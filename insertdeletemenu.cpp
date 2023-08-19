
#include "insertdeletemenu.h"

InsertDeleteMenu::InsertDeleteMenu(SQLEngine *engine,QWidget *parrent)
    :QWidget(parrent),dataBaseconnection(engine)
{
    dataBaseconnection->changeConnectionToALLINFO();

    reckLabel = new QLabel("Reck");
    reckLabel->setAlignment(Qt::AlignCenter);

    shelfLabel = new QLabel("Shelf");
    shelfLabel->setAlignment(Qt::AlignCenter);

    thingLabel = new QLabel("Thing");
    thingLabel->setAlignment(Qt::AlignCenter);

    infoLabel = new QLabel("");
    infoLabel->setAlignment(Qt::AlignCenter);

    reckLineEdit = new QLineEdit;
    shelfLineEdit = new QLineEdit;
    thingLineEdit = new QLineEdit;

    backButton = new QPushButton("Back");
    insertButton = new QPushButton("Insert Item");
    deleteButton = new QPushButton("Delete Item");

    insertDeleteMenuLayout = new QGridLayout;
    insertDeleteMenuLayout->setContentsMargins(5,5,5,5);
    insertDeleteMenuLayout->setSpacing(5);


    //first line
    insertDeleteMenuLayout->addWidget(infoLabel,0,1);
    //second line
    insertDeleteMenuLayout->addWidget(reckLabel,1,0);
    insertDeleteMenuLayout->addWidget(shelfLabel,1,1);
    insertDeleteMenuLayout->addWidget(thingLabel,1,2);
    //trird line
    insertDeleteMenuLayout->addWidget(reckLineEdit,2,0);
    insertDeleteMenuLayout->addWidget(shelfLineEdit,2,1);
    insertDeleteMenuLayout->addWidget(thingLineEdit,2,2);
    //fourth line
    insertDeleteMenuLayout->addWidget(backButton,3,0);
    insertDeleteMenuLayout->addWidget(deleteButton,3,1);
    insertDeleteMenuLayout->addWidget(insertButton,3,2);

    connect(backButton,SIGNAL(clicked()),this,SLOT(sendingBackSignalSlot()));
    connect(insertButton,SIGNAL(clicked()),this,SLOT(sendingInsertSignalSlot()));
    connect(deleteButton,SIGNAL(clicked()),this,SLOT(sendingDeletingSignalSlot()));

    connect(reckLineEdit,SIGNAL(textChanged(QString)),this,SLOT(reckLabelToStringSlot(QString)));
    connect(shelfLineEdit,SIGNAL(textChanged(QString)),this,SLOT(shelfLabelToStringSlot(QString)));
    connect(thingLineEdit,SIGNAL(textChanged(QString)),this,SLOT(thingLabelToStringSlot(QString)));

    connect(dataBaseconnection,SIGNAL(insertInfoSignal(QString)),this,SLOT(becomeInfoLabelTextSlot(QString)));

    setLayout(insertDeleteMenuLayout);

}

void InsertDeleteMenu::reckLabelToStringSlot(QString text){
    reckString=text;
    //qDebug()<<reckString;
}
void InsertDeleteMenu::shelfLabelToStringSlot(QString text){
    shelfString=text;
    //qDebug()<<shelfString;
}
void InsertDeleteMenu::thingLabelToStringSlot(QString text){
    thingString=text;
    //qDebug()<<thingString;
}

void InsertDeleteMenu::becomeAddressSlot(QString address){
    addressString=address;
}

void InsertDeleteMenu::sendingBackSignalSlot(){
    emit backSignal();
}

void InsertDeleteMenu::sendingInsertSignalSlot(){
    if(reckString.isEmpty()||shelfString.isEmpty()||thingString.isEmpty()){
        qDebug()<<"Some line Edit is empty";
        return;
    }

    dataBaseconnection->insertIntoAllSlot(addressString,reckString,shelfString,thingString);

}

void InsertDeleteMenu::sendingDeletingSignalSlot(){
    if(reckString.isEmpty()||shelfString.isEmpty()||thingString.isEmpty()){
        qDebug()<<"Some line Edit is empty";
        return;
    }

    dataBaseconnection->deleteThingAllSlot(addressString,reckString,shelfString,thingString);
}

void InsertDeleteMenu::becomeInfoLabelTextSlot(QString text){
    infoLabel->setText(text);
}
