#pragma once

//  QT Libraris
#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>

class changeItemPositionMenu:public QWidget
{
    Q_OBJECT

private:

    QVBoxLayout *mainBoxLayout;
    QHBoxLayout *buttonsLayout,*lineEditLayout,*labelLayout;
    QLabel *thingNameLabel,*currentReckLabel,*currentShelfLabel;
    QLineEdit *newReckLineEdit,*newShelfLineEdit;
    QPushButton *backButton,*changeButton;

public:
    changeItemPositionMenu(QWidget *parrent=0);
};
