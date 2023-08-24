#pragma once

//  Basic headers files
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

//  Logger
#include "logger.h"

class SettingsMenu : public QWidget
{
    Q_OBJECT
private:

    QLabel *infoLabel;
    Logger *logFile;
    QPushButton *backButton,*clearLogFileButton;
    QVBoxLayout *menuLayout;

public:
    SettingsMenu(Logger *logParrent,QWidget *parrent=0);

private slots:

    void clearLogFileSlot();
    void backToMainMenuSlot();

signals:
    void backToMainMenuSignal();
};
