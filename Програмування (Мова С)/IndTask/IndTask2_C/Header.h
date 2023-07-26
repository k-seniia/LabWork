#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG

/// <summary>
/// �������� ������ �����
/// </summary>
/// <param name="arr"> - ����� ����� </param>
/// <param name="name"> - ��'� ������ </param>
/// <returns> ����� ������ </returns>
int input(char*** arr, const char* name);

/// <summary>
/// ��������� ������ ������ ����� �� ����� ��������: 
/// ���� ����� ������� ������ ����� ���������� ����� ������� ������, 
/// �� �������� ��������� �������� ������ � ����� � ������� ������, 
/// � ��������� � ����� � ������� ������, ���� �, �� �������.
/// </summary>
/// <param name="arr1"> - ������ ����� </param>
/// <param name="arr2"> - ������ ����� </param>
/// <param name="arr3"> - ����� ����� (���������) </param>
/// <param name="n1"> - ����� ������� ������ </param>
/// <param name="n2"> - ����� ������� ������ </param>
/// <returns> ����� ������ ������ (����������) </returns>
int result(const char** arr1, const char** arr2, char*** arr3, const int n1, const int n2);

/// <summary>
/// ��������� ������ ����� � �������
/// </summary>
/// <param name="arr"> - �����, �� ����������</param>
/// <param name="n"> - ����� ������ </param>
/// <param name="name"> - ��'� ������ </param>
void printarr(const char** arr, const int n, const char* name);