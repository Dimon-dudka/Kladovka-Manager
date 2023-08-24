//  SQL Engine has interface to answer on widget requests

#pragma once

//  Basic headers files
#include <QtSql>
#include <QObject>
#include <QString>

//  Logger
#include "logger.h"

class SQLEngine : public QObject
{
    Q_OBJECT

private:

    //Basic DB connection
    QSqlDatabase alldb;

    Logger *logging;

public:

    //Query is public, becouse it is needble to become data from some
    //requests direct to read it in another function
    QSqlQuery *query;

    SQLEngine(Logger *logParrent,QObject *parrent=0);

    void buildConnectionAndDB();

    //  Functions to change the sql connection between two DB
    void changeConnectionToALLINFO();
    void changeConnectionToADDRESSES();

public slots:
    void insertAddressQuery(QString queryText);
    void deleteTheKladovka(QString queryText);
    void insertIntoAllSlot(QString address,QString reck,QString shelf,QString thing);
    void deleteThingAllSlot(QString address,QString reck,QString shelf,QString thing);
    void deleteThingAllByIDSlot(QString id);

signals:

    void errorConnectionSignal(QString text);

    //  Signals for <add new Kladovka> widget
    void addressAlreadyExistsSignal(QString text);
    void addressAddedSignal(QString text);

    //Signals for <insert into all>
    void insertInfoSignal(QString text);

    void updataingTreeSignal();

};
