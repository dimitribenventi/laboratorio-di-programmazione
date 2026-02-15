cmake_minimum_required(VERSION 4.1)
project(ActivityRegister)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ActivityRegister
        main.cpp
        mainwindow.cpp
        Activity.h
        Register.h
        mainwindow.cpp
        mainwindow.h
)

target_link_libraries(ActivityRegister PRIVATE Qt6::Widgets)

