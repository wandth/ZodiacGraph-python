cmake_minimum_required(VERSION 3.23)
project(ZodiacGraphDemo)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(Qt5_DIR "D:/Qt/Qt5.12.5/5.12.5/msvc2015_64/lib/cmake/Qt5")

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set(CXX_FILES main.cpp
    mainwindow.cpp
    collapsible.cpp
    mainctrl.cpp
    nodectrl.cpp
    nodeproperties.cpp
    propertyeditor.cpp)


set(CXX_HEADER
    mainwindow.h
    collapsible.h
    mainctrl.h
    nodectrl.h
    nodeproperties.h
    propertyeditor.h
    )

qt5_add_resources(QRC_FILES res/icons.qrc)

ADD_SUBDIRECTORY(ZodiacGraph)

add_executable(${PROJECT_NAME} ${CXX_FILES} ${CXX_HEADER} ${QRC_FILES})

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        ZodiacGraph
)

message(warning ZodiacGraph)