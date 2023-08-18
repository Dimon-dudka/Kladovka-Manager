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

    SQLEngine *insertToDBAdress;

    QPushButton *backToMainMenuButton,*pushTheAdressToSQLButton;
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonsLayout;
    QLineEdit *adressEditingLine;
    QLabel *userInfoLabel,*sqlQueryStatus;

    QString adressFromLabel;

public:
    NewKladovkaMenu(QWidget * parrent= 0);

private slots:

    void backToMainMenuSlot();
    void becomeStringFromLineEdit(QString txt);

    void sendingSignalToSQLEngineSlot();

signals:

    void backToMainMenuSignal();

    void queryToSQLEngineSignal(QString txt);

};
