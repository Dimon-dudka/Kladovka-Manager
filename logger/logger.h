//  Simple logger for most recent problems

#pragma once

#include <QFile>
#include <QDir>
#include <QScopedPointer>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>
#include <QCoreApplication>
#include <QString>

class Logger : public QObject
{
private:

    QScopedPointer<QFile> logFile;

    QString direction;

public:

    enum class TypeError{
        WARNING,
        CRITICAL
    };

    Logger(QObject * parrent = 0);

    void messageHandler(TypeError type,const QString whereAccident,const QString message);
    void clearTheFile();
};
