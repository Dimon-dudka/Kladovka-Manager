//  Describing of Main Menu Widget

#pragma once

//  Basic headers files
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QLabel>
#include <QString>
#include <QMessageBox>

//  Projects own SQLite engine
//  In here its proof that with SQL all right
#include "sqlengine.h"

class MainMenu : public QWidget
{
    Q_OBJECT

private:

    SQLEngine *DBOpenProof;
    QPushButton *newKladovkaButton,
        *openExistsKladovkaButton, *exitButton,*settingsButton;
    QVBoxLayout *mainMenuLayout;
    QLabel *infoLabel,*errorLabel;

public:

    MainMenu(SQLEngine *test,QWidget *parrent=0);


private slots:

    void newKladovkaSlotPrivate();
    void openExistsKladovkaSlotPrivate();
    void openSettingsMenuSlot();

public slots:

    void changeLabelAfterError(const QString text);

signals:

    void newKladovkaSignal();
    void openExistsKladovkaSignal();
    void openSettingsMenuSignal();
};
