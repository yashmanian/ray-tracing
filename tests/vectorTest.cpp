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

TEST(vectorTest, operationTest)
{
    float x1 = 1.0f;float y1 = -3.0f;float z1 = 2.0f;
    float x2 = 2.0f;float y2 = 4.0f;float z2 = -1.0f;

    const Vector3 v1(x1, y1, z1);
    const Vector3 v2(x2, y2, z2);
    const float scalar = 2.0f;

    // Element-wise sum of two vectors
    Vector3 resultSum = v1 + v2;
    ASSERT_EQ(resultSum.x(), 3.0f);
    ASSERT_EQ(resultSum.y(), 1.0f);
    ASSERT_EQ(resultSum.z(), 1.0f);

    // Element-wise difference between two vectors
    Vector3 resultDiff = v1 - v2;
    ASSERT_EQ(resultDiff.x(), -1.0f);
    ASSERT_EQ(resultDiff.y(), -7.0f);
    ASSERT_EQ(resultDiff.z(), 3.0f);

    // Element-wise product of two vectors
    Vector3 resultProd = v1 * v2;
    ASSERT_EQ(resultProd.x(), 2.0f);
    ASSERT_EQ(resultProd.y(), -12.0f);
    ASSERT_EQ(resultProd.z(), -2.0f);

    // Element-wise division of two vectors
    Vector3 resultDiv = v1 / v2;
    ASSERT_EQ(resultDiv.x(), 0.5f);
    ASSERT_EQ(resultDiv.y(), -0.75f);
    ASSERT_EQ(resultDiv.z(), -2.0f);

    // Scalar multiplication test
    Vector3 resultScalarProd = scalar*v1;
    ASSERT_EQ(resultScalarProd.x(), 2.0f);
    ASSERT_EQ(resultScalarProd.y(), -6.0f);
    ASSERT_EQ(resultScalarProd.z(), 4.0f);

    // Scalar division test
    Vector3 resultScalarDiv = v1/scalar;
    ASSERT_EQ(resultScalarDiv.x(), 0.5f);
    ASSERT_EQ(resultScalarDiv.y(), -1.5f);
    ASSERT_EQ(resultScalarDiv.z(), 1.0f);

    // Dot product Test
    float resultDotProd = dot(v1, v2);
    ASSERT_EQ(resultDotProd, -12.0f);

    // Cross product Test
    Vector3 resultCrossProd = cross(v1, v2);
    ASSERT_EQ(resultCrossProd.x(), y1*z2 - y2*z1);
    ASSERT_EQ(resultCrossProd.y(), -(x1*z2 - x2*z1));
    ASSERT_EQ(resultCrossProd.z(), x1*y2 - x2*y1);

    // Equivalience Test
    bool equivalience = (v1 == v2);
    ASSERT_FALSE(equivalience);
}

TEST(vectorTest, propertiesTest)
{
    float x1 = 112.0f;float y1 = 12.0f;float z1 = 9.0f;
    Vector3 v1(x1, y1, z1);

    // Computing length and squared length
    ASSERT_EQ(v1.length(), 113.0f);
    ASSERT_EQ(v1.squaredLength(), 12769.0f);

    v1.makeUnitVector();
    ASSERT_EQ(v1.x(), x1/113.0f);
    ASSERT_EQ(v1.y(), y1/113.0f);
    ASSERT_EQ(v1.z(), z1/113.0f);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}