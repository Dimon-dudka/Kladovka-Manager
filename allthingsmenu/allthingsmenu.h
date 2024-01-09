// Menu that displays everything in the storage (Kladovka)

#pragma once

//  Basic headers files
#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QString>
#include <QLabel>
#include <QPointer>
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

    QPointer<Logger>logging;

    QPointer<SQLEngine>connectionDB;
    QPointer<QPushButton>backButton,deleteButton,changeButton;
    QPointer<QTreeWidget>treeView;
    QTreeWidgetItem *treeItem;
    QPointer<QVBoxLayout>AllThingsLayout;
    QPointer<QHBoxLayout>buttonsLayout;
    QPointer<QLabel>userInfoLabel;
    QString addressString,reckString,shelfString,thingString,idString;

public:

    AllThingsMenu(Logger *logParrent,SQLEngine *connection,QWidget *parrent = 0);

public slots:

    void becomeAddressSlot(const QString text);

    //updating tree Widget after some action
    void updateStuffTree();

private slots:

    void sendingBackSlot();
    void sendingDeleteQuerySlot();
    void userChoiseSlot(QTreeWidgetItem* test);
    void changeSlot();

signals:

    void backSignal();
    void deleteSignal(QString id);
    void changeSignal(QString idString,QString item,QString reck,QString shelf);
};
