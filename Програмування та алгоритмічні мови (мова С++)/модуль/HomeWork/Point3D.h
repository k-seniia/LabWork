#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <stdexcept>
using namespace std;

class Point3D
{
	double x, y, z;
public:
    Point3D(double x = 0.0, double y = 0.0, double z = 0.0);

    double getX() const;
    double getY() const;
    double getZ() const;

    friend istream& operator>>(istream& in, Point3D& point);
    friend ostream& operator<<(ostream& os, const Point3D& point);

    friend ifstream& operator>>(ifstream& fin, Point3D& point);
    friend ofstream& operator<<(ofstream& fout, const Point3D& point) {
        fout << point.x << " " << point.y << " " << point.z;
        return fout;
    }

    /// <summary>
    /// Розраховує відстань між точками за координатами
    /// </summary>
    /// <param name="point1"> перша точка </param>
    /// <param name="point2"> друга точка </param>
    /// <returns> відстань між точками </returns>
    friend double calculateDistance(const Point3D& point1, const Point3D& point2);
};