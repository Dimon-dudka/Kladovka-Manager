//  Describing of Main Menu Widget

#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QLabel>
#include <QString>

#include "sqlengine.h"

class MainMenu : public QWidget
{
    Q_OBJECT

private:

    SQLEngine *DBOpenProof;

    QPushButton *newKladovkaButton,
        *openExistsKladovkaButton, *exitButton;

    QVBoxLayout *mainMenuLayout;

    QLabel *infoLabel,*errorLabel;

public:

    MainMenu(QWidget *parrent=0);


private slots:

    void newKladovkaSlotPrivate();
    void openExistsKladovkaSlotPrivate();

public slots:

    void changeLabelAfterError(QString text){
        qDebug()<<"changeLabelAfterError";
         errorLabel->setText(text);
    }

signals:

    void newKladovkaSignal();
    void openExistsKladovkaSignal();

};
