//  SQL Engine has interface to answer on widget requests

#pragma once

#include <QtSql>
#include <QObject>
#include <QString>

class SQLEngine : public QObject
{
    Q_OBJECT

private:

    QSqlDatabase alldb;

public:

    QSqlQuery *query;

    SQLEngine(QObject *parrent=0);

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
