#pragma once
#include "Point3D.h"

class Sphere
{
	double radius;
	Point3D center;
public:
	Sphere(double radius = 0.0, const Point3D& center = Point3D());

	double getRadius() const;
	Point3D getCenter() const;

	void setRadius(double radius);
	void setCenter(const Point3D& center);

	Sphere& operator*(int value);
	Sphere& operator/(int value);

	/// <summary>
	/// Перевіряє, де відносно сфери знаходиться задана точка
	/// </summary>
	/// <param name="point"> задана точка </param>
	/// <returns> текстовий результат положення </returns>
	string determinePosition(const Point3D& point) const;

	void saveToFile(const string& filename) const;
	bool loadFromFile(const string& filename);

	friend istream& operator>>(istream& in, Sphere& sphere);
	friend ostream& operator<<(ostream& out, const Sphere& sphere);

	friend ifstream& operator>>(ifstream& fin, Sphere& sphere);
	friend ofstream& operator<<(ofstream& fout, const Sphere& sphere);
};