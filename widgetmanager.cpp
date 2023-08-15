#include "widgetmanager.h"

WidgetManager::WidgetManager(QStackedWidget * parrent):QStackedWidget(parrent)
{

    setWindowTitle("Kladovka Manager v 0.1");

    setMinimumSize(200,150);

    mainMenuWidget = new MainMenu;
    newKladovkaMenuWidget = new NewKladovkaMenu;

    addWidget(mainMenuWidget);
    addWidget(newKladovkaMenuWidget);

    connect(mainMenuWidget,SIGNAL(newKladovkaSignal()),this,SLOT(setCurrentNewKladovkaWidget()));
    connect(newKladovkaMenuWidget,SIGNAL(backToMainMenuSignal()),this,SLOT(setCurrentMainMenuWidget()));

    setCurrentWidget(mainMenuWidget);



}

void WidgetManager::setCurrentMainMenuWidget(){
    setCurrentWidget(mainMenuWidget);
}

void WidgetManager::setCurrentNewKladovkaWidget(){
    setCurrentWidget(newKladovkaMenuWidget);
}
/*
void WidgetManager::setCurrentOpenKladovkaWidget(){

}
*/
