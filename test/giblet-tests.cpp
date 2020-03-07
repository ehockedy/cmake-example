#include "giblet.h"
#include "giblet-accessory.h"

#include <gtest/gtest.h>

TEST(GibletTests, GibletAddAccessoryFailsIfTooManyAccessories) {
  GibletAccessory ga;
  Giblet g;

  ASSERT_TRUE(g.AddAccessory(ga));
  ASSERT_TRUE(g.AddAccessory(ga));
  ASSERT_TRUE(g.AddAccessory(ga));
  ASSERT_TRUE(g.AddAccessory(ga));
  ASSERT_TRUE(g.AddAccessory(ga));
  ASSERT_FALSE(g.AddAccessory(ga));
}

