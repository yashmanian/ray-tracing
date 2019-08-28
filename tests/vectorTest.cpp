//
// Created by yashmanian on 8/27/19.
//

#include <gtest/gtest.h>
#include <iostream>
#include "Vector3.h"

TEST(vectorTest, initTest)
{
    float x = 1.0f;
    float y = 2.0f;
    float z = 1.0f;

    Vector3 v1(x, y, z);
    // Coordinate Test
    ASSERT_EQ(x, v1.x());
    ASSERT_EQ(y, v1.y());
    ASSERT_EQ(z, v1.z());

    // Color test
    ASSERT_EQ(x, v1.r());
    ASSERT_EQ(y, v1.g());
    ASSERT_EQ(z, v1.b());

    // Overloaded index operator test
    ASSERT_EQ(x, v1[0]);
    ASSERT_EQ(y, v1[1]);
    ASSERT_EQ(z, v1[2]);

    // Overloaded positive and negative operations test
    Vector3 v2 = +v1;
    ASSERT_EQ(x, v2.x());
    ASSERT_EQ(y, v2.y());
    ASSERT_EQ(z, v2.z());

    Vector3 v3 = -v1;
    ASSERT_EQ(-1.0f*x, v3.x());
    ASSERT_EQ(-1.0f*y, v3.y());
    ASSERT_EQ(-1.0f*z, v3.z());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}