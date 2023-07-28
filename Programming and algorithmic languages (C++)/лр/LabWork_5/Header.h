#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define DEBUG

/// <summary>
/// 1. � ��������� ��������� ��������� �����. ������� ��������, ��� �������� ������� ���, 
/// �� ����� ������� �������; �������� �� ����� ������� ����� �����
/// </summary>
void task1();

/// <summary>
/// ����� ����� buf � �����
/// </summary>
/// <param name="buf"> - �����, � ���� ��������� ����� � ����� </param>
/// <returns> false - � ������� ��������� �����
/// true - � ������� ������� ���������� </returns>
bool read_from_file_task1(string& buf);

/// <summary>
/// �������� ������� ���, �� ����� ������� �������; 
/// �������� ������� ����� �����
/// </summary>
/// <param name="buf"> - ����� � �������� ������ </param>
/// <param name="count"> - ������� ���, �� ����� ������� ������� </param>
/// <param name="let"> - ����� � ����� </param>
/// <param name="num"> - ������� ������� ����� ����� � ����� </param>
/// <param name="n"> - ������� ���� � ����� </param>
void do_task1(string& buf, int& count, char let[], int num[], int& n);

/// <summary>
/// ����� ����� � ���������� �������
/// </summary>
/// <param name="let"> - ����� � ����� </param>
/// <param name="num"> - ������� ������� ����� ����� � ����� </param>
/// <param name="n"> - ������� ���� � ����� </param>
void sort(char* let, int* num, const int& n);

/// <summary>
/// ������ ��������� ��������� �� �����
/// </summary>
/// <param name="count"> - ������� ���, �� ����� ������� ������� </param>
/// <param name="let"> - ����� � ����� </param>
/// <param name="num"> - ������� ������� ����� ����� � ����� </param>
/// <param name="n"> - ������� ���� � ����� </param>
void write_to_file_task1(const int& count, const char* let, const int* num, const int& n);

/// <summary>
/// ������ � ���� ����� ���������� ���� ��������� ��������
/// </summary>
void debug_file_task1();

/// <summary>
/// 2. ��������� � ��������� ��� � ������ ��:��� ��������� 12: 11.
/// �������� ����� ��� ������� : ���������� ������ ���������� ������.
/// ����� ���������� ��������� �������� � �ᑺ�� ���� string.
/// </summary>
void task2();

/// <summary>
/// ����� ����� buf � �����
/// </summary>
/// <param name="buf"> - �����, � ���� ��������� ����� � ����� </param>
/// <returns> false - � ������� ��������� �����
/// true - � ������� ������� ���������� </returns>
bool read_from_file_task2(string& buf);

/// <summary>
/// ������ �� ���������� � ������������� ��� ������� �� �������
/// </summary>
/// <param name="buf"> - ����� � �������� ������ </param>
/// <returns> ����� � ����� � ���������� ������ </returns>
string do_task2(const string& buf);

/// <summary>
/// ���������� � �������������� ���� � �����, � ��������� ��������� ��/���
/// </summary>
/// <param name="mm"> - ������� </param>
/// <param name="ss"> - ������� </param>
/// <returns> ����� � ����� � ���������� ������ </returns>
string do_string(const int& mm, const int& ss);

/// <summary>
/// ������ ��������� ��������� �� �����
/// </summary>
/// <param name="time"> - ����� � ����� � ���������� ������ </param>
void write_to_file_task2(const string& time);

/// <summary>
/// ������ � ���� �������� ��� ��/���
/// </summary>
void debug_file_task2();