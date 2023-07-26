#pragma once
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
using namespace std;

struct Point {
	int x, y;

	// �����������
	Point(int x, int y);

	// �������������� ��������� ���������
	friend ostream& operator<<(ostream& out, const Point& p);
};

class Square
{
	Point p1, p2;	// ��������� ����� ��������

	/// <summary>
	/// ���������� ����� ��������
	/// </summary>
	/// <returns> ����� �������� </returns>
	int area() const;
public:
	// ������������
	Square();
	Square(const int& x1, const int& y1, const int& x2, const int& y2);
	Square(const Square& sq);

	// �������������� ��������� ��������-���������
	friend ostream& operator<<(ostream& out, const Square& sq);
	friend istream& operator>>(istream& in, Square& sq);

	/// <summary>
	/// ��������� ������� ������� ��������
	/// </summary>
	/// <returns> ������� ������� �������� </returns>
	double diagonal() const;
	
	/// <summary>
	/// ��������� �������� ���������� ����� �ᒺ���, ��������� �� ������� ���������
	/// </summary>
	/// <returns> ��������� ����� �� ������� ��������� </returns>
	Point closest() const;

	//�������������� ������� ���������, �������� ����������� �� ������
	friend bool operator==(const Square& sq1, const Square& sq2);
	friend bool operator!=(const Square& sq1, const Square& sq2);
	friend bool operator<(const Square& sq1, const Square& sq2);
	friend bool operator<=(const Square& sq1, const Square& sq2);
	friend bool operator>(const Square& sq1, const Square& sq2);
	friend bool operator>=(const Square& sq1, const Square& sq2);
};

// ���� ���������
class NonSquare :public exception {
public:
	/// <summary>
	/// ������ ����� �������
	/// </summary>
	/// <returns> ����� � ������� ������� </returns>
	const char* what() const noexcept;
};