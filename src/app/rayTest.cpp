//
// Created by yashmanian on 8/17/19.
//
#include <iostream>
#include <fstream>
#include "Ray.h"

float hitSphere(const Vector3& center, float radius, const Ray& ray)
{
    Vector3 originToCenter = ray.origin() - center;
    float a = dot(ray.direction(), ray.direction());
    float b = 2.0f * dot(originToCenter, ray.direction());
    float c = dot(originToCenter, originToCenter) - radius*radius;
    float discriminant = b*b - 4*a*c;
    if(discriminant < 0)
    {
        return -1.0f;
    }
    else
    {
        return (-b -sqrt(discriminant))/(2.0f*a);
    }
}

Vector3 color(const Ray& ray)
{
    float t = hitSphere(Vector3(0.0f, 0.0f, -1.0f), 0.5f, ray);

    if(t>0.0f)
    {
        Vector3 normal = unitVector(ray.pointAtParam(t) - Vector3(0.0f, 0.0f, -1.0f));
        return 0.5f*Vector3(normal.x() + 1.0f, normal.y() + 1.0f, normal.z() + 1.0f);
    }

    Vector3 unitDirection = unitVector(ray.direction());
    t = 0.5f * (unitDirection.y() + 1.0f);
    return (1.0f - t)*Vector3(1.0f, 1.0f, 1.0f) + t*Vector3(0.5f, 0.7f, 1.0f);
}

int main()
{
    int nx = 200;
    int ny = 100;

    std::ofstream ofs;
    ofs.open("rayTraceTest.ppm");

    ofs << "P3\n" << nx << " " << ny << "\n255\n";
    Vector3 lowerLeftCorner(-2.0f, -1.0f, -1.0f);
    Vector3 horizontalVector(4.0f, 0.0f, 0.0f);
    Vector3 verticalVector(0.0f, 2.0f, 0.0f);
    Vector3 origin(0.0f, 0.0f, 0.0f);

    for(int j = ny - 1; j >= 0 ; j--)
    {
        for (int i = 0; i < nx; i++)
        {
            float u = static_cast<float>(i)/ static_cast<float>(nx);
            float v = static_cast<float>(j)/ static_cast<float>(ny);
            Ray r(origin, lowerLeftCorner + u*horizontalVector + v*verticalVector);
            Vector3 col = color(r);
            int ir = int(255.99*col.x());
            int ig = int(255.99*col.y());
            int ib = int(255.99*col.z());
            ofs << ir << " " << ig << " " << ib << "\n";
        }
    }
    ofs.close();
}