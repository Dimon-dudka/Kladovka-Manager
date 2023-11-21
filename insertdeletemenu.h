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

    void erasingLineEdits();

public:
    InsertDeleteMenu(SQLEngine *engine,QWidget *parrent =0);

public slots:

    void becomeAddressSlot(const QString address);
    void becomeInfoLabelTextSlot(const QString text);

private slots:

    void sendingBackSignalSlot();
    void sendingInsertSignalSlot();
    void sendingDeletingSignalSlot();

    //Slots to become a user choise string from the Line edit
    void reckLabelToStringSlot(const QString text);
    void shelfLabelToStringSlot(const QString text);
    void thingLabelToStringSlot(const QString text);


signals:

    void backSignal();
};
