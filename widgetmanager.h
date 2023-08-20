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
#include "openkladovkamenu.h"
#include "eventswithkladovkamenu.h"
#include "insertdeletemenu.h"
#include "allthingsmenu.h"

//  SQLite Engine
#include "sqlengine.h"

class WidgetManager : public QStackedWidget
{
    Q_OBJECT

private:
    SQLEngine *test;


    MainMenu *mainMenuWidget;
    NewKladovkaMenu *newKladovkaMenuWidget;
    OpenKladovkaMenu *openKladovkaWidget;
    EventsWithKladovkaMenu *eventKladovkaWidget;
    InsertDeleteMenu *insertDeleteMenuWidget;
    AllThingsMenu *allThinksMenuWidget;

public:

    WidgetManager(QStackedWidget * parrent = 0);


public slots:



private slots:

    void setCurrentMainMenuWidget();
    void setCurrentNewKladovkaWidget();
    void setCurrentOpenKladovkaWidget();
    void setCurrentEventKladovkaMenuWidget();
    void setCurrentInsertDeleteMenuWidget();
    void setCurrentAllThingsMenuWidget();

signals:


};
