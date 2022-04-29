cmake_minimum_required(VERSION 3.21)
<<<<<<<< HEAD:lab_05/CMakeLists.txt
project(lab_05)
========
project(lab_06)
>>>>>>>> lab_06:lab_06/CMakeLists.txt

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.2.4/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

<<<<<<<< HEAD:lab_05/CMakeLists.txt
add_executable(lab_05
========
add_executable(lab_06
>>>>>>>> lab_06:lab_06/CMakeLists.txt
        Errors.h
        Errors.cpp
        Graphics.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
<<<<<<<< HEAD:lab_05/CMakeLists.txt
        Edge.h)

target_link_libraries(lab_05
========
        )

target_link_libraries(lab_06
>>>>>>>> lab_06:lab_06/CMakeLists.txt
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
