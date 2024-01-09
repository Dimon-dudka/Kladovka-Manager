#pragma once

//  Basic headers files
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QPointer>

//  Logger
#include "logger.h"

class SettingsMenu : public QWidget
{
    Q_OBJECT
private:

    QPointer<QLabel>infoLabel;
    QPointer<Logger>logFile;
    QPointer<QPushButton>backButton,clearLogFileButton;
    QPointer<QVBoxLayout>menuLayout;

public:
    SettingsMenu(Logger *logParrent,QWidget *parrent=0);

private slots:

    void clearLogFileSlot();
    void backToMainMenuSlot();

signals:
    void backToMainMenuSignal();
};
