//  Describing New Kladovka Menu Widget

#pragma once

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QLineEdit>
#include <QLabel>

class NewKladovkaMenu : public QWidget
{
    Q_OBJECT

private:

    QPushButton *backToMainMenuButton,*pushTheAdressToSQLButton;
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonsLayout;
    QLineEdit *adressEditingLine;
    QLabel *userInfoLabel;

public:
    NewKladovkaMenu(QWidget * parrent= 0);

private slots:

    void backToMainMenuSlot();

signals:

    void backToMainMenuSignal();

};
