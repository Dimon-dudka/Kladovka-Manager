
#include "changeitempositionmenu.h"

changeItemPositionMenu::changeItemPositionMenu(QWidget *parrent):QWidget(parrent)
{

    backButton = new QPushButton("Back");
    changeButton = new QPushButton("Change");


    //piece of shit
    mainBoxLayout = new QVBoxLayout;
    labelLayout=new QHBoxLayout;
    lineEditLayout=new QHBoxLayout;
    buttonsLayout=new QHBoxLayout;



}

