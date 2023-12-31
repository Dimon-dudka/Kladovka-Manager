
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

    QFont font=infoLabel->font();
    font.setPointSize(10);
    font.setBold(true);
    infoLabel->setFont(font);


    reckLineEdit = new QLineEdit;
    shelfLineEdit = new QLineEdit;
    thingLineEdit = new QLineEdit;

    backButton = new QPushButton("Back");
    insertButton = new QPushButton("Insert Item");
    deleteButton = new QPushButton("Delete Item");


    labelsLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    editLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    buttonsLayout = new QBoxLayout(QBoxLayout::LeftToRight);

    labelsLayout->addWidget(reckLabel,1);
    labelsLayout->addWidget(shelfLabel,1);
    labelsLayout->addWidget(thingLabel,3);

    editLayout->addWidget(reckLineEdit,1);
    editLayout->addWidget(shelfLineEdit,1);
    editLayout->addWidget(thingLineEdit,3);

    buttonsLayout->addWidget(backButton,1);
    buttonsLayout->addWidget(deleteButton,1);
    buttonsLayout->addWidget(insertButton,1);

    allLayout=new QVBoxLayout;
    allLayout->setSpacing(10);

    allLayout->addWidget(infoLabel);
    allLayout->addStretch();
    allLayout->addLayout(labelsLayout);
    allLayout->addStretch();
    allLayout->addLayout(editLayout);
    allLayout->addStretch();
    allLayout->addLayout(buttonsLayout);

    //Buttons connections
    connect(backButton,SIGNAL(clicked()),this,SLOT(sendingBackSignalSlot()));
    connect(insertButton,SIGNAL(clicked()),this,SLOT(sendingInsertSignalSlot()));
    connect(deleteButton,SIGNAL(clicked()),this,SLOT(sendingDeletingSignalSlot()));

    //Line edit connections
    connect(reckLineEdit,SIGNAL(textChanged(QString)),this,SLOT(reckLabelToStringSlot(QString)));
    connect(reckLineEdit,SIGNAL(textChanged(QString)),infoLabel,SLOT(clear()));
    connect(shelfLineEdit,SIGNAL(textChanged(QString)),this,SLOT(shelfLabelToStringSlot(QString)));
    connect(shelfLineEdit,SIGNAL(textChanged(QString)),infoLabel,SLOT(clear()));
    connect(thingLineEdit,SIGNAL(textChanged(QString)),this,SLOT(thingLabelToStringSlot(QString)));
    connect(thingLineEdit,SIGNAL(textChanged(QString)),infoLabel,SLOT(clear()));

    //SQL connections
    connect(dataBaseconnection,SIGNAL(insertInfoSignal(QString)),this,SLOT(becomeInfoLabelTextSlot(QString)));

    setLayout(allLayout);

}

void InsertDeleteMenu::reckLabelToStringSlot(const QString text){
    reckString=text;
}
void InsertDeleteMenu::shelfLabelToStringSlot(const QString text){
    shelfString=text;
}
void InsertDeleteMenu::thingLabelToStringSlot(const QString text){
    thingString=text;
}

void InsertDeleteMenu::becomeAddressSlot(const QString address){
    addressString=address;
}

void InsertDeleteMenu::sendingBackSignalSlot(){
    infoLabel->clear();
    emit backSignal();
}

void InsertDeleteMenu::sendingInsertSignalSlot(){
    if(reckString.isEmpty()||shelfString.isEmpty()||thingString.isEmpty()){
        return;
    }

    dataBaseconnection->insertIntoAllSlot(addressString,std::move(reckString)
                                          ,std::move(shelfString),std::move(thingString));
    QString tmp{infoLabel->text()};
    erasingLineEdits();
    infoLabel->setText(tmp);
}

void InsertDeleteMenu::sendingDeletingSignalSlot(){
    if(reckString.isEmpty()||shelfString.isEmpty()||thingString.isEmpty()){
        return;
    }

    int n = QMessageBox::warning(0,"Warning","Delete option will delete "
                                               "all things\nwith same name on this shel\n"
                                               "Do you want to delete choisen thing?",
                                 QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(n==QMessageBox::No)return;

    dataBaseconnection->deleteThingAllSlot(addressString,std::move(reckString)
                                           ,std::move(shelfString),std::move(thingString));

    erasingLineEdits();

}

void InsertDeleteMenu::becomeInfoLabelTextSlot(const QString text){
    infoLabel->setText(text);
}

void InsertDeleteMenu::erasingLineEdits(){
    reckLineEdit->clear();
    shelfLineEdit->clear();
    thingLineEdit->clear();
}
