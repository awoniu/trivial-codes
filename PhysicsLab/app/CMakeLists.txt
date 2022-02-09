cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED PATHS "/opt/Qt5.14.2/5.14.2/gcc_64/lib/cmake/Qt5/")
set(QRC_SOURCE_FILES src.qrc)
qt5_add_resources(QRC_FILES ${QRC_SOURCE_FILES})

add_executable(PhysicsLab.run
  main.cpp
)

target_link_libraries(PhysicsLab.run PRIVATE pl_env pl_geom pl_base pl_gui Qt5::Widgets GL pthread)
