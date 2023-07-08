#include "gtest/gtest.h"
#include "libhello/hello.h"

TEST(SampleTest, SampleTest) {

    EXPECT_EQ(13, add(6, 7));
}