#pragma once

#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QString>
#include <QMessageBox>
//  Describing openKladovkaMenu Widget

#include "sqlengine.h"

class OpenKladovkaMenu : public QWidget
{
    Q_OBJECT

private:

    SQLEngine *connectionDB;

    QLabel *someInfoLabel;
    QVBoxLayout *menuLayout;
    QHBoxLayout *buttonsLayout;
    QPushButton *backMainMenuButton,*acceptChoiseAndNextButton,*deleteKladovkaButton;

    QTreeWidget *treeView;
    QTreeWidgetItem *treeItem;

    QString addressTxt;


public:
    OpenKladovkaMenu(SQLEngine *connectParameter,QWidget* parrent=0);

public slots:

    //void updateOfTreeWidget();
    void updateOfAddressesList();

private slots:

    void sendingbackToMainMenuSlot();

    void userAddressChoiseSlot(QTreeWidgetItem* test,int number);

    void deletingButtonSlot();

signals:
    void backToMainMenuSignal();

};
