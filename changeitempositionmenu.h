#pragma once

//  QT Libraris
#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>

//  Projects SQLite engine
#include "sqlengine.h"

class ChangeItemPositionMenu:public QWidget
{
    Q_OBJECT

private:

    QString itemString{""},reckString{""},shelfString{""},idString{""};

    QVBoxLayout *mainBoxLayout;
    QGridLayout *gridLayout;
    QLabel *thingNameLabel,*changeReckLabel,*changeShelfLabel;
    QLineEdit *newReckLineEdit,*newShelfLineEdit;
    QPushButton *backButton,*changeButton;

    SQLEngine *dataBaseconnection;

public:
    ChangeItemPositionMenu(SQLEngine *engine,QWidget *parrent=0);

private slots:
    void backButtonSlot();
    void becomeReckStringFromLineSlot(QString reck);
    void becomeShelfStringFromLineSlot(QString shelf);
    void changeButtonSlot();

public slots:

    void changeLabelsSlot(QString id,QString thing,QString reck,QString shelf);

signals:
    void backSignal();
    void changeSignal(QString id,QString reck, QString shelf);
};
