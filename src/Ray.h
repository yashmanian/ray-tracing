//
// Created by yashmanian on 8/19/19.
//

#ifndef RAY_H
#define RAY_H
#include "Vector3.h"

/**
 * Equation for Ray defined as
 * p(t) = A + t*B
 * Where p is the position in 3D along ray
 * A is the origin of the ray
 * B is the direction of the ray
 * t is the parameter that changes the 3D point p along B starting from A
 */

class Ray
{
public:
    Ray()
    {
    }

    Ray(const Vector3& rayOrigin, const Vector3& rayDirection)
    {
        A = rayOrigin;
        B = rayDirection;
    }

    Vector3 origin() const
    {
        return A;
    }

    Vector3 direction() const
    {
        return B;
    }

    Vector3 pointAtParam(float t) const
    {
        return A + t*B;
    }

private:
    Vector3 A;
    Vector3 B;

};


#endif //RAY_H
