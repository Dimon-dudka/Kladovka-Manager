//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
//
// Started on 14.08.2023
//
// v 0.1 - 20.08.2023
// v 1.0 - 24.08.2023
// v 1.1 - 15.11.2023
//
// KLADOVKA PROJECT
//
// This application is designed to simplify the inventory
// of items in warehouses or storerooms
//--------------------------------------------------------------------------------------------

#include "widgetmanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    WidgetManager mainApp;

    mainApp.show();

    return app.exec();
}
