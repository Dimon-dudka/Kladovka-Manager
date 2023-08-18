#include "widgetmanager.h"

WidgetManager::WidgetManager(QStackedWidget * parrent):QStackedWidget(parrent)
{
    test= new SQLEngine;

    setWindowTitle("Kladovka Manager v 0.1");

    setMinimumSize(200,150);

    mainMenuWidget = new MainMenu(test);
    newKladovkaMenuWidget = new NewKladovkaMenu(test);
    openKladovkaWidget = new OpenKladovkaMenu(test);

    addWidget(mainMenuWidget);
    addWidget(newKladovkaMenuWidget);
    addWidget(openKladovkaWidget);

    connect(mainMenuWidget,SIGNAL(newKladovkaSignal()),this,SLOT(setCurrentNewKladovkaWidget()));
    connect(newKladovkaMenuWidget,SIGNAL(backToMainMenuSignal()),this,SLOT(setCurrentMainMenuWidget()));
    connect(mainMenuWidget,SIGNAL(openExistsKladovkaSignal()),this,SLOT(setCurrentOpenKladovkaWidget()));

    connect(openKladovkaWidget,SIGNAL(backToMainMenuSignal()),this,SLOT(setCurrentMainMenuWidget()));

    connect(mainMenuWidget,SIGNAL(openExistsKladovkaSignal())
            ,openKladovkaWidget,SLOT(updateOfAddressesList()));

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



