
#include "newkladovkamenu.h"

NewKladovkaMenu::NewKladovkaMenu(QWidget * parrent):QWidget(parrent)
{
    userInfoLabel = new QLabel("Enter the kladovka adress");
    userInfoLabel->setAlignment(Qt::AlignCenter);

    adressEditingLine = new QLineEdit;

    backToMainMenuButton = new QPushButton("Back To Menu");
    pushTheAdressToSQLButton = new QPushButton("Enter the new adress");

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(backToMainMenuButton);
    buttonsLayout->addWidget(pushTheAdressToSQLButton);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(userInfoLabel);
    mainLayout->addWidget(adressEditingLine);
    mainLayout->addLayout(buttonsLayout);

    connect(backToMainMenuButton,SIGNAL(clicked()),this,SLOT(backToMainMenuSlot()));

    setLayout(mainLayout);

}

void NewKladovkaMenu::backToMainMenuSlot(){
    emit backToMainMenuSignal();
}
