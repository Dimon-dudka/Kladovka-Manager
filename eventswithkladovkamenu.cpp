
#include "eventswithkladovkamenu.h"

EventsWithKladovkaMenu::EventsWithKladovkaMenu(QWidget *parrent):QWidget(parrent)
{
    addressText="";

    addressKladovkiLabel = new QLabel;
    addressKladovkiLabel->setAlignment(Qt::AlignCenter);
    addressKladovkiLabel->setText(addressText);

    insertButton = new QPushButton("Insert/Delete Item");
    deleteButton = new QPushButton("Delete Item");
    printAllButton = new QPushButton("Print all stuff in the Kladovka");
    //to another buttons
    backButton = new QPushButton("Back");

    eventsMenuLayout=new QVBoxLayout;
    eventsMenuLayout->addWidget(addressKladovkiLabel);
    eventsMenuLayout->addWidget(insertButton);
    //eventsMenuLayout->addWidget(deleteButton);
    eventsMenuLayout->addWidget(printAllButton);
    eventsMenuLayout->addWidget(backButton);

    connect(backButton,SIGNAL(clicked()),this,SLOT(sendingBackSignal()));
    connect(insertButton,SIGNAL(clicked()),this,SLOT(insertDeleteWidgetOpen()));

    setLayout(eventsMenuLayout);

}

void EventsWithKladovkaMenu::becomeAddressTextSlot(QString address){
    //qDebug()<<address;
    addressText=address;
    addressKladovkiLabel->setText(addressText);
}

void EventsWithKladovkaMenu::sendingBackSignal(){
    emit backSignal();
}

void EventsWithKladovkaMenu::insertDeleteWidgetOpen(){
    emit insertDeleteWidgetOpenSignal();
}
