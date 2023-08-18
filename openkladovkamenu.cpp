#include "openkladovkamenu.h"

OpenKladovkaMenu::OpenKladovkaMenu(SQLEngine *connectParameter,QWidget* parrent)
    :QWidget(parrent),connectionDB(connectParameter)
{
    someInfoLabel = new QLabel("Select kladovka address");
    someInfoLabel->setAlignment(Qt::AlignCenter);

    backMainMenuButton=new QPushButton("Back");
    acceptChoiseAndNextButton = new QPushButton("Next");

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(backMainMenuButton);
    buttonsLayout->addWidget(acceptChoiseAndNextButton);

    treeView = new QTreeWidget;
    treeView->setHeaderLabel("Addresses");
    //treeView->resize(100,10);
    treeView->resize(200,100);
    //treeView->setSelectionBehavior(QAbstractItemView::SelectItems);

    treeItem = new QTreeWidgetItem(treeView);
    updateOfAddressesList();

    menuLayout = new QVBoxLayout;
    menuLayout->addWidget(someInfoLabel);
    menuLayout->addWidget(treeView);
    menuLayout->addLayout(buttonsLayout);

    connect(backMainMenuButton,SIGNAL(clicked()),this,SLOT(sendingbackToMainMenuSlot()));

    setLayout(menuLayout);

}

void OpenKladovkaMenu::updateOfAddressesList(){
    QString queryText = "SELECT address FROM addressKladovki ;";
    QString tmpAddress = "";

    if(!connectionDB->query->exec(queryText)){
        qDebug()<<"Fail with query in openkladovkamenu.cpp\n";
    }

    //treeItem = new QTreeWidgetItem(treeView);
    QSqlRecord rec = connectionDB->query->record();
    treeView->clear();

    while(connectionDB->query->next()){
        tmpAddress = connectionDB->query->value(rec.indexOf("address")).toString();
        //qDebug()<<tmpAddress;

        treeItem = new QTreeWidgetItem(treeView);
        treeItem->setText(0,tmpAddress);
    }

    connectionDB->query->clear();
}

void OpenKladovkaMenu::sendingbackToMainMenuSlot(){
    emit backToMainMenuSignal();
}

