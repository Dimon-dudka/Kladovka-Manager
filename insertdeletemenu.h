#pragma once

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QLineEdit>

#include "sqlengine.h"

class InsertDeleteMenu : public QWidget
{
    Q_OBJECT

private:

    SQLEngine *dataBaseconnection;

    QString addressString,reckString,shelfString,thingString;

    QLabel *reckLabel,*shelfLabel,*thingLabel,*infoLabel;
    QLineEdit *reckLineEdit,*shelfLineEdit,*thingLineEdit;
    QPushButton *backButton,*insertButton,*deleteButton;

    QGridLayout *insertDeleteMenuLayout;

public:
    InsertDeleteMenu(SQLEngine *engine,QWidget *parrent =0);

public slots:

    void becomeAddressSlot(QString address);
    void becomeInfoLabelTextSlot(QString text);

private slots:

    void sendingBackSignalSlot();
    void sendingInsertSignalSlot();
    void sendingDeletingSignalSlot();

    void reckLabelToStringSlot(QString text);
    void shelfLabelToStringSlot(QString text);
    void thingLabelToStringSlot(QString text);


signals:

    void backSignal();
    //void insertSignal(QString address,QString reck,QString shelf,QString thing);
};
