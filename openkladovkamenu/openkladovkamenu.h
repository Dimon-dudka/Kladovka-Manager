//  Describing openKladovkaMenu Widget
//  This widget contatins in the tree view all storages(addresses of them)

#pragma once

//  Basic headers files
#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QString>
#include <QPointer>
#include <QMessageBox>

//  Projects own SQLite engine
#include "sqlengine.h"

//  Logger
#include "logger.h"

class OpenKladovkaMenu : public QWidget
{
    Q_OBJECT

private:

    QPointer<Logger>logging;

    QPointer<SQLEngine>connectionDB;
    QPointer<QLabel>someInfoLabel;
    QPointer<QVBoxLayout>menuLayout;
    QPointer<QHBoxLayout>buttonsLayout;
    QPointer<QPushButton>backMainMenuButton,acceptChoiseAndNextButton,deleteKladovkaButton;
    QPointer<QTreeWidget>treeView;
    QTreeWidgetItem *treeItem;
    QString addressTxt;


public:
    OpenKladovkaMenu(Logger *logParrent,SQLEngine *connectParameter,QWidget* parrent=0);

public slots:

    void updateOfAddressesList();

private slots:

    void sendingbackToMainMenuSlot();
    void userAddressChoiseSlot(QTreeWidgetItem* test,int number);
    void deletingButtonSlot();
    void proofAddressAndSendSlot();

signals:
    void backToMainMenuSignal();
    void sendTheAddressSignal(QString address);
    void nextMenuSignal();

};
