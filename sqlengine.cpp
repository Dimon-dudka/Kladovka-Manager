#include "sqlengine.h"

SQLEngine::SQLEngine(Logger *logParrent,QObject *parrent): QObject(parrent),logging(logParrent)
{
    alldb = QSqlDatabase::addDatabase("QSQLITE");
    query = new QSqlQuery;
}

void SQLEngine::buildConnectionAndDB(){

    QString str;

    //  Making connection and DB if not exists for DB with whole information
    changeConnectionToALLINFO();

    if(!alldb.open()){
        emit errorConnectionSignal("Data Base Error!");
        return;
    }

    str = "CREATE TABLE IF NOT EXISTS allInfoKladovki("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "address TEXT, "
                  "reck INTEGER, "
                  "shelf INTEGER, "
                  "thing TEXT "
                  ");";

    if(!query->exec(str)){
        emit errorConnectionSignal("Data Base Query Error!");
        logging->messageHandler(Logger::CRITICAL,"SQLEngine","Data Base query to \"allInfoKladovki\" "
                                                              "not open");
        return;
    }

    query->clear();

    //Making connection for DB with adresses
    changeConnectionToADDRESSES();

    if(!alldb.open()){
        emit errorConnectionSignal("Data Base Error!");
        return;
    }

    str = "CREATE TABLE IF NOT EXISTS addressKladovki("
          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
          "address TEXT UNIQUE"
          ");";

    if(!query->exec(str)){
        emit errorConnectionSignal("Data Base Query Error!");
        logging->messageHandler(Logger::CRITICAL,"SQLEngine","Data Base query to \"allInfoKladovki\" "
                                                              "not open");
        return;
    }

    query->clear();
}

void SQLEngine::insertAddressQuery(QString queryText){

    changeConnectionToADDRESSES();

    if(!alldb.open()){
        emit errorConnectionSignal("Data Base Error!");
        return;
    }

    QString str = "INSERT INTO addressKladovki( address ) VALUES ( '"+queryText+"' );";

    if(!query->exec(str)){
        logging->messageHandler(Logger::WARNING,"SQLEngine","Request to"
                                                              " \"addressKladovki\" failed");

        emit addressAlreadyExistsSignal("Address Already Exists");
        //qDebug()<<"Somethink wrong with the query in <insertAddressQuery>!";
    }
    else{
        emit addressAddedSignal("Address added");
    }

    query->clear();

}

void SQLEngine::changeConnectionToALLINFO(){
    alldb.setDatabaseName("C:/Users/D/Documents/Kladovka/KladovkaProject/allInfoKladovki.sqlite");
    if(!alldb.open()){
        logging->messageHandler(Logger::CRITICAL,"SQLEngine","Data Base connection to"
                                                              " \"allInfoKladovki\" failed");
    }
    query->clear();

}

void SQLEngine::changeConnectionToADDRESSES(){
    alldb.setDatabaseName("C:/Users/D/Documents/Kladovka/KladovkaProject/addressKladovki.sqlite");
    if(!alldb.open()){

        logging->messageHandler(Logger::CRITICAL,"SQLEngine","Data Base connection to"
                                                              " \"addressKladovki\" failed");
    }
    query->clear();
}

void SQLEngine::deleteTheKladovka(QString queryText){

    changeConnectionToADDRESSES();

    QString str = "DELETE FROM addressKladovki WHERE address = '"+queryText+"';";
    if(!query->exec(str)){

        logging->messageHandler(Logger::WARNING,"SQLEngine","Delete request from"
                                                              " \"addressKladovki\" failed");
    }

    query->clear();

    changeConnectionToALLINFO();

    str = "DELETE FROM allInfoKladovki WHERE address = '"+queryText+"';";
    if(!query->exec(str)){

        logging->messageHandler(Logger::WARNING,"SQLEngine","Delete request from"
                                                             " \"allInfoKladovki\" by address failed");
    }

    query->clear();
}

void SQLEngine::insertIntoAllSlot(QString address,QString reck,QString shelf,QString thing){

    changeConnectionToALLINFO();

    QString queryTxt = "INSERT INTO allInfoKladovki (address,reck,shelf,thing) "
                       "VALUES ( '"+address+"' , '"+reck+"' , '"+shelf+"' , '"+thing+"' );";
    if(!query->exec(queryTxt)){

        logging->messageHandler(Logger::WARNING,"SQLEngine","Insert request to"
                                                             " \"allInfoKladovki\" failed");

        emit insertInfoSignal("Insert error!");
    }else{
        emit insertInfoSignal("All done");
    }
    query->clear();

}

void SQLEngine::deleteThingAllSlot( QString address,QString reck,QString shelf,QString thing){

    changeConnectionToALLINFO();

    QString queryTxt = "DELETE FROM allInfoKladovki WHERE "
        " address = '"+address+"' AND reck = '"+reck+"' AND shelf = '"+shelf+"' AND thing = '"+thing+"';";
    if(!query->exec(queryTxt)){

        logging->messageHandler(Logger::WARNING,"SQLEngine","Delete request from"
                                 " \"allInfoKladovki\" by address,reck,shelf,thing address failed");

        emit insertInfoSignal("Deleting error!");
    }else{
        emit insertInfoSignal("Deleting done");
    }


    query->clear();
}

void SQLEngine::deleteThingAllByIDSlot(QString id){
    if(id=="-1")return;

    changeConnectionToALLINFO();

    QString queryTxt = "DELETE FROM allInfoKladovki WHERE "
                       " id = "+id+" ;";
    if(!query->exec(queryTxt)){

        logging->messageHandler(Logger::WARNING,"SQLEngine","Delete request from"
                                                             " \"allInfoKladovki\" by id failed");
    }else{

        emit updataingTreeSignal();
    }
}
