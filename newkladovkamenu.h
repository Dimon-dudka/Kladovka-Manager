//  Describing New Kladovka(storage) Menu Widget
//  This widget contatins ability to create the new storage

#pragma once

//  Basic headers files
#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QString>

//  Projects own SQLite engine
#include "sqlengine.h"

class NewKladovkaMenu : public QWidget
{
    Q_OBJECT

private:

    SQLEngine *insertToDBAddress;
    QPushButton *backToMainMenuButton,*pushTheAddressToSQLButton,*openNewKladovka;
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonsLayout;
    QLineEdit *addressEditingLine;
    QLabel *userInfoLabel,*sqlQueryStatus;
    QString addressFromLabel;

public:
    NewKladovkaMenu(SQLEngine *test,QWidget * parrent= 0);

private slots:

    void backToMainMenuSlot();
    void becomeStringFromLineEdit(QString txt);

    void sendingSignalToSQLEngineSlot();
    void goingToNewKladovkaSlot();

signals:

    void backToMainMenuSignal();
    void queryToSQLEngineSignal(QString txt);

    //new
    void goingToNewKladovkaSignal();
    void changeAddressSignal(QString txt);
};
