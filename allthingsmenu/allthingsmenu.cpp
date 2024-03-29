
#include "allthingsmenu.h"

AllThingsMenu::AllThingsMenu(Logger *logParrent,SQLEngine *connection,QWidget *parrent)
    :QWidget(parrent),logging(logParrent),connectionDB(connection)
{

    userInfoLabel = new QLabel("");
    userInfoLabel->setAlignment(Qt::AlignCenter);

    QFont font=userInfoLabel->font();
    font.setPointSize(10);
    font.setBold(true);
    userInfoLabel->setFont(font);

    backButton = new QPushButton("Back");
    deleteButton = new QPushButton("Delete Item");
    changeButton = new QPushButton("Change position");

    treeView = new QTreeWidget;
    treeView->setHeaderLabel("Items in this Kladovka");
    treeView->setSortingEnabled(true);
    treeView->resize(200,100);

    treeItem = new QTreeWidgetItem(treeView);

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(backButton);
    buttonsLayout->addWidget(deleteButton);
    buttonsLayout->addWidget(changeButton);

    AllThingsLayout = new QVBoxLayout;
    AllThingsLayout->addWidget(userInfoLabel);
    AllThingsLayout->addWidget(treeView);
    AllThingsLayout->addLayout(buttonsLayout);


    //Buttons connections
    connect(backButton,SIGNAL(clicked()),this,SLOT(sendingBackSlot()));
    connect(deleteButton,SIGNAL(clicked()),this,SLOT(sendingDeleteQuerySlot()));
    connect(changeButton,SIGNAL(clicked()),this,SLOT(changeSlot()));

    //Tree widget connections
    connect(treeView,SIGNAL(itemClicked(QTreeWidgetItem*,int))
            ,this,SLOT(userChoiseSlot(QTreeWidgetItem*)));
    connect(connectionDB,SIGNAL(updataingTreeSignal()),this,SLOT(updateStuffTree()));

    //SQL connections
    connect(this,SIGNAL(deleteSignal(QString)),connectionDB,SLOT(deleteThingAllByIDSlot(QString)));


    setLayout(AllThingsLayout);

}

void AllThingsMenu::userChoiseSlot(QTreeWidgetItem* test){
    thingString=test->data(0,Qt::DisplayRole).toString();
    reckString=test->data(1,Qt::DisplayRole).toString();
    shelfString=test->data(2,Qt::DisplayRole).toString();
    idString = test->data(3,Qt::DisplayRole).toString();
}

void AllThingsMenu::sendingBackSlot(){
    emit backSignal();
}

void AllThingsMenu::becomeAddressSlot(const QString text){
    addressString=std::move(text);
}

void AllThingsMenu::updateStuffTree(){

    userInfoLabel->setText(addressString);

    connectionDB->changeConnectionToALLINFO();

    // become id, reck, shelf, thing from the DB
    QString queryText = "SELECT id, reck, shelf, thing FROM allInfoKladovki WHERE address = '"
                        +addressString+"' ;";
    if(!connectionDB->query->exec(queryText)){
        logging->messageHandler(Logger::TypeError::WARNING,"AllThingsMenu","Fail in request by updating tree widget");
        //qDebug()<<"Fail SQL Engine in <allthingsmenu.cpp>!";
        return;
    }

    // Reading id, reck, shelf, thing from the query
    QSqlRecord rec = connectionDB->query->record();

    treeView->clear();
    QStringList lst;
    lst<<"thing"<<"reck"<<"shelf"<<"ID";
    treeView->setHeaderLabels(lst);
    treeView->setColumnWidth(0,150);
    treeView->setColumnWidth(1,20);
    treeView->setColumnWidth(2,20);
    treeView->setColumnWidth(3,20);

    // Filling the widget with id, reck, shelf, thing information
    QString tmpID{""},tmpReck{""},tmpShelf{""}, tmpThing{""};
    while(connectionDB->query->next()){

        tmpID = connectionDB->query->value(rec.indexOf("id")).toString();
        tmpReck = connectionDB->query->value(rec.indexOf("reck")).toString();
        tmpShelf = connectionDB->query->value(rec.indexOf("shelf")).toString();
        tmpThing=connectionDB->query->value(rec.indexOf("thing")).toString();

        treeItem = new QTreeWidgetItem(treeView);

        treeItem->setText(0,tmpThing);
        treeItem->setText(1,tmpReck);
        treeItem->setText(2,tmpShelf);
        treeItem->setText(3,tmpID);
    }

    connectionDB->query->clear();

}

void AllThingsMenu::sendingDeleteQuerySlot(){
    if(idString.isEmpty())return;

    int n = QMessageBox::warning(0,"Warning","The choisen option is deleting\n"
                                               "Do you wanna delete choisen Thing?",
                                 QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(n==QMessageBox::No)return;

    emit deleteSignal(std::move(idString));

}

void AllThingsMenu::changeSlot(){
    if(idString.isEmpty()||thingString.isEmpty()||reckString.isEmpty()||shelfString.isEmpty())return;

    emit changeSignal(std::move(idString),std::move(thingString)
                      ,std::move(reckString),std::move(shelfString));
}
