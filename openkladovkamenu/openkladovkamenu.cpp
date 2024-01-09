#include "openkladovkamenu.h"

OpenKladovkaMenu::OpenKladovkaMenu(Logger *logParrent,SQLEngine *connectParameter,QWidget* parrent)
    :QWidget(parrent),logging(logParrent),connectionDB(connectParameter)
{

    addressTxt ="";

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
    treeView->resize(200,100);

    treeItem = new QTreeWidgetItem(treeView);
    updateOfAddressesList();

    menuLayout = new QVBoxLayout;
    menuLayout->addWidget(someInfoLabel);
    menuLayout->addWidget(treeView);
    menuLayout->addLayout(buttonsLayout);

    //Buttons connections
    connect(backMainMenuButton,SIGNAL(clicked()),this,SLOT(sendingbackToMainMenuSlot()));
    connect(deleteKladovkaButton,SIGNAL(clicked()),this,SLOT(deletingButtonSlot()));
    connect(acceptChoiseAndNextButton,SIGNAL(clicked()),this,SLOT(proofAddressAndSendSlot()));

    //Tree widget connections
    connect(treeView,SIGNAL(itemClicked(QTreeWidgetItem*,int))
            ,this,SLOT(userAddressChoiseSlot(QTreeWidgetItem*,int)));

    setLayout(menuLayout);

}

//Slot that become an user selected address in Tree widget
void OpenKladovkaMenu::userAddressChoiseSlot(QTreeWidgetItem* test,int number){
    addressTxt=test->text(number);
}

void OpenKladovkaMenu::deletingButtonSlot(){
    if(addressTxt.isEmpty())return;

    int n = QMessageBox::warning(0,"Warning","The choisen option is deleting\n"
                                 "Do you want to delete choisen Kladovka?",
                                 QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(n==QMessageBox::No)return;


    connectionDB->changeConnectionToADDRESSES();
    connectionDB->deleteTheKladovka(std::move(addressTxt));

    updateOfAddressesList();

}

//Updating function that by using SQL query becomes all addresses
void OpenKladovkaMenu::updateOfAddressesList(){

    connectionDB->changeConnectionToADDRESSES();

    QString queryText{"SELECT address FROM addressKladovki ;"};
    QString tmpAddress {""};

    if(!connectionDB->query->exec(queryText)){
        logging->messageHandler(Logger::TypeError::WARNING
                                ,"OpenKladovkaMenu"
                                ,"Fail in request by updating addresses list");

    }

    QSqlRecord rec = connectionDB->query->record();
    treeView->clear();

    while(connectionDB->query->next()){
        tmpAddress = connectionDB->query->value(rec.indexOf("address")).toString();

        treeItem = new QTreeWidgetItem(treeView);
        treeItem->setText(0,tmpAddress);
    }

    connectionDB->query->clear();
}

//Slot for "back" button
void OpenKladovkaMenu::sendingbackToMainMenuSlot(){
    emit backToMainMenuSignal();
}

void OpenKladovkaMenu::proofAddressAndSendSlot(){
    if(addressTxt.isEmpty())return;
    emit sendTheAddressSignal(addressTxt);
    emit nextMenuSignal();
}
