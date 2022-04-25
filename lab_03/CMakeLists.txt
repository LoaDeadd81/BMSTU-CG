cmake_minimum_required(VERSION 3.21)
project(lab_03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.2.4/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
        Charts)

add_executable(lab_03
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Algo.cpp
        Algo.h
        Point.h
        Graphics.h
        Errors.cpp
        Errors.h
        Point.cpp
        form.cpp
        form.h
        form.ui
        )

target_link_libraries(lab_03
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
