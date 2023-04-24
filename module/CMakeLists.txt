cmake_minimum_required(VERSION 3.14)

project(module VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

set(LIB_SOURCES
    inc/activitybutton.h
    inc/sidewidget.h
    inc/editwidget.h

    src/activitybutton.cpp
    src/sidewidget.cpp
    src/editwidget.cpp
)

add_library(module SHARED ${LIB_SOURCES})
set_target_properties(module PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_library(module_static STATIC ${LIB_SOURCES})
set_target_properties(module_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

target_link_libraries(module PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(module_static PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_compile_definitions(module PRIVATE PLUGIN_LIBRARY)
target_compile_definitions(module_static PRIVATE PLUGIN_LIBRARY)

install(TARGETS module module_static
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
