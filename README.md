# Kladovka-Manager
This is a small GUI program that provides the ability to control items in warehouses, storerooms, etc. and change, add, delete them.

Technology stack: C++ 17, QT 6.5, SQLITE, GIT

Description:

The program is implemented on the basis of QT widgets.
It is a manager of storages, storerooms, etc. 
Implements the ability to add and delete addresses of storerooms, as well as add items to specific storerooms and delete them. 
It is also possible to display the entire contents of the pantry.
To add and remove items, you must also enter the number of their cabinet/shelving as well as the shelves where they are located.

Description of the functioning of the program:

Widgets are managed, as well as the connection of the main signals for interaction takes place in the "WidgetManager" class,
which is inherited from the "Qstackedwidget" class.
The rest of the widget classes describe the interface and basic user interactions.
There are also two classes with which the user does not interact directly.
These are the "SQLEngine" and "Logger" classes. 
"SQLEngine" - implements the engine and interfaces for working with databases. 
"Logger" - records all major errors in the .log file, and also provides the ability to clean this file for the user

The goal of the project was to solve some personal tasks for the home, but the main thing is to apply the mastered technologies in practice.