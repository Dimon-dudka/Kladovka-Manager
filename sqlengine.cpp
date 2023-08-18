#include "sqlengine.h"

SQLEngine::SQLEngine(QObject *parrent): QObject(parrent)
{
    alldb = QSqlDatabase::addDatabase("QSQLITE");
}

void SQLEngine::buildConnectionAndDB(){

    QString str;

    //  Making connection and DB if not exists for DB with whole information

    alldb.setDatabaseName("C:/Users/D/Documents/Kladovka/KladovkaProject/allInfoKladovki.sqlite");

    if(!alldb.open()){
        emit errorConnectionSignal("Data Base Error!");
        return;
    }
    else{
        qDebug()<<"Succes";
    }
    str = "CREATE TABLE IF NOT EXISTS allInfoKladovki("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "address TEXT, "
                  "reck INTEGER, "
                  "shelf INTEGER, "
                  "think TEXT "
                  ");";
    QSqlQuery query;
    if(!query.exec(str)){
        emit errorConnectionSignal("Data Base Query Error 1!");
        return;
    }
    else{
        qDebug()<<"Succes";
    }
    query.clear();

    //Making connection for DB with adresses

    alldb.setDatabaseName("C:/Users/D/Documents/Kladovka/KladovkaProject/addressKladovki.sqlite");

    if(!alldb.open()){
        emit errorConnectionSignal("Data Base Error!");
        return;
    }
    else{
        qDebug()<<"Succes";
    }

    str = "CREATE TABLE IF NOT EXISTS addressKladovki("
          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
          "address TEXT UNIQUE"
          ");";

    QSqlQuery querySecond;
    if(!querySecond.exec(str)){
        emit errorConnectionSignal("Data Base Query Error 2!");
        return;
    }
    else{
        qDebug()<<"Succes";
    }

    querySecond.clear();
    alldb.close();

}

void SQLEngine::insertAddressQuery(QString queryText){

    alldb.setDatabaseName("C:/Users/D/Documents/Kladovka/KladovkaProject/addressKladovki.sqlite");

    if(!alldb.open()){
        qDebug()<<"Fail insertAdressQuery!";
        emit errorConnectionSignal("Data Base Error!");
        return;
    }
    else{
        qDebug()<<"Succes open insertAdressQuery";
    }

    QString str = "INSERT INTO addressKladovki( address ) VALUES ( '"+queryText+"' );";

    QSqlQuery query;
    if(!query.exec(str)){
        emit addressAlreadyExistsSignal("Address Already Exists");
        qDebug()<<"Somethink wrong with the query in <insertAddressQuery>!";
        //return;
    }
    else{
        emit addressAddedSignal("Address added");
        qDebug()<<"Succes";
    }

    query.clear();
    alldb.close();

}
