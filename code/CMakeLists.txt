cmake_minimum_required(VERSION 3.10.2)
project (giblet-world)  # project name
#include_directories(include)  # bring the include directory into the environment

#set(SOURCES src/main.cpp src/Giblet.cpp)  # Set the variable SOURCES to contain the names of the source files

#add_executable(giblet-factory ${SOURCES})  # executable to be built, followed by source

# Subdirectories
# These dirs must contain a CMakeLists.txt
add_subdirectory(src/giblet-creator)
add_subdirectory(src/giblet-world)

