
#include "eventswithkladovkamenu.h"

EventsWithKladovkaMenu::EventsWithKladovkaMenu(QWidget *parrent):QWidget(parrent)
{

    addressKladovkiLabel = new QLabel;
    addressKladovkiLabel->setAlignment(Qt::AlignCenter);
    addressKladovkiLabel->setText("");

    QFont font=addressKladovkiLabel->font();
    font.setPointSize(10);
    font.setBold(true);
    addressKladovkiLabel->setFont(font);

    insertButton = new QPushButton("Insert/Delete Item");
    printAllButton = new QPushButton("Print all stuff in the Kladovka");
    backButton = new QPushButton("Back");

    eventsMenuLayout=new QVBoxLayout;
    eventsMenuLayout->addWidget(addressKladovkiLabel);
    eventsMenuLayout->addWidget(insertButton);
    eventsMenuLayout->addWidget(printAllButton);
    eventsMenuLayout->addWidget(backButton);

    //Buttons connections
    connect(backButton,SIGNAL(clicked()),this,SLOT(sendingBackSignalSlot()));
    connect(insertButton,SIGNAL(clicked()),this,SLOT(insertDeleteWidgetOpenSlot()));
    connect(printAllButton,SIGNAL(clicked()),this,SLOT(sendingPrintAllSlot()));

    setLayout(eventsMenuLayout);
}

void EventsWithKladovkaMenu::becomeAddressTextSlot(const QString address){
    addressKladovkiLabel->setText(std::move(address));
}

void EventsWithKladovkaMenu::sendingBackSignalSlot(){
    emit backSignal();
}

void EventsWithKladovkaMenu::insertDeleteWidgetOpenSlot(){
    emit insertDeleteWidgetOpenSignal();
}

void EventsWithKladovkaMenu::sendingPrintAllSlot(){
    emit printAllSignal();
}
