set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../test)
include_directories(../include)
include_directories(../third_party)

add_executable(json-reader-tests json-reader-tests.cpp)
add_dependencies(json-reader-tests json-reader) # not sure how much need this
target_link_libraries(json-reader-tests ${CMAKE_SOURCE_DIR}/build/src/json-reader/libjson-reader.a)
