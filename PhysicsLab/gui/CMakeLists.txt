cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED PATHS "/opt/Qt5.14.2/5.14.2/gcc_64/lib/cmake/Qt5/")
set(QRC_SOURCE_FILES src.qrc)
qt5_add_resources(QRC_FILES ${QRC_SOURCE_FILES})

add_library(pl_gui
  # ${QRC_FILES}
  mainwindow.cpp
  mainwindow.h
  glwidget.cpp
  glwidget.h
  dataPaint.cc
  dataPaint.h
)

target_link_libraries(pl_gui PRIVATE Qt5::Widgets GL)

