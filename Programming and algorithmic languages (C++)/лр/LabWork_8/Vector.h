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
	double x, y, z; // ����������
public:
	/// <summary>
	/// ����������� �� �������������
	/// </summary>
	Vector();
	
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	/// <param name="_x"> - ���������a x </param>
	/// <param name="_y"> - ���������a y </param>
	/// <param name="_z"> - ���������a z </param>
	Vector(const double& _x, const double& _y, const double& _z);
	
	// ���������-�����
	
	/// <summary>
	/// �������������� ��������� +=
	/// </summary>
	/// <param name="v"> - ��'���, �� �������� </param>
	/// <returns> ��������� �� ��'���, �� � ����������� �������� += </returns>
	Vector& operator+=(const Vector& v);
	
	/// <summary>
	/// �������������� ��������� -=
	/// </summary>
	/// <param name="v"> - ��'���, �� ��������� </param>
	/// <returns> ��������� �� ��'���, �� � ����������� �������� -= </returns>
	Vector& operator-=(const Vector& v);
	
	/// <summary>
	/// �������������� ��������� *=
	/// </summary>
	/// <param name="v"> - ��'���, �� ���� ��������� </param>
	/// <returns> ��������� �� ��'���, �� � ����������� �������� *= </returns>
	Vector& operator*=(const Vector& v);
	
	// ���������-����
	
	/// <summary>
	/// ������ ������� �������������� ��������� +
	/// </summary>
	/// <param name="v1"> - ���� ������� </param>
	/// <param name="v2"> - ������ ������� </param>
	/// <returns> ��'���, �� � ����������� �������� ��������� </returns>
	friend Vector operator+(const Vector& v1, const Vector& v2);
	
	/// <summary>
	/// ������ ������� �������������� ��������� -
	/// </summary>
	/// <param name="v1"> - ���� ������� </param>
	/// <param name="v2"> - ������ ������� </param>
	/// <returns> ��'���, �� � ����������� �������� �������� </returns>
	friend Vector operator-(const Vector& v1, const Vector& v2);
	
	/// <summary>
	/// ������ ������� �������������� ��������� *
	/// </summary>
	/// <param name="d"> - �����, �� ��� ��������� ��'��� </param>
	/// <param name="v"> - ��'��� </param>
	/// <returns> ��'���, �� � ����������� �������� �������� �� ����� </returns>
	friend Vector operator*(const double& d, const Vector& v);
	
	/// <summary>
	/// ������ ������� �������������� ��������� *
	/// </summary>
	/// <param name="v"> - ��'��� </param>
	/// <param name="d"> - �����, �� ��� ��������� ��'��� </param>
	/// <returns> ��'���, �� � ����������� �������� �������� �� ����� </returns>
	friend Vector operator*(const Vector& v, const double& d);


	/// <summary>
	/// ��������� �������
	/// </summary>
	/// <param name="v1"> - ���� ������� </param>
	/// <param name="v2"> - ������ ������� </param>
	/// <returns> ��������� ������� </returns>
	friend double operator*(const Vector& v1, const Vector& v2);

	
	/// <summary>
	/// ������� �������
	/// </summary>
	/// <param name="v"> - ��'��� </param>
	/// <returns> ������� ������� </returns>
	friend double lenght(const Vector& v);


	/// <summary>
	/// ��� �� ����� ���������
	/// </summary>
	/// <param name="v1"> - ���� ������� </param>
	/// <param name="v2"> - ������ ������� </param>
	/// <returns> ��� �� ����� ��������� </returns>
	friend double angel(const Vector& v1, const Vector& v2);

	
	/// <summary>
	/// ��������� ������� ���� �������
	/// </summary>
	/// <param name="v1"> - ���� ������� </param>
	/// <param name="v2"> - ������ ������� </param>
	/// <returns> ��������� ������� ���� ������� </returns>
	friend Vector operator ^(const Vector& v1, const Vector& v2);
	
	// ���������� �������

	/// <summary>
	/// ���������a x
	/// </summary>
	/// <param name="v"> - ��'��� </param>
	/// <returns> ���������a x </returns>
	friend double x(const Vector& v);
	
	/// <summary>
	/// ���������a y
	/// </summary>
	/// <param name="v"> - ��'��� </param>
	/// <returns> ���������a y </returns>
	friend double y(const Vector& v);
	
	/// <summary>
	/// ���������a z
	/// </summary>
	/// <param name="v"> - ��'��� </param>
	/// <returns> ���������a z </returns>
	friend double z(const Vector& v);
	
	// ��������� ��������-���������
	
	/// <summary>
	/// �������������� ��������� >>
	/// </summary>
	/// <param name="in"> - �������� �������� </param>
	/// <param name="v"> - ��'��� </param>
	/// <returns> ��������� �������� </returns>
	friend istream& operator>>(istream& in, Vector& v);
	
	/// <summary>
	/// �������������� ��������� <<
	/// </summary>
	/// <param name="out"> - �������� ��������� </param>
	/// <param name="v"> - ��'��� </param>
	/// <returns> ��������� ��������� </returns>
	friend ostream& operator<<(ostream& out, Vector& v);
};