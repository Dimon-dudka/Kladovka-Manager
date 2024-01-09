cmake_minimum_required(VERSION 3.5)

project(KladovkaProject VERSION 1.2 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Sql)

if(QT_FOUND)
    message("QT found")
else()
    message(FATAL_ERROR "Cannot find QT")
endif()

set(HEADERS
    ${CMAKE_SOURCE_DIR}/allthingsmenu/allthingsmenu.h
    ${CMAKE_SOURCE_DIR}/changeitempositionmenu/changeitempositionmenu.h
    ${CMAKE_SOURCE_DIR}/eventswithkladovkamenu/eventswithkladovkamenu.h
    ${CMAKE_SOURCE_DIR}/insertdeletemenu/insertdeletemenu.h
    ${CMAKE_SOURCE_DIR}/logger/logger.h
    ${CMAKE_SOURCE_DIR}/mainmenu/mainmenu.h
    ${CMAKE_SOURCE_DIR}/newkladovkamenu/newkladovkamenu.h
    ${CMAKE_SOURCE_DIR}/openkladovkamenu/openkladovkamenu.h
    ${CMAKE_SOURCE_DIR}/settingsmenu/settingsmenu.h
    ${CMAKE_SOURCE_DIR}/sqlengine/sqlengine.h
    ${CMAKE_SOURCE_DIR}/widgetmanager/widgetmanager.h
)

set(SOURCES
    main.cpp
    ${CMAKE_SOURCE_DIR}/allthingsmenu/allthingsmenu.cpp
    ${CMAKE_SOURCE_DIR}/changeitempositionmenu/changeitempositionmenu.cpp
    ${CMAKE_SOURCE_DIR}/eventswithkladovkamenu/eventswithkladovkamenu.cpp
    ${CMAKE_SOURCE_DIR}/insertdeletemenu/insertdeletemenu.cpp
    ${CMAKE_SOURCE_DIR}/logger/logger.cpp
    ${CMAKE_SOURCE_DIR}/mainmenu/mainmenu.cpp
    ${CMAKE_SOURCE_DIR}/newkladovkamenu/newkladovkamenu.cpp
    ${CMAKE_SOURCE_DIR}/openkladovkamenu/openkladovkamenu.cpp
    ${CMAKE_SOURCE_DIR}/settingsmenu/settingsmenu.cpp
    ${CMAKE_SOURCE_DIR}/sqlengine/sqlengine.cpp
    ${CMAKE_SOURCE_DIR}/widgetmanager/widgetmanager.cpp

)

if(WIN32)
    set(app_icon_resource_windows ${CMAKE_SOURCE_DIR}/resources/rec.qrc)

    add_executable(KladovkaProject ${SOURCES} ${HEADERS} ${app_icon_resource_windows})
else()
    add_executable(KladovkaProject ${SOURCES} ${HEADERS} )
endif()

target_include_directories(KladovkaProject
    PUBLIC ${CMAKE_SOURCE_DIR}/allthingsmenu
    PUBLIC ${CMAKE_SOURCE_DIR}/changeitempositionmenu
    PUBLIC ${CMAKE_SOURCE_DIR}/eventswithkladovkamenu
    PUBLIC ${CMAKE_SOURCE_DIR}/insertdeletemenu
    PUBLIC ${CMAKE_SOURCE_DIR}/logger
    PUBLIC ${CMAKE_SOURCE_DIR}/mainmenu
    PUBLIC ${CMAKE_SOURCE_DIR}/newkladovkamenu
    PUBLIC ${CMAKE_SOURCE_DIR}/openkladovkamenu
    PUBLIC ${CMAKE_SOURCE_DIR}/settingsmenu
    PUBLIC ${CMAKE_SOURCE_DIR}/sqlengine
    PUBLIC ${CMAKE_SOURCE_DIR}/widgetmanager
)

target_link_libraries(KladovkaProject
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    PRIVATE Qt${QT_VERSION_MAJOR}::Sql
)
