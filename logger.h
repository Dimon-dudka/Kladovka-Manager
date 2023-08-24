//  Simple logger for most recent problems

#pragma once

#include <QFile>
#include <QDir>
#include <QScopedPointer>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>
//#include <QLoggingCategory>

class Logger
{
private:

    QScopedPointer<QFile> logFile;

public:

    enum TypeError{
        WARNING,
        CRITICAL
    };

    Logger();

    void messageHandler(TypeError type,QString whereAccident,QString message);
    void clearTheFile();
};
