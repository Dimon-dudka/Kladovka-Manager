#include "widgetmanager.h"

WidgetManager::WidgetManager(QStackedWidget * parrent):QStackedWidget(parrent)
{

    setWindowTitle("Kladovka Manager v 0.1");

    setMinimumSize(200,150);

    mainMenuWidget = new MainMenu;

    addWidget(mainMenuWidget);

    setCurrentWidget(mainMenuWidget);



}

void WidgetManager::setCurrentMainMenuWidget(){
    setCurrentWidget(mainMenuWidget);
}
/*
void WidgetManager::setCurrentNewKladovkaWidget(){

}

void WidgetManager::setCurrentOpenKladovkaWidget(){

}
*/
