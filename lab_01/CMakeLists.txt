cmake_minimum_required(VERSION 3.16)
project(lab_01)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:\\Qt\\6.2.3\\mingw_64\\lib\\cmake\\")


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab_01
        figures.cpp
        figures.h
        lan_01.pro
        lan_01.pro.user
        main.cpp
        mainwindow.ui
        mainwindow.h
        mainwindow.cpp
        myerrors.cpp
        myerrors.h
        )

target_link_libraries(lab_01
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )


include_directories(../build-lab_01-Desktop_Qt_6_2_3_MinGW_64_bit-Debug)