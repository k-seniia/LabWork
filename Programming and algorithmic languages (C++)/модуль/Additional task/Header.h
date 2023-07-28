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

/// <summary>
/// ����� ����� � ���-�����
/// </summary>
/// <param name="log"> - ����� ��� ��������� ����� </param>
/// <returns> false - � ������� ��������� �����
/// true - � ������� ������� ���������� </returns>
bool read_from_file(vector<string>& log);

/// <summary>
/// �������� �����, ��������� ��������
/// </summary>
/// <param name="log"> - ����� ��� ��������� ����� </param>
void dupli(vector<string>& log);

/// <summary>
/// ������ ����� � ���� ��� ��������
/// </summary>
/// <param name="log"> - ����� ��� ��������� ����� </param>
void write_to_file(const vector<string>& log);