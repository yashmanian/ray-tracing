//
// Created by yashmanian on 9/1/19.
//

#include <gtest/gtest.h>
#include <iostream>
#include "Ray.h"

TEST(rayTest, initTest)
{
    Vector3 origin(0.0f, 0.0f, 0.0f);
    Vector3 direction(-1.0f, 2.0f, 1.0f);

    Ray testRay(origin, direction);
    ASSERT_TRUE(testRay.origin() == origin);
    ASSERT_TRUE(testRay.direction() == direction);
}

TEST(rayTest, paramTest)
{
    Vector3 origin(0.0f, 0.0f, 0.0f);
    Vector3 direction(-1.0f, 2.0f, 1.0f);
    Ray testRay(origin, direction);
    float t = 2;

    Vector3 paramResult = origin + t*direction;
    ASSERT_TRUE(testRay.pointAtParam(t) == paramResult);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
