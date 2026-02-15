cmake_minimum_required(VERSION 3.16)
project(ActivityRegister)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/dimitribenvenuti/Qt/6.10.2/macos")

find_package(Qt6 REQUIRED COMPONENTS Widgets)


add_executable(ActivityRegister
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/Activity.h
        src/Register.h
)

target_link_libraries(ActivityRegister PRIVATE Qt6::Widgets)


add_subdirectory(lib/googletest)
include_directories(lib/googletest/include)

add_executable(runAllTests
        test/runAllTests.cpp
        test/TestActivity.cpp
        test/TestRegister.cpp
        src/Activity.h
        src/Register.h
)

target_link_libraries(runAllTests PRIVATE gtest gtest_main)
include(GoogleTest)
gtest_discover_tests(runAllTests)