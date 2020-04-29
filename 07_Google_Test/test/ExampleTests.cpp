#include "gtest/gtest.h"
#include "../src/OrbitalMath.h"

TEST(ExampleTests, DemonstrateGtest) {
    OrbitalMath cls;
    EXPECT_EQ(false, cls.fun());
}

TEST(AnotherTests, firstOne) {
    EXPECT_TRUE(false);
}

TEST(AnotherTests, secondOne) {
    EXPECT_TRUE(true);
}