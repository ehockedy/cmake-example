
include_directories(../../include)

# Create static library
# This will be directly linked and compiled with anything that includes it
add_library(consumer-creator STATIC consumer-generator.cpp consumer.cpp)
add_dependencies(consumer-creator json-reader)
target_link_libraries(consumer-creator ${CMAKE_SOURCE_DIR}/build/src/json-reader/libjson-reader.a)

