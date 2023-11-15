// Menu where user can change position of some item

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
    void becomeReckStringFromLineSlot(const QString reck);
    void becomeShelfStringFromLineSlot(const QString shelf);
    void changeButtonSlot();

public slots:

    void changeLabelsSlot(const QString id,const QString thing,const QString reck, const QString shelf);

signals:
    void backSignal();
    void changeSignal(const QString id,const QString reck,const QString shelf);
};
