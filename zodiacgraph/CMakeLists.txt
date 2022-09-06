
project(ZodiacGraph)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CXX_FILES
    baseedge.cpp
    bezieredge.cpp
    drawedge.cpp
    edgearrow.cpp
    edgegroup.cpp
    edgegroupinterface.cpp
    edgegrouppair.cpp
    edgelabel.cpp
    labeltextfactory.cpp
    node.cpp
    nodehandle.cpp
    nodelabel.cpp
    perimeter.cpp
    plug.cpp
    plugarranger.cpp
    plugedge.cpp
    plughandle.cpp
    pluglabel.cpp
    scene.cpp
    scenehandle.cpp
    straightdoubleedge.cpp
    straightedge.cpp
    view.cpp)

set(CXX_HEADER
    baseedge.h
    bezieredge.h
    drawedge.h
    edgearrow.h
    edgegroup.h
    edgegroupinterface.h
    edgegrouppair.h
    edgelabel.h
    labeltextfactory.h
    node.h
    nodehandle.h
    nodelabel.h
    perimeter.h
    plug.h
    plugarranger.h
    plugedge.h
    plughandle.h
    pluglabel.h
    scene.h
    scenehandle.h
    straightdoubleedge.h
    straightedge.h
    utils.h
    view.h
    )

add_library(${PROJECT_NAME} STATIC  ${CXX_FILES})

target_link_libraries(
        ${PROJECT_NAME}
        PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${CXX_HEADER}
)

