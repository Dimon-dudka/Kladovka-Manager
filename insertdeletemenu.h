//  This Menu contains buttons "insert" or "delete" some thing in Kladovka(storage)

#pragma once

//  Basic headers files
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QMessageBox>
#include <QBoxLayout>

//  Projects own SQLite engine
#include "sqlengine.h"

class InsertDeleteMenu : public QWidget
{
    Q_OBJECT

private:

    QBoxLayout *labelsLayout,*editLayout,*buttonsLayout;
    QVBoxLayout *allLayout;

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

    //Slots to become a user choise string from the Line edit
    void reckLabelToStringSlot(QString text);
    void shelfLabelToStringSlot(QString text);
    void thingLabelToStringSlot(QString text);


signals:

    void backSignal();
};
