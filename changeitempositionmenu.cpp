
#include "changeitempositionmenu.h"

ChangeItemPositionMenu::ChangeItemPositionMenu(SQLEngine *engine,QWidget *parrent)
    :QWidget(parrent),dataBaseconnection(engine)
{

    backButton = new QPushButton("Back");
    changeButton = new QPushButton("Change");

    mainBoxLayout = new QVBoxLayout;
    gridLayout = new QGridLayout;

    thingNameLabel = new QLabel("");

    QFont font=thingNameLabel->font();
    font.setPointSize(13);
    font.setBold(true);
    thingNameLabel->setFont(font);

    thingNameLabel->setAlignment(Qt::AlignCenter);
    changeReckLabel=new QLabel("Change Reck");
    changeShelfLabel = new QLabel("Change Shelf");

    newReckLineEdit=new QLineEdit;
    newShelfLineEdit=new QLineEdit;

    backButton=new QPushButton("Back");
    changeButton = new QPushButton("Change");

    gridLayout->addWidget(changeReckLabel,0,0);
    gridLayout->addWidget(changeShelfLabel,0,1);
    gridLayout->addWidget(newReckLineEdit,1,0);
    gridLayout->addWidget(newShelfLineEdit,1,1);
    gridLayout->addWidget(backButton,2,0);
    gridLayout->addWidget(changeButton,2,1);

    mainBoxLayout->addWidget(thingNameLabel);
    mainBoxLayout->addLayout(gridLayout);

    //Buttons connections
    connect(backButton,SIGNAL(clicked()),this,SLOT(backButtonSlot()));
    connect(changeButton,SIGNAL(clicked()),this,SLOT(changeButtonSlot()));

    //Line Edit connections
    connect(newReckLineEdit,SIGNAL(textChanged(QString)),this,SLOT(becomeReckStringFromLineSlot(QString)));
    connect(newShelfLineEdit,SIGNAL(textChanged(QString)),this,SLOT(becomeShelfStringFromLineSlot(QString)));

    setLayout(mainBoxLayout);
}

void ChangeItemPositionMenu::changeLabelsSlot(QString id,QString thing,QString reck,QString shelf){
    idString = id;
    itemString=thing;
    reckString=reck;
    shelfString=shelf;
    thingNameLabel->setText(thing);
}

void ChangeItemPositionMenu::backButtonSlot(){
    emit backSignal();
}

void ChangeItemPositionMenu::becomeReckStringFromLineSlot(QString reck){
    reckString=reck;
}

void ChangeItemPositionMenu::becomeShelfStringFromLineSlot(QString shelf){
    shelfString=shelf;
}

void ChangeItemPositionMenu::changeButtonSlot(){
    if(idString.isEmpty()||reckString.isEmpty()||shelfString.isEmpty())return;
    else{
        emit changeSignal(idString,reckString,shelfString);
    }
    idString.clear();
    reckString.clear();
    shelfString.clear();
}
