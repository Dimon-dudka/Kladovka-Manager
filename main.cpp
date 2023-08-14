//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
//
// Started on 14.08.2023
//
// KLADOVKA PROJECT
//--------------------------------------------------------------------------------------------

#include "widgetmanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    WidgetManager mainApp;

    mainApp.show();

    return app.exec();
}
