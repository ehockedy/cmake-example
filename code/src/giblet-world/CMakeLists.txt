set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../..) # Outputs the executable in the build/ dir

include_directories(../../include)

#set(PROJECT_LINK_LIBS libgiblet-creator.a)

add_executable(giblet-world main.cpp)
target_link_libraries(giblet-world ${CMAKE_SOURCE_DIR}/build/src/giblet-creator/libgiblet-creator.a)

