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
	virtual double perimeter() const = 0; // �������� 
	virtual double area() const = 0; // �������
};

/// <summary>
/// ������� ��� ��������� ������� �� ��������� ��'���� ���� Area
/// </summary>
/// <param name="obj"> ��'��� ��� ����� ����� ������� ������� �� ��������� </param>
void printAreaInfo(const Area& obj);