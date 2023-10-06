QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

win64:RC_ICONS += rec.qrc
RC_ICONS = logo.ico
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#ICON = logo.png

SOURCES += \
    allthingsmenu.cpp \
    changeitempositionmenu.cpp \
    eventswithkladovkamenu.cpp \
    insertdeletemenu.cpp \
    logger.cpp \
    main.cpp \
    mainmenu.cpp \
    newkladovkamenu.cpp \
    openkladovkamenu.cpp \
    settingsmenu.cpp \
    sqlengine.cpp \
    widgetmanager.cpp

HEADERS += \
    allthingsmenu.h \
    changeitempositionmenu.h \
    eventswithkladovkamenu.h \
    insertdeletemenu.h \
    logger.h \
    mainmenu.h \
    newkladovkamenu.h \
    openkladovkamenu.h \
    settingsmenu.h \
    sqlengine.h \
    widgetmanager.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += rec.qrc

DISTFILES += \
    UML_Description_V1.0.qmodel

