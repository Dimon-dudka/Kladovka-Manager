// Menu that displays everything in the storage (Kladovka)

#pragma once

//  Basic headers files
#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QString>
#include <QLabel>
#include <QMessageBox>
#include <QTreeWidget>

//  Projects SQLite engine
#include "sqlengine.h"

//  Logger
#include "logger.h"

class AllThingsMenu : public QWidget
{

    Q_OBJECT

private:

    Logger *logging;

    SQLEngine *connectionDB;
    QPushButton *backButton,*deleteButton,*changeButton;
    QTreeWidget *treeView;
    QTreeWidgetItem *treeItem;
    QVBoxLayout *AllThingsLayout;
    QHBoxLayout *buttonsLayout;
    QLabel *userInfoLabel;
    QString addressString,reckString,shelfString,thingString,idString;

public:

    AllThingsMenu(Logger *logParrent,SQLEngine *connection,QWidget *parrent = 0);

public slots:

    void becomeAddressSlot(QString text);

    //updating tree Widget after some action
    void updateStuffTree();

private slots:

    void sendingBackSlot();
    void sendingDeleteQuerySlot();
    void userChoiseSlot(QTreeWidgetItem* test);
    void changeSlot();

signals:

    void backSignal();
    void deleteSignal(QString id="-1");
    void changeSignal(QString idString,QString item,QString reck,QString shelf);
};
