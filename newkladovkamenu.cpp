
#include "newkladovkamenu.h"

NewKladovkaMenu::NewKladovkaMenu(SQLEngine *test,QWidget * parrent)
    :QWidget(parrent),insertToDBAddress(test)
{
    insertToDBAddress->changeConnectionToADDRESSES();

    sqlQueryStatus = new QLabel("");
    sqlQueryStatus->setAlignment(Qt::AlignCenter);

    userInfoLabel = new QLabel("Enter the kladovka address");
    userInfoLabel->setAlignment(Qt::AlignCenter);

    addressEditingLine = new QLineEdit("");

    backToMainMenuButton = new QPushButton("Back To Menu");
    pushTheAddressToSQLButton = new QPushButton("Enter the new address");

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(backToMainMenuButton);
    buttonsLayout->addWidget(pushTheAddressToSQLButton);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(sqlQueryStatus);
    mainLayout->addWidget(userInfoLabel);
    mainLayout->addWidget(addressEditingLine);
    mainLayout->addLayout(buttonsLayout);

    connect(backToMainMenuButton,SIGNAL(clicked()),this,SLOT(backToMainMenuSlot()));
    connect(addressEditingLine,SIGNAL(textChanged(QString)),this,SLOT(becomeStringFromLineEdit(QString)));

    connect(pushTheAddressToSQLButton,SIGNAL(clicked())
            ,this,SLOT(sendingSignalToSQLEngineSlot()));

    connect(this,SIGNAL(queryToSQLEngineSignal(QString)),insertToDBAddress,SLOT(insertAddressQuery(QString)));

    connect(insertToDBAddress,SIGNAL(addressAlreadyExistsSignal(QString))
            ,sqlQueryStatus,SLOT(setText(QString)));
    connect(insertToDBAddress,SIGNAL(addressAddedSignal(QString))
            ,sqlQueryStatus,SLOT(setText(QString)));

    setLayout(mainLayout);

}

void NewKladovkaMenu::backToMainMenuSlot(){
    emit backToMainMenuSignal();
}

void NewKladovkaMenu::becomeStringFromLineEdit(QString txt){
    addressFromLabel = txt;
}

void NewKladovkaMenu::sendingSignalToSQLEngineSlot(){

    insertToDBAddress->changeConnectionToADDRESSES();

    if(addressFromLabel=="")
        return;

    emit queryToSQLEngineSignal(addressFromLabel);

}
