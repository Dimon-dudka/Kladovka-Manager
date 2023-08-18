
#include "newkladovkamenu.h"

NewKladovkaMenu::NewKladovkaMenu(SQLEngine *test,QWidget * parrent):QWidget(parrent),insertToDBAdress(test)
{
    //insertToDBAdress = new SQLEngine;

    sqlQueryStatus = new QLabel("");
    sqlQueryStatus->setAlignment(Qt::AlignCenter);

    userInfoLabel = new QLabel("Enter the kladovka adress");
    userInfoLabel->setAlignment(Qt::AlignCenter);

    adressEditingLine = new QLineEdit;

    adressFromLabel="";


    backToMainMenuButton = new QPushButton("Back To Menu");
    pushTheAdressToSQLButton = new QPushButton("Enter the new adress");

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(backToMainMenuButton);
    buttonsLayout->addWidget(pushTheAdressToSQLButton);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(sqlQueryStatus);
    mainLayout->addWidget(userInfoLabel);
    mainLayout->addWidget(adressEditingLine);
    mainLayout->addLayout(buttonsLayout);

    connect(backToMainMenuButton,SIGNAL(clicked()),this,SLOT(backToMainMenuSlot()));
    connect(adressEditingLine,SIGNAL(textChanged(QString)),this,SLOT(becomeStringFromLineEdit(QString)));

    connect(pushTheAdressToSQLButton,SIGNAL(clicked())
            ,this,SLOT(sendingSignalToSQLEngineSlot()));

    connect(this,SIGNAL(queryToSQLEngineSignal(QString)),insertToDBAdress,SLOT(insertAdressQuery(QString)));

    connect(insertToDBAdress,SIGNAL(adressAlreadyExistsSignal(QString))
            ,sqlQueryStatus,SLOT(setText(QString)));
    connect(insertToDBAdress,SIGNAL(adressAddedSignal(QString))
            ,sqlQueryStatus,SLOT(setText(QString)));

    setLayout(mainLayout);

}

void NewKladovkaMenu::backToMainMenuSlot(){
    emit backToMainMenuSignal();
}

void NewKladovkaMenu::becomeStringFromLineEdit(QString txt){
    adressFromLabel = txt;
}

void NewKladovkaMenu::sendingSignalToSQLEngineSlot(){
    if(adressFromLabel=="")
        return;

    emit queryToSQLEngineSignal(adressFromLabel);

}
