//  Widget Manager
//  Compound of Widgets
//  And relations between them

#pragma once

//  QT  Libraryes
#include <QApplication>
#include <QWidget>
#include <QStackedWidget>

//  Derived from QWidget widgets
#include "mainmenu.h"
#include "newkladovkamenu.h"

#include "sqlengine.h"

class WidgetManager : public QStackedWidget
{
    Q_OBJECT

private:
    SQLEngine *test;


    MainMenu *mainMenuWidget;
    NewKladovkaMenu *newKladovkaMenuWidget;


public:

    WidgetManager(QStackedWidget * parrent = 0);


public slots:

private slots:

    void setCurrentMainMenuWidget();
    void setCurrentNewKladovkaWidget();
    //void setCurrentOpenKladovkaWidget();

signals:


};
