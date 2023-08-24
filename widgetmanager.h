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
#include "settingsmenu.h"

//  SQLite Engine
#include "sqlengine.h"


//  Logger
#include "logger.h"

class WidgetManager : public QStackedWidget
{
    Q_OBJECT

private:

    Logger *logging;
    SQLEngine *test;
    MainMenu *mainMenuWidget;
    NewKladovkaMenu *newKladovkaMenuWidget;
    OpenKladovkaMenu *openKladovkaWidget;
    EventsWithKladovkaMenu *eventKladovkaWidget;
    InsertDeleteMenu *insertDeleteMenuWidget;
    AllThingsMenu *allThingsMenuWidget;
    SettingsMenu *settingsMenu;

public:

    WidgetManager(QStackedWidget * parrent = 0);

private slots:

    //Slots that change the current Widget to another
    void setCurrentMainMenuWidget();
    void setCurrentNewKladovkaWidget();
    void setCurrentOpenKladovkaWidget();
    void setCurrentEventKladovkaMenuWidget();
    void setCurrentInsertDeleteMenuWidget();
    void setCurrentAllThingsMenuWidget();
    void setCurrentSettingsmenuWidget();

};
