#include <gtest/gtest.h>
#include "time_converter.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(time_converter(10, 10, "pm") == "1010");
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(time_converter(12, 12, "pm") == "0012");
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(time_converter(4, 36, "am") == "1636");
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(time_converter(13, 36, "pm") == "ERROR: Wrong input data\n");
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(time_converter(11, 99, "pm") == "ERROR: Wrong input data\n");
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(time_converter(10, 10, "toyotalancruiserprado") == "ERROR: Wrong input data\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}