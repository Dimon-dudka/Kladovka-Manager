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
    QSqlDatabase db;

    SQLEngine(QObject *parrent=0);
    void buildConnectionAndDB();



signals:

    void errorConnectionSignal(QString text);

};
