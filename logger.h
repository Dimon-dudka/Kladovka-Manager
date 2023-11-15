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

class Logger
{
private:

    QScopedPointer<QFile> logFile;

    QString direction;

public:

    enum TypeError{
        WARNING,
        CRITICAL
    };

    Logger();

    void messageHandler(TypeError type,const QString whereAccident,const QString message);
    void clearTheFile();
};
