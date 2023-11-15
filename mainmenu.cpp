
#include "mainmenu.h"

MainMenu::MainMenu(SQLEngine *test,QWidget *parrent) : QWidget(parrent),DBOpenProof(test)
{

    errorLabel = new QLabel("");
    errorLabel->setAlignment(Qt::AlignCenter);

    QFont font=errorLabel->font();
    font.setPointSize(10);
    font.setBold(true);
    errorLabel->setFont(font);

    connect(DBOpenProof,SIGNAL(errorConnectionSignal(QString)),this,SLOT(changeLabelAfterError(QString)));

    DBOpenProof->buildConnectionAndDB();

    newKladovkaButton = new QPushButton("New Kladovka");
    openExistsKladovkaButton = new QPushButton("Open The Exists Kladovka");
    settingsButton = new QPushButton("Settings");
    exitButton = new QPushButton("Exit");

    infoLabel = new QLabel("Made by Dudin Dmitrii\nv 1.1");
    infoLabel->setAlignment(Qt::AlignCenter);

    mainMenuLayout = new QVBoxLayout;

    mainMenuLayout->addWidget(errorLabel);
    mainMenuLayout->addWidget(newKladovkaButton);
    mainMenuLayout->addWidget(openExistsKladovkaButton);
    mainMenuLayout->addWidget(settingsButton);
    mainMenuLayout->addWidget(exitButton);
    mainMenuLayout->addWidget(infoLabel);

    //Buttons connections
    connect(newKladovkaButton,SIGNAL(clicked()),this,SLOT(newKladovkaSlotPrivate()));
    connect(openExistsKladovkaButton,SIGNAL(clicked()),this,SLOT(openExistsKladovkaSlotPrivate()));
    connect(settingsButton,SIGNAL(clicked()),this,SLOT(openSettingsMenuSlot()));
    connect(exitButton,SIGNAL(clicked()),qApp,SLOT(quit()));

    setLayout(mainMenuLayout);
}

void MainMenu::newKladovkaSlotPrivate(){
    emit newKladovkaSignal();
}
void MainMenu::openExistsKladovkaSlotPrivate(){
    emit openExistsKladovkaSignal();
}

void MainMenu::openSettingsMenuSlot(){
    emit openSettingsMenuSignal();
}

void MainMenu::changeLabelAfterError(QString text){
    errorLabel->setText(text);

    QMessageBox::warning(0,"Warning","Data Base not found!",
                                 QMessageBox::Ok,QMessageBox::Ok);
}
