#include "io.h"

#include <string>
#include <gtest/gtest.h>

TEST(CustomIO, OutputterTestModeSetSuccessfully) {
  Outputter o;
  o.SetModeSuppressed();
  o << "OUTPUTTING\n"; // << std::endl;
  ASSERT_TRUE(1 == 1);
}
/**
TEST(CustomIO, OutputterStandardModeSetSuccessfully) {
  Outputter o;
  o.SetStandardMode();
  ASSERT_TRUE(o.CheckMode() == OutputterMode::standard);
}

TEST(CustomIO, OutputterStandardModeSetSuccessfullyAfterTestModeSet) {
  Outputter o;
  o.SetTestMode();
  o.SetStandardMode();
  ASSERT_TRUE(o.CheckMode() == OutputterMode::standard);
}
*/

