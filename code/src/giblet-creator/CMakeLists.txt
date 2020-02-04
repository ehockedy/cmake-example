
include_directories(../../include)

# Create static library
# This will be directly linked and compiled with anything that includes it
add_library(giblet-creator STATIC Giblet.cpp)
