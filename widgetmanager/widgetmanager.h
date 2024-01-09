//  Widget Manager
//  Compound of Widgets
//  And relations between them

#pragma once

//  QT  Libraryes
#include <QApplication>
#include <QWidget>
#include <QStackedWidget>
#include <QPointer>

//  Derived from QWidget widgets
#include "mainmenu.h"
#include "newkladovkamenu.h"
#include "openkladovkamenu.h"
#include "eventswithkladovkamenu.h"
#include "insertdeletemenu.h"
#include "allthingsmenu.h"
#include "settingsmenu.h"
#include "changeitempositionmenu.h"

//  SQLite Engine
#include "sqlengine.h"


//  Logger
#include "logger.h"

class WidgetManager : public QStackedWidget
{
    Q_OBJECT

private:

    QPointer<Logger>logging;
    QPointer<SQLEngine>test;
    QPointer<MainMenu>mainMenuWidget;
    QPointer<NewKladovkaMenu>newKladovkaMenuWidget;
    QPointer<OpenKladovkaMenu>openKladovkaWidget;
    QPointer<EventsWithKladovkaMenu>eventKladovkaWidget;
    QPointer<InsertDeleteMenu>insertDeleteMenuWidget;
    QPointer<AllThingsMenu>allThingsMenuWidget;
    QPointer<SettingsMenu>settingsMenu;
    QPointer<ChangeItemPositionMenu>changePositionMenuWidget;

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
    void setCurrentChangePositionWidget();
};
