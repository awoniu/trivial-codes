cmake_minimum_required(VERSION 3.5)
project(PhysicsLab LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/output)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

subdirs(base)
subdirs(geom)
subdirs(gui)
subdirs(app)
subdirs(env)
