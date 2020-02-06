#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "../include/reader.h"

TEST_CASE("Initial test", "[json-reader]") {
  REQUIRE(1 == 1);
}
TEST_CASE("Second test", "[other]") {
  REQUIRE(2 == 2);
}
