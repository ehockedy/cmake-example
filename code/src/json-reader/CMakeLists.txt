
include_directories(../../third_party)
include_directories(../../include)

add_library(json-reader STATIC reader.cpp remote-reader.cpp)
