//  SQL Engine has interface to answer on widget requests

#pragma once

#include <QtSql>
#include <QObject>
#include <QString>

class SQLEngine : public QObject
{
    Q_OBJECT

private:

    void createConnection();

public:
    //allDB connection is for the DB with all information
    QSqlDatabase alldb;
    //adressDB is only for storages adresses
    //QSqlDatabase adressesDB;

    SQLEngine(QObject *parrent=0);
    void buildConnectionAndDB();



signals:

    void errorConnectionSignal(QString text);

};
