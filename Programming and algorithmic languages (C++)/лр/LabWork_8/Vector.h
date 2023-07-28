#pragma once
#pragma region Includes
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <locale>
#include "windows.h"
using namespace std;
#pragma endregion

class Vector
{
	double x, y, z; // координати
public:
	/// <summary>
	/// конструктор за замовчуванням
	/// </summary>
	Vector();
	
	/// <summary>
	/// конструктор по елементам
	/// </summary>
	/// <param name="_x"> - координатa x </param>
	/// <param name="_y"> - координатa y </param>
	/// <param name="_z"> - координатa z </param>
	Vector(const double& _x, const double& _y, const double& _z);
	
	// оператори-члени
	
	/// <summary>
	/// перевантаження оператора +=
	/// </summary>
	/// <param name="v"> - об'єкт, що додається </param>
	/// <returns> посилання на об'єкт, що є результатом операції += </returns>
	Vector& operator+=(const Vector& v);
	
	/// <summary>
	/// перевантаження оператора -=
	/// </summary>
	/// <param name="v"> - об'єкт, що віднімається </param>
	/// <returns> посилання на об'єкт, що є результатом операції -= </returns>
	Vector& operator-=(const Vector& v);
	
	/// <summary>
	/// перевантаження оператора *=
	/// </summary>
	/// <param name="v"> - об'єкт, на який множиться </param>
	/// <returns> посилання на об'єкт, що є результатом операції *= </returns>
	Vector& operator*=(const Vector& v);
	
	// оператори-друзі
	
	/// <summary>
	/// дружня функція перевантаження оператора +
	/// </summary>
	/// <param name="v1"> - лівий операнд </param>
	/// <param name="v2"> - правий операнд </param>
	/// <returns> об'єкт, що є результатом операції додавання </returns>
	friend Vector operator+(const Vector& v1, const Vector& v2);
	
	/// <summary>
	/// дружня функція перевантаження оператора -
	/// </summary>
	/// <param name="v1"> - лівий операнд </param>
	/// <param name="v2"> - правий операнд </param>
	/// <returns> об'єкт, що є результатом операції віднімання </returns>
	friend Vector operator-(const Vector& v1, const Vector& v2);
	
	/// <summary>
	/// дружня функція перевантаження оператора *
	/// </summary>
	/// <param name="d"> - число, на яке множиться об'єкт </param>
	/// <param name="v"> - об'єкт </param>
	/// <returns> об'єкт, що є результатом операції множення на число </returns>
	friend Vector operator*(const double& d, const Vector& v);
	
	/// <summary>
	/// дружня функція перевантаження оператора *
	/// </summary>
	/// <param name="v"> - об'єкт </param>
	/// <param name="d"> - число, на яке множиться об'єкт </param>
	/// <returns> об'єкт, що є результатом операції множення на число </returns>
	friend Vector operator*(const Vector& v, const double& d);


	/// <summary>
	/// скалярний добуток
	/// </summary>
	/// <param name="v1"> - лівий операнд </param>
	/// <param name="v2"> - правий операнд </param>
	/// <returns> скалярний добуток </returns>
	friend double operator*(const Vector& v1, const Vector& v2);

	
	/// <summary>
	/// довжина вектору
	/// </summary>
	/// <param name="v"> - об'єкт </param>
	/// <returns> довжина вектору </returns>
	friend double lenght(const Vector& v);


	/// <summary>
	/// кут між двома векторами
	/// </summary>
	/// <param name="v1"> - лівий операнд </param>
	/// <param name="v2"> - правий операнд </param>
	/// <returns> кут між двома векторами </returns>
	friend double angel(const Vector& v1, const Vector& v2);

	
	/// <summary>
	/// векторний добуток двох векторів
	/// </summary>
	/// <param name="v1"> - лівий операнд </param>
	/// <param name="v2"> - правий операнд </param>
	/// <returns> векторний добуток двох векторів </returns>
	friend Vector operator ^(const Vector& v1, const Vector& v2);
	
	// координати вектору

	/// <summary>
	/// координатa x
	/// </summary>
	/// <param name="v"> - об'єкт </param>
	/// <returns> координатa x </returns>
	friend double x(const Vector& v);
	
	/// <summary>
	/// координатa y
	/// </summary>
	/// <param name="v"> - об'єкт </param>
	/// <returns> координатa y </returns>
	friend double y(const Vector& v);
	
	/// <summary>
	/// координатa z
	/// </summary>
	/// <param name="v"> - об'єкт </param>
	/// <returns> координатa z </returns>
	friend double z(const Vector& v);
	
	// оператори введення-виведення
	
	/// <summary>
	/// перевантаження оператора >>
	/// </summary>
	/// <param name="in"> - оператор введення </param>
	/// <param name="v"> - об'єкт </param>
	/// <returns> результат введення </returns>
	friend istream& operator>>(istream& in, Vector& v);
	
	/// <summary>
	/// перевантаження оператора <<
	/// </summary>
	/// <param name="out"> - оператор виведення </param>
	/// <param name="v"> - об'єкт </param>
	/// <returns> результат виведення </returns>
	friend ostream& operator<<(ostream& out, Vector& v);
};