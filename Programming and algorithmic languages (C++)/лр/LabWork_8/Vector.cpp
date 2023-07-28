#include "Vector.h"

Vector::Vector() :x(0), y(0), z(0) {}

Vector::Vector(const double& _x, const double& _y, const double& _z) :x(_x), y(_y), z(_z) {}

Vector& Vector::operator+=(const Vector& v)
{
	x += v.x; y += v.y; z += v.z;
	return *this;
}

Vector& Vector::operator-=(const Vector& v)
{
	x -= v.x; y -= v.y; z -= v.z;
	return *this;
}

Vector& Vector::operator*=(const Vector& v)
{
	x *= v.x; y *= v.y; z *= v.z;
	return *this;
}

Vector operator+(const Vector& v1, const Vector& v2)
{
	return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector operator-(const Vector& v1, const Vector& v2)
{
	return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector operator*(const double& d, const Vector& v)
{
	return Vector(v.x * d, v.y * d, v.z * d);
}

Vector operator*(const Vector& v, const double& d)
{
	return Vector(v.x * d, v.y * d, v.z * d);
}

double operator*(const Vector& v1, const Vector& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

double lenght(const Vector& v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double angel(const Vector& v1, const Vector& v2)
{
	return acos((v1 * v2) / (lenght(v1) * lenght(v2)));
}

Vector operator^(const Vector& v1, const Vector& v2)
{
	return Vector(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

double x(const Vector& v) { return v.x; }

double y(const Vector& v) { return v.y; }

double z(const Vector& v) { return v.z; }

istream& operator>>(istream& in, Vector& v)
{
	cout << "x -> "; in >> v.x;
	cout << "y -> "; in >> v.y;
	cout << "z -> "; in >> v.z;
	return in;
}

ostream& operator<<(ostream& out, Vector& v)
{
	out << "( " << v.x << " , " << v.y << " , " << v.z << " )";
	return out;
}