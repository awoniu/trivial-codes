cmake_minimum_required(VERSION 3.0)
add_definitions(-fPIC)
#add_definitions(-Wl,--whole-archive)
project("merge static lib")

add_library(func0 func0.cc)

link_directories(./)
link_directories(./build)
add_library(func1 func1.cc)
target_link_libraries(func1 func0 -Wl,--whole-archive)

add_custom_command(OUTPUT libmerge.a 
COMMAND ar crsT libmerge.a libfunc0.a libfunc1.a && echo "merge command")
add_custom_target(libmerge ALL DEPENDS libmerge.a)

link_directories(./)
link_directories(./build)
add_executable(main.out main.cc)
target_link_libraries(main.out merge)

add_dependencies(main.out libmerge)
add_dependencies(libmerge func1)
add_dependencies(libmerge func0)

