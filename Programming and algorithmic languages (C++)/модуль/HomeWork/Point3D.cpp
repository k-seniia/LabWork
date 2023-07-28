#include "Point3D.h"

Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z)
{
}

double Point3D::getX() const
{
	return x;
}

double Point3D::getY() const
{
	return y;
}

double Point3D::getZ() const
{
	return z;
}

istream& operator>>(istream& in, Point3D& point)
{
    cout << "Enter the x-coordinate: "; in >> point.x;
    cout << "Enter the y-coordinate: "; in >> point.y;
    cout << "Enter the z-coordinate: "; in >> point.z;

    if (in.fail()) {
        throw runtime_error("Invalid input for Point3D coordinates.");
    }

    return in;
}

ostream& operator<<(ostream& os, const Point3D& point)
{
    os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
    return os;
}

ifstream& operator>>(ifstream& fin, Point3D& point)
{
    fin >> point.x >> point.y >> point.z;

    if (fin.fail()) {
        throw runtime_error("Error reading Point3D coordinates from file.");
    }

    return fin;
}

//ofstream& operator<<(ofstream& fout, const Point3D& point)
//{
//    fout << point.x << " " << point.y << " " << point.z;
//    return fout;
//}

/// <summary>
/// Розрахунок відстані між точками
/// </summary>
/// <param name="point1"> точка </param>
/// <param name="point2"> точка </param>
/// <returns> відстань між точками </returns>
double calculateDistance(const Point3D& point1, const Point3D& point2)
{
    double dx = point1.getX() - point2.getX();
    double dy = point1.getY() - point2.getY();
    double dz = point1.getZ() - point2.getZ();
    return sqrt(dx * dx + dy * dy + dz * dz);
}
