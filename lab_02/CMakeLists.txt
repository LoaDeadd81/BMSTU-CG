cmake_minimum_required(VERSION 3.16)
project(lab_02)

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

add_executable(lab_02
        lab_02.pro
        main.cpp
        mainwindow.cpp
        inc/mainwindow.h
        mainwindow.ui
        Figure.cpp
        inc/Figure.h
        MyErrors.cpp
        inc/MyErrors.h)

target_link_libraries(lab_02
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

include_directories(./inc)