//  Describing of Main Menu Widget

#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QLabel>

class MainMenu : public QWidget
{
    Q_OBJECT

private:

    QPushButton *newKladovkaButton,
        *openExistsKladovkaButton, *exitButton;

    QVBoxLayout *mainMenuLayout;

    QLabel *infoLabel;

public:
    MainMenu(QWidget *parrent=0);

private slots:

    void newKladovkaSlotPrivate();
    void openExistsKladovkaSlotPrivate();

signals:

    void newKladovkaSignal();
    void openExistsKladovkaSignal();

};
