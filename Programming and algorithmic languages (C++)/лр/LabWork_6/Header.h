#pragma region Includes
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include "windows.h"
using namespace std;
#pragma endregion

struct tourist {	// ������:
	string name;	// �������
	int age;		// ��
	char gender;	// �����
};

/// <summary>
/// ����� � ����� �������� ��� �� ������ �� � ������� ����
/// </summary>
/// <param name="t"> ������ ������� </param>
/// <returns> false - � ������� ��������� ����� ��� ����������� �����
/// true - � ������� ������� ���������� </returns>
bool read_from_file(vector<tourist>& t);

/// <summary>
/// ������� � ���� �������� ��� ��� ����������
/// </summary>
void debug();

/// <summary>
/// ��������� ������� �� ��� �������
/// </summary>
/// <param name="t"> ������ ������� </param>
/// <returns> ������� �� ��� ������� </returns>
int middle_age(const vector<tourist>& t);

/// <summary>
/// ����� ���� ����� �������, �� ������ �� ������� � ������� �����
/// </summary>
/// <param name="t"> ������ ������� </param>
/// <param name="w_name"> ������� ��� ���� </param>
void woman_name(const vector<tourist>& t, vector<string>& w_name);

/// <summary>
/// ������ ���������� ��������� �������� � ���� � �������� ������
/// </summary>
/// <param name="m_age"> ������� �� ��� ������� </param>
/// <param name="w_name"> ������� ��� ���� </param>
void write_to_file(const int& m_age, const vector<string>& w_name);