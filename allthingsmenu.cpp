
#include "allthingsmenu.h"

AllThingsMenu::AllThingsMenu(SQLEngine *connection,QWidget *parrent)
    :QWidget(parrent),connectionDB(connection)
{
    userInfoLabel = new QLabel("");
    userInfoLabel->setAlignment(Qt::AlignCenter);

    //operationStatusLabel=new QLabel("");
    //operationStatusLabel->setAlignment(Qt::AlignCenter);

    backButton = new QPushButton("Back");
    deleteButton = new QPushButton("Delete Item");

    treeView = new QTreeWidget;
    treeView->setHeaderLabel("Items int this Kladovka");
    treeView->setSortingEnabled(true);
    treeView->resize(200,100);

    //updateStuffTree();

    treeItem = new QTreeWidgetItem(treeView);

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(backButton);
    buttonsLayout->addWidget(deleteButton);

    AllThingsLayout = new QVBoxLayout;
    AllThingsLayout->addWidget(userInfoLabel);
    AllThingsLayout->addWidget(treeView);
    AllThingsLayout->addLayout(buttonsLayout);


    connect(backButton,SIGNAL(clicked()),this,SLOT(sendingBackSlot()));
    connect(deleteButton,SIGNAL(clicked()),this,SLOT(sendingDeleteQuerySlot()));

    connect(treeView,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(userChoiseSlot(QTreeWidgetItem*,int)));

    connect(this,SIGNAL(deleteSignal(QString)),connectionDB,SLOT(deleteThingAllByIDSlot(QString)));
    connect(connectionDB,SIGNAL(updataingTreeSignal()),this,SLOT(updateStuffTree()));

    setLayout(AllThingsLayout);

}

void AllThingsMenu::userChoiseSlot(QTreeWidgetItem* test,int number){
    //addressTxt=test->text(number);
    number =3;
    idString = test->data(number,Qt::DisplayRole).toString();
    //qDebug()<<idString;
    //qDebug()<<addressTxt;
}

void AllThingsMenu::sendingBackSlot(){
    emit backSignal();
}

void AllThingsMenu::becomeAddressSlot(QString text){
    addressString=text;
    //qDebug()<<addressString;
}

void AllThingsMenu::updateStuffTree(){

    userInfoLabel->setText(addressString);

    connectionDB->changeConnectionToALLINFO();

    QString queryText = "SELECT id, reck, shelf, thing FROM allInfoKladovki WHERE address = '"
                        +addressString+"' ;";
    if(!connectionDB->query->exec(queryText)){
        qDebug()<<"Fail SQL Engine in <allthingsmenu.cpp>!";
        return;
    }

    QSqlRecord rec = connectionDB->query->record();
    treeView->clear();
    QStringList lst;
    //lst<<"reck"<<"shelf"<<"thing"<<"ID";
    lst<<"thing"<<"reck"<<"shelf"<<"ID";
    treeView->setHeaderLabels(lst);


    //int tmpID,tmpReck,tmpShelf;
    QString tmpID="",tmpReck="",tmpShelf="", tmpThing="";

    while(connectionDB->query->next()){

        tmpID = connectionDB->query->value(rec.indexOf("id")).toString();
        tmpReck = connectionDB->query->value(rec.indexOf("reck")).toString();
        tmpShelf = connectionDB->query->value(rec.indexOf("shelf")).toString();
        tmpThing=connectionDB->query->value(rec.indexOf("thing")).toString();

        //qDebug()<<tmpID<<" "<<tmpReck<<" "<<tmpShelf<<" "<<tmpThing;

        treeItem = new QTreeWidgetItem(treeView);

        treeItem->setText(0,tmpThing);
        treeItem->setText(1,tmpReck);
        treeItem->setText(2,tmpShelf);
        treeItem->setText(3,tmpID);
    }

    connectionDB->query->clear();

}

void AllThingsMenu::sendingDeleteQuerySlot(){
    if(idString=="-1")return;

    int n = QMessageBox::warning(0,"Warning","The choisen option is deleting\n"
                                               "Do you wanna delete choisen Thing?",
                                 QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(n==QMessageBox::No)return;

    emit deleteSignal(idString);
}
