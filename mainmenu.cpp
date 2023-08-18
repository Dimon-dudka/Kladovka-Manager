
#include "mainmenu.h"

MainMenu::MainMenu(SQLEngine *test,QWidget *parrent) : QWidget(parrent),DBOpenProof(test)
{

    //DBOpenProof = test;

    errorLabel = new QLabel("");
    errorLabel->setAlignment(Qt::AlignCenter);
    connect(DBOpenProof,SIGNAL(errorConnectionSignal(QString)),this,SLOT(changeLabelAfterError(QString)));

    DBOpenProof->buildConnectionAndDB();

    newKladovkaButton = new QPushButton("New Kladovka");
    openExistsKladovkaButton = new QPushButton("Open The Exists Kladovka");
    exitButton = new QPushButton("Exit");

    infoLabel = new QLabel("Made by Dudin Dmitrii\nv 0.1");
    infoLabel->setAlignment(Qt::AlignCenter);



    mainMenuLayout = new QVBoxLayout;

    mainMenuLayout->addWidget(errorLabel);
    mainMenuLayout->addWidget(newKladovkaButton);
    mainMenuLayout->addWidget(openExistsKladovkaButton);
    mainMenuLayout->addWidget(exitButton);
    mainMenuLayout->addWidget(infoLabel);

    connect(newKladovkaButton,SIGNAL(clicked()),this,SLOT(newKladovkaSlotPrivate()));
    connect(openExistsKladovkaButton,SIGNAL(clicked()),this,SLOT(openExistsKladovkaSlotPrivate()));
    connect(exitButton,SIGNAL(clicked()),qApp,SLOT(quit()));

    setLayout(mainMenuLayout);
}

void MainMenu::newKladovkaSlotPrivate(){
    emit newKladovkaSignal();
}
void MainMenu::openExistsKladovkaSlotPrivate(){
    emit openExistsKladovkaSignal();
}


