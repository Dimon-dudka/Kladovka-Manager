#include "sqlengine.h"

SQLEngine::SQLEngine(QObject *parrent): QObject(parrent)
{
    alldb = QSqlDatabase::addDatabase("QSQLITE");
}

void SQLEngine::buildConnectionAndDB(){

    QString str;

    //  Making connection and DB if not exists for DB with whole information

    alldb.setDatabaseName("C:/Users/D/Documents/Kladovka/KladovkaProject/allInfoKladovki.sqlite");
    //{
    if(!alldb.open()){
        emit errorConnectionSignal("Data Base Error!");
        return;
    }
    else{
        qDebug()<<"Succes";
    }
    str = "CREATE TABLE IF NOT EXISTS allInfoKladovki("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "adress TEXT, "
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
    //alldb.close();
    //}
    //alldb=QSqlDatabase();
    //QSqlDatabase::removeDatabase("allInfoKladovki");

    //Making connection for DB with adresses
    //{
    //alldb = QSqlDatabase::addDatabase("QSQLITE");
    //alldb=QSqlDatabase::database("QSQLITE");
    alldb.setDatabaseName("C:/Users/D/Documents/Kladovka/KladovkaProject/adressKladovki.sqlite");

    if(!alldb.open()){
        emit errorConnectionSignal("Data Base Error!");
        return;
    }
    else{
        qDebug()<<"Succes";
    }

    str = "CREATE TABLE IF NOT EXISTS adressKladovki("
          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
          "adress TEXT "
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
   // }

}

//void SQLEngine::insertAdressQuery(QString queryText){

//}
