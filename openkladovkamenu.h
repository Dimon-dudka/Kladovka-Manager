#pragma once

#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QString>
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
    QPushButton *backMainMenuButton,*acceptChoiseAndNextButton;

    QTreeWidget *treeView;
    QTreeWidgetItem *treeItem;

public:
    OpenKladovkaMenu(SQLEngine *connectParameter,QWidget* parrent=0);

private slots:

    void sendingbackToMainMenuSlot();

signals:
    void backToMainMenuSignal();

};
