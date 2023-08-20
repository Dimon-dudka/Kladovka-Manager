#pragma once

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QString>
#include <QLabel>
#include <QMessageBox>
#include <QTreeWidget>

#include "sqlengine.h"

class AllThingsMenu : public QWidget
{

    Q_OBJECT

private:

    SQLEngine *connectionDB;

    QPushButton *backButton,*deleteButton;

    QTreeWidget *treeView;
    QTreeWidgetItem *treeItem;

    QVBoxLayout *AllThingsLayout;
    QHBoxLayout *buttonsLayout;

    QLabel *userInfoLabel;

    QString addressString,reckString,shelfString,thingString,idString;
    //int idNumber;


public:

    AllThingsMenu(SQLEngine *connection,QWidget *parrent = 0);

public slots:

    void becomeAddressSlot(QString text);
    void updateStuffTree();

private slots:

    void sendingBackSlot();

    void sendingDeleteQuerySlot();

    void userChoiseSlot(QTreeWidgetItem* test,int number);

signals:
    void backSignal();
    void deleteSignal(QString id="-1");
};
