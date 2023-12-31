
#include "newkladovkamenu.h"

NewKladovkaMenu::NewKladovkaMenu(SQLEngine *test,QWidget * parrent)
    :QWidget(parrent),insertToDBAddress(test)
{
    insertToDBAddress->changeConnectionToADDRESSES();

    sqlQueryStatus = new QLabel("");
    sqlQueryStatus->setAlignment(Qt::AlignCenter);

    QFont font=sqlQueryStatus->font();
    font.setPointSize(10);
    font.setBold(true);
    sqlQueryStatus->setFont(font);

    userInfoLabel = new QLabel("Enter the kladovka address");
    userInfoLabel->setAlignment(Qt::AlignCenter);

    font=userInfoLabel->font();
    font.setPointSize(10);
    userInfoLabel->setFont(font);

    addressEditingLine = new QLineEdit("");

    backToMainMenuButton = new QPushButton("Back");
    pushTheAddressToSQLButton = new QPushButton("Enter");
    openNewKladovka = new QPushButton("Open");

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(backToMainMenuButton);
    buttonsLayout->addWidget(pushTheAddressToSQLButton);
    buttonsLayout->addWidget(openNewKladovka);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(sqlQueryStatus);
    mainLayout->addWidget(userInfoLabel);
    mainLayout->addWidget(addressEditingLine);
    mainLayout->addLayout(buttonsLayout);

    //Buttons connections
    connect(backToMainMenuButton,SIGNAL(clicked()),this,SLOT(backToMainMenuSlot()));
    connect(pushTheAddressToSQLButton,SIGNAL(clicked())
            ,this,SLOT(sendingSignalToSQLEngineSlot()));
    connect(openNewKladovka,SIGNAL(clicked()),this,SLOT(goingToNewKladovkaSlot()));

    //Line edit connections
    connect(addressEditingLine,SIGNAL(textChanged(QString))
            ,this,SLOT(becomeStringFromLineEdit(QString)));
    connect(addressEditingLine,SIGNAL(textChanged(QString)),
            sqlQueryStatus,SLOT(clear()));

    //SQL connections
    connect(this,SIGNAL(queryToSQLEngineSignal(QString))
            ,insertToDBAddress,SLOT(insertAddressQuery(QString)));
    connect(insertToDBAddress,SIGNAL(addressAlreadyExistsSignal(QString))
            ,sqlQueryStatus,SLOT(setText(QString)));
    connect(insertToDBAddress,SIGNAL(addressAddedSignal(QString))
            ,sqlQueryStatus,SLOT(setText(QString)));

    setLayout(mainLayout);

}

void NewKladovkaMenu::goingToNewKladovkaSlot(){

    if(addressFromLabel.isEmpty()||sqlQueryStatus->text() !="Address added"){
        return;
    }

    sqlQueryStatus->clear();
    emit goingToNewKladovkaSignal();
    emit changeAddressSignal(std::move(addressFromLabel));
    addressEditingLine->clear();
}

void NewKladovkaMenu::backToMainMenuSlot(){
    sqlQueryStatus->clear();
    emit backToMainMenuSignal();
}

void NewKladovkaMenu::becomeStringFromLineEdit(const QString txt){
    addressFromLabel=std::move(txt);
}

void NewKladovkaMenu::sendingSignalToSQLEngineSlot(){

    insertToDBAddress->changeConnectionToADDRESSES();

    if(addressFromLabel.isEmpty())
        return;

    emit queryToSQLEngineSignal(addressFromLabel);
}
