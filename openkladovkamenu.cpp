#include "openkladovkamenu.h"

OpenKladovkaMenu::OpenKladovkaMenu(SQLEngine *connectParameter,QWidget* parrent)
    :QWidget(parrent),connectionDB(connectParameter)
{
    addressTxt = "";

    someInfoLabel = new QLabel("Select kladovka address");
    someInfoLabel->setAlignment(Qt::AlignCenter);

    backMainMenuButton=new QPushButton("Back");
    acceptChoiseAndNextButton = new QPushButton("Next");
    deleteKladovkaButton = new QPushButton("Delete");

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(backMainMenuButton);
    buttonsLayout->addWidget(deleteKladovkaButton);
    buttonsLayout->addWidget(acceptChoiseAndNextButton);

    treeView = new QTreeWidget;
    treeView->setHeaderLabel("Addresses");
    treeView->setSortingEnabled(true);
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
    connect(deleteKladovkaButton,SIGNAL(clicked()),this,SLOT(deletingButtonSlot()));

    connect(treeView,SIGNAL(itemClicked(QTreeWidgetItem*,int))
            ,this,SLOT(userAddressChoiseSlot(QTreeWidgetItem*,int)));

    setLayout(menuLayout);

}

//Slot that become an user selected address in Tree widget
void OpenKladovkaMenu::userAddressChoiseSlot(QTreeWidgetItem* test,int number){
    addressTxt=test->text(number);
    //qDebug()<<addressTxt;
}

void OpenKladovkaMenu::deletingButtonSlot(){
    if(addressTxt.isEmpty())return;
    if(addressTxt=="")return;

    int n = QMessageBox::warning(0,"Warning","The choisen option is deleting\n"
                                 "Do you want to delete choisen Kladovka?",
                                 QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(n==QMessageBox::No)return;


    connectionDB->changeConnectionToADDRESSES();
    connectionDB->deleteTheKladovka(addressTxt);
    updateOfAddressesList();

}

//Updating function that by using SQL query becomes all addresses
void OpenKladovkaMenu::updateOfAddressesList(){

    connectionDB->changeConnectionToADDRESSES();

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

//Slot for "back" button
void OpenKladovkaMenu::sendingbackToMainMenuSlot(){
    emit backToMainMenuSignal();
}

