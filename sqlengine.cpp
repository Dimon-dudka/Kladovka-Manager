#include "sqlengine.h"

SQLEngine::SQLEngine(QObject *parrent): QObject(parrent)
{

}

void SQLEngine::buildConnectionAndDB(){

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/D/Documents/Kladovka/KladovkaProject/Kladovki.sqlite");
    db.setUserName("user");
    db.setHostName("host");
    if(!db.open()){
        emit errorConnectionSignal("Data Base Error!");
        return;
    }
    else{
        qDebug()<<"Succes";
    }
    QString str = "CREATE TABLE IF NOT EXISTS Kladovki("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "adress TEXT, "
                  "reck INTEGER, "
                  "shelf INTEGER, "
                  "think TEXT "
                  ");";
    QSqlQuery query;
    if(!query.exec(str)){
        emit errorConnectionSignal("Data Base Error!");
        return;
    }
    else{
        qDebug()<<"Succes";
    }
}
