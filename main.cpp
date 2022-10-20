/**
 * @author zouxiaoliang
 * @date 2022/10/20
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(Helloworld, True) { EXPECT_TRUE(true); }
TEST(Helloworld, False) { EXPECT_TRUE(false); }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
