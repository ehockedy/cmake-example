
include_directories(../../include)

# Create static library
# This will be directly linked and compiled with anything that includes it
add_library(giblet-creator STATIC giblet-generator.cpp giblet-accessory.cpp giblet.cpp)
add_dependencies(giblet-creator json-reader)
target_link_libraries(giblet-creator ${CMAKE_SOURCE_DIR}/build/src/json-reader/libjson-reader.a ${CMAKE_SOURCE_DIR}/build/src/io/libio.a)

