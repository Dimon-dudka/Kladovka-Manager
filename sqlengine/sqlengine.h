//  SQL Engine has interface to answer on widget requests

#pragma once

//  Basic headers files
#include <QtSql>
#include <QObject>
#include <QString>
#include <QCoreApplication>
#include <QPointer>

//  Logger
#include "logger.h"

class SQLEngine : public QObject
{
    Q_OBJECT

private:

    //Basic DB connection
    QSqlDatabase alldb;

    QPointer<Logger>logging;

    QString directory;

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
    void insertAddressQuery(const QString queryText);
    void deleteTheKladovka(const QString queryText);
    void insertIntoAllSlot(const QString address,const QString reck,const QString shelf,const QString thing);
    void deleteThingAllSlot(const QString address,const QString reck,const QString shelf,const QString thing);
    void deleteThingAllByIDSlot(const QString id);
    void updateThingPositionSlot(const QString id,const QString reck,const QString shelf);

signals:

    void errorConnectionSignal(QString text);

    //  Signals for <add new Kladovka> widget
    void addressAlreadyExistsSignal(QString text);
    void addressAddedSignal(QString text);

    //Signals for <insert into all>
    void insertInfoSignal(QString text);

    void updataingTreeSignal();

};
