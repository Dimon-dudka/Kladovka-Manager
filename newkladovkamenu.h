//  Describing New Kladovka Menu Widget

#pragma once

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QString>

#include "sqlengine.h"

class NewKladovkaMenu : public QWidget
{
    Q_OBJECT

private:

    SQLEngine *insertToDBAddress;

    QPushButton *backToMainMenuButton,*pushTheAddressToSQLButton;
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

signals:

    void backToMainMenuSignal();

    void queryToSQLEngineSignal(QString txt);

};
