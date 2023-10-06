#include "widgetmanager.h"

WidgetManager::WidgetManager(QStackedWidget * parrent):QStackedWidget(parrent)
{
    logging = new Logger;
    test= new SQLEngine(logging);

    setWindowTitle("Kladovka Manager");

    QPixmap pix(":images/logo.png");
    setWindowIcon(QIcon(pix));


    setMinimumSize(300,150);

    mainMenuWidget = new MainMenu(test);
    newKladovkaMenuWidget = new NewKladovkaMenu(test);
    openKladovkaWidget = new OpenKladovkaMenu(logging,test);
    eventKladovkaWidget = new EventsWithKladovkaMenu;
    insertDeleteMenuWidget = new InsertDeleteMenu(test);
    allThingsMenuWidget = new AllThingsMenu(logging,test);
    settingsMenu = new SettingsMenu(logging);

    addWidget(mainMenuWidget);
    addWidget(newKladovkaMenuWidget);
    addWidget(openKladovkaWidget);
    addWidget(eventKladovkaWidget);
    addWidget(insertDeleteMenuWidget);
    addWidget(allThingsMenuWidget);
    addWidget(settingsMenu);

    //Main Menu connections
    connect(mainMenuWidget,SIGNAL(newKladovkaSignal()),this,SLOT(setCurrentNewKladovkaWidget()));
    connect(mainMenuWidget,SIGNAL(openExistsKladovkaSignal()),this,SLOT(setCurrentOpenKladovkaWidget()));
    connect(mainMenuWidget,SIGNAL(openExistsKladovkaSignal())
            ,openKladovkaWidget,SLOT(updateOfAddressesList()));
    connect(mainMenuWidget,SIGNAL(openSettingsMenuSignal()),this,SLOT(setCurrentSettingsmenuWidget()));

    //New Kladovka connections
    connect(newKladovkaMenuWidget,SIGNAL(backToMainMenuSignal()),this,SLOT(setCurrentMainMenuWidget()));
    connect(newKladovkaMenuWidget,SIGNAL(goingToNewKladovkaSignal()),this,SLOT(setCurrentEventKladovkaMenuWidget()));
    connect(newKladovkaMenuWidget,SIGNAL(changeAddressSignal(QString))
            ,eventKladovkaWidget,SLOT(becomeAddressTextSlot(QString)));
    connect(newKladovkaMenuWidget,SIGNAL(changeAddressSignal(QString))
            ,insertDeleteMenuWidget,SLOT(becomeAddressSlot(QString)));
    connect(newKladovkaMenuWidget,SIGNAL(changeAddressSignal(QString))
            ,allThingsMenuWidget,SLOT(becomeAddressSlot(QString)));
    connect(newKladovkaMenuWidget,SIGNAL(changeAddressSignal(QString))
            ,openKladovkaWidget,SLOT(updateOfAddressesList()));

    //Open Kladovka connections
    connect(openKladovkaWidget,SIGNAL(backToMainMenuSignal()),this,SLOT(setCurrentMainMenuWidget()));
    connect(openKladovkaWidget,SIGNAL(sendTheAddressSignal(QString))
            ,eventKladovkaWidget,SLOT(becomeAddressTextSlot(QString)));
    connect(openKladovkaWidget,SIGNAL(nextMenuSignal())
            ,this,SLOT(setCurrentEventKladovkaMenuWidget()));
    connect(openKladovkaWidget,SIGNAL(sendTheAddressSignal(QString))
            ,insertDeleteMenuWidget,SLOT(becomeAddressSlot(QString)));
    connect(openKladovkaWidget,SIGNAL(sendTheAddressSignal(QString))
            ,allThingsMenuWidget,SLOT(becomeAddressSlot(QString)));

    //Event Kladovka connections
    connect(eventKladovkaWidget,SIGNAL(backSignal()),this,SLOT(setCurrentOpenKladovkaWidget()));
    connect(eventKladovkaWidget,SIGNAL(insertDeleteWidgetOpenSignal())
            ,this,SLOT(setCurrentInsertDeleteMenuWidget()));
    connect(eventKladovkaWidget,SIGNAL(printAllSignal()),this,SLOT(setCurrentAllThingsMenuWidget()));
    connect(eventKladovkaWidget,SIGNAL(printAllSignal()),allThingsMenuWidget,SLOT(updateStuffTree()));

    //Insert Delete Menu connections
    connect(insertDeleteMenuWidget,SIGNAL(backSignal()),this,SLOT(setCurrentEventKladovkaMenuWidget()));

    //Print all things connections
    connect(allThingsMenuWidget,SIGNAL(backSignal()),this,SLOT(setCurrentEventKladovkaMenuWidget()));

    //Settings Menu connections
    connect(settingsMenu,SIGNAL(backToMainMenuSignal()),this,SLOT(setCurrentMainMenuWidget()));

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

void WidgetManager::setCurrentAllThingsMenuWidget(){
    setCurrentWidget(allThingsMenuWidget);
}

void WidgetManager::setCurrentSettingsmenuWidget(){
    setCurrentWidget(settingsMenu);
}
