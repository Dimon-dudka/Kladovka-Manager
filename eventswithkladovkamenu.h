#pragma once

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>
#include <QString>

class EventsWithKladovkaMenu : public QWidget
{
    Q_OBJECT

private:

    QString addressText;

    QLabel *addressKladovkiLabel;
    QPushButton *insertButton,*deleteButton,*printAllButton,
        *findKonkretThingButton,*backButton;

    QVBoxLayout *eventsMenuLayout;

public:

    EventsWithKladovkaMenu(QWidget *parrent=0);

public slots:

    void becomeAddressTextSlot(QString address);

private slots:

    void sendingBackSignal();
    void insertDeleteWidgetOpen();

signals:

    void backSignal();
    void insertDeleteWidgetOpenSignal();

};
