
#include "settingsmenu.h"

SettingsMenu::SettingsMenu(Logger *logParrent,QWidget *parrent):QWidget(parrent),logFile(logParrent)
{
    infoLabel = new QLabel("Settings");
    infoLabel->setAlignment(Qt::AlignCenter);

    QFont font=infoLabel->font();
    font.setPointSize(10);
    font.setBold(true);
    infoLabel->setFont(font);

    backButton = new QPushButton("Back");
    clearLogFileButton = new QPushButton("Clear the log file");

    menuLayout = new QVBoxLayout;

    menuLayout->addWidget(infoLabel);
    menuLayout->addStretch();
    menuLayout->addWidget(clearLogFileButton);
    menuLayout->addWidget(backButton);

    //Buttons connection
    connect(backButton,SIGNAL(clicked()),this,SLOT(backToMainMenuSlot()));
    connect(clearLogFileButton,SIGNAL(clicked()),this,SLOT(clearLogFileSlot()));

    setLayout(menuLayout);
}

void SettingsMenu::backToMainMenuSlot(){
    emit backToMainMenuSignal();
}

void SettingsMenu::clearLogFileSlot(){
    int n = QMessageBox::warning(0,"Warning","Delete all errors story\n"
                                               "Are you sure?",
                                 QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    if(n==QMessageBox::No)return;
    logFile->clearTheFile();
}
