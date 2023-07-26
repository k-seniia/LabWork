#include "Sphere.h"

Sphere::Sphere(double radius, const Point3D& center) : radius(radius), center(center)
{
	if (radius < 0) {
		throw runtime_error("Radius must be a positive value.");
	}
}

double Sphere::getRadius() const
{
	return radius;
}

Point3D Sphere::getCenter() const
{
	return center;
}

void Sphere::setRadius(double radius)
{
	this->radius = radius;
}

void Sphere::setCenter(const Point3D& center)
{
	this->center = center;
}

/// <summary>
/// Збільшення радіусу на значення
/// </summary>
/// <param name="value"> значення </param>
/// <returns> сфера зі збільшеним радіусом </returns>
Sphere& Sphere::operator*(int value)
{
	radius *= value;
	return *this;
}

/// <summary>
/// Зменшення радіусу на значення
/// </summary>
/// <param name="value"> значення </param>
/// <returns> сфера зі зменшеним радіусом </returns>
Sphere& Sphere::operator/(int value)
{
	if (value == 0) {
		throw invalid_argument("Divisor cannot be zero.");
	}

	radius /= value;
	return *this;
}

/// <summary>
/// Визначення позиції точки відносно сфери
/// </summary>
/// <param name="point"> точка </param>
/// <returns> текстове пояснення позиції </returns>
string Sphere::determinePosition(const Point3D& point) const
{
	double distance = calculateDistance(point, center);

	if (distance < radius) {
		return "The point is inside the sphere.";
	}
	else if (distance > radius) {
		return "The point is outside the sphere.";
	}
	else {
		return "The point is on the surface of the sphere.";
	}
}

void Sphere::saveToFile(const string& filename) const
{
	ofstream fout(filename);

	if (!fout) {
		throw runtime_error("Error opening file for writing.");
	}

	fout << *this;

	if (!fout) {
		throw runtime_error("Error writing to file.");
	}

	fout.close();
}

bool Sphere::loadFromFile(const string& filename)
{
	ifstream fin(filename);

	if (!fin) {
		fin.close();
		throw runtime_error("Error opening file for reading.");
	}

	fin >> *this;

	if (!fin) {
		fin.close();
		throw runtime_error("Error reading from file.");
	}

	fin.close();
	return true;
}

istream& operator>>(istream& in, Sphere& sphere)
{
	try {
		cout << "Enter the center point of the sphere:\n";
		in >> sphere.center;
		while (true) {
			cout << "Enter the radius of the sphere: ";
			cin >> sphere.radius;

			if (sphere.radius <= 0) {
				throw runtime_error("Radius must be a positive value.");
			}

			break;
		}
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return in;
}

ostream& operator<<(ostream& out, const Sphere& sphere)
{
	cout << "Radius: " << sphere.radius << endl;
	cout << "Center: " << sphere.center << endl;
	return out;
}

ifstream& operator>>(ifstream& fin, Sphere& sphere)
{
	fin >> sphere.center >> sphere.radius;

	if (fin.fail()) {
		throw runtime_error("Error reading Sphere from file.");
	}
	if (sphere.radius <= 0) {
		throw runtime_error("Radius must be a positive value.");
	}

	return fin;
}

ofstream& operator<<(ofstream& fout, const Sphere& sphere)
{
	fout << sphere.center << " " << sphere.radius;
	return fout;
}
