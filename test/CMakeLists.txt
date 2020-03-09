set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../test)
include_directories(../include)
include_directories(../third_party)



#Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

# CMAKE_COMMAND - full path to cmake executable
# CMAKE_GENERATOR - the generator being used
#   - generator is what cmake uses to create configuration files for
#     the make build system to compile/link
# CMAKE_CURRENT_BINARY_DIR - the path to the build directory where this
#     config is being processed.
#   - Whenever add_subdirectory is called it makes the relevant directory
#     within the build directory. Since this config exists in test/ (relative
#     to root Cmake file), the output directory for what is built by this
#     config will be placed in build/test
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()


# Catch2 tests
#add_executable(json-reader-tests json-reader-tests.cpp)
#add_dependencies(json-reader-tests json-reader)
#target_link_libraries(json-reader-tests ${CMAKE_SOURCE_DIR}/build/src/json-reader/libjson-reader.a)

#add_executable(json-use-tests json-use-tests.cpp)
#add_dependencies(json-use-tests json-reader)
#target_link_libraries(json-use-tests ${CMAKE_SOURCE_DIR}/build/src/json-reader/libjson-reader.a)



# Gtests

add_library(gtest_main_custom STATIC gtest_main_custom.cpp)
target_link_libraries(gtest_main_custom gtest)

add_executable(json-reader-tests json-reader-tests.cpp)
#add_dependencies(json-reader-gtests json-reader)
target_link_libraries(json-reader-tests ${CMAKE_SOURCE_DIR}/build/src/json-reader/libjson-reader.a gtest_main_custom)

add_executable(giblet-tests giblet-tests.cpp ../src/giblet-creator/giblet.cpp ../src/giblet-creator/giblet-accessory.cpp)
target_link_libraries(giblet-tests gtest_main_custom)

add_executable(json-use-tests json-use-tests.cpp)
target_link_libraries(json-use-tests ${CMAKE_SOURCE_DIR}/build/src/json-reader/libjson-reader.a gtest_main_custom)

add_executable(io-tests io-tests.cpp)
target_link_libraries(io-tests ${CMAKE_SOURCE_DIR}/build/src/io/libio.a gtest_main_custom)
