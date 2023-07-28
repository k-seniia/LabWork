#pragma once
#pragma region Includes
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
using namespace std;
#pragma endregion
#define M_PI 3.14159265358979323846
#define _DEBUG

class Area
{
public:
	virtual ~Area() {} 
	virtual double perimeter() const = 0; // периметр 
	virtual double area() const = 0; // площина
};

/// <summary>
/// Функція для виведення площини та периметру об'єкта типу Area
/// </summary>
/// <param name="obj"> об'єкт для якого треба вивести площини та периметру </param>
void printAreaInfo(const Area& obj);