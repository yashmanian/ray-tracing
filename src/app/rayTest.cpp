//
// Created by yashmanian on 8/17/19.
//
#include <iostream>
#include <fstream>
#include "Vector3.h"

int main()
{
    int nx = 200;
    int ny = 100;

    std::ofstream ofs;
    ofs.open("../rayTraceTest.ppm");

    ofs << "P3\n" << nx << " " << ny << "\n255\n";

    for(int j = ny - 1; j >= 0 ; j--)
    {
        for (int i = 0; i < nx; i++)
        {
            Vector3 col(float(i)/float(nx), float(j)/float(ny), 0.2);
            int ir = int(255.99*col.x());
            int ig = int(255.99*col.y());
            int ib = int(255.99*col.z());
            ofs << ir << " " << ig << " " << ib << "\n";
        }
    }
    ofs.close();
}