#include "widgetmanager.h"

WidgetManager::WidgetManager(QStackedWidget * parrent):QStackedWidget(parrent)
{
    test= new SQLEngine;

    setWindowTitle("Kladovka Manager v 0.1");

    setMinimumSize(200,150);

    mainMenuWidget = new MainMenu(test);
    newKladovkaMenuWidget = new NewKladovkaMenu(test);
    openKladovkaWidget = new OpenKladovkaMenu(test);
    eventKladovkaWidget = new EventsWithKladovkaMenu;
    insertDeleteMenuWidget = new InsertDeleteMenu(test);

    addWidget(mainMenuWidget);
    addWidget(newKladovkaMenuWidget);
    addWidget(openKladovkaWidget);
    addWidget(eventKladovkaWidget);
    addWidget(insertDeleteMenuWidget);

    connect(mainMenuWidget,SIGNAL(newKladovkaSignal()),this,SLOT(setCurrentNewKladovkaWidget()));
    connect(newKladovkaMenuWidget,SIGNAL(backToMainMenuSignal()),this,SLOT(setCurrentMainMenuWidget()));
    connect(mainMenuWidget,SIGNAL(openExistsKladovkaSignal()),this,SLOT(setCurrentOpenKladovkaWidget()));

    connect(openKladovkaWidget,SIGNAL(backToMainMenuSignal()),this,SLOT(setCurrentMainMenuWidget()));
    connect(openKladovkaWidget,SIGNAL(sendTheAddressSignal(QString))
            ,eventKladovkaWidget,SLOT(becomeAddressTextSlot(QString)));
    connect(openKladovkaWidget,SIGNAL(nextMenuSignal())
            ,this,SLOT(setCurrentEventKladovkaMenuWidget()));

    connect(eventKladovkaWidget,SIGNAL(backSignal()),this,SLOT(setCurrentOpenKladovkaWidget()));
    connect(eventKladovkaWidget,SIGNAL(insertDeleteWidgetOpenSignal())
            ,this,SLOT(setCurrentInsertDeleteMenuWidget()));

    connect(mainMenuWidget,SIGNAL(openExistsKladovkaSignal())
            ,openKladovkaWidget,SLOT(updateOfAddressesList()));


    connect(openKladovkaWidget,SIGNAL(sendTheAddressSignal(QString))
            ,insertDeleteMenuWidget,SLOT(becomeAddressSlot(QString)));

    connect(insertDeleteMenuWidget,SIGNAL(backSignal()),this,SLOT(setCurrentEventKladovkaMenuWidget()));

    setCurrentWidget(mainMenuWidget);

    resize(250,200);

}

void WidgetManager::setCurrentMainMenuWidget(){
    setCurrentWidget(mainMenuWidget);
}

void WidgetManager::setCurrentNewKladovkaWidget(){
    setCurrentWidget(newKladovkaMenuWidget);
}

void WidgetManager::setCurrentOpenKladovkaWidget(){
    setCurrentWidget(openKladovkaWidget);
}

void WidgetManager::setCurrentEventKladovkaMenuWidget(){
    setCurrentWidget(eventKladovkaWidget);
}

void WidgetManager::setCurrentInsertDeleteMenuWidget(){
    setCurrentWidget(insertDeleteMenuWidget);
}
