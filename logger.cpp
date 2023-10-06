#include "logger.h"

Logger::Logger()
{
    direction=QFileInfo(QCoreApplication::applicationFilePath()).path();
    //logFile.reset(new QFile(direction+"/logFile.log"));
    logFile.reset(new QFile("C:/Users/D/Documents/Kladovka/KladovkaProject/logFile.log"));
    logFile.data()->open(QFile::Append|QFile::Text);
}

void Logger::messageHandler(TypeError type,QString whereAccident,QString message){

    QTextStream out(logFile.data());
    out<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");

    switch(type){
    case TypeError::CRITICAL:

        out<<"<CRITICAL ERROR>";
        break;
    case TypeError::WARNING:

        out<<"<WARNING>";
        break;
    }
    out<<" "<<whereAccident<<": "<<message<<"\n";

    out.flush();
}

void Logger::clearTheFile(){

    logFile.data()->remove();
    logFile.data()->open(QFile::Append|QFile::Text);

    QMessageBox::information(0,"Succes","Log file is empty",QMessageBox::Ok);
}
