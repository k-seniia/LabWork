#pragma once
#pragma region Includes
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <locale>
#include "windows.h"
using namespace std;
#pragma endregion

class Student {
	string surname;		// �������
	string name;		// ���
	string patronymic;	// ��-�������
	int dateOfBirth;	// ���� ���������� (��)
	string address;		// ������ (����)
	string phoneNumber;	// �������
	string faculty;		// ��������� (����������)
	int course;			// ����

	/// <summary>
	/// ������ �������� ��� � ������� ����
	/// </summary>
	void writebin();
public:
	/// <summary>
	/// ����������� �� �������������
	/// </summary>
	Student();

	/// <summary>
	/// ����������� �����������
	/// </summary>
	/// <param name="surname"> - ������� </param>
	/// <param name="name"> - ��� </param>
	/// <param name="patronymic"> - ��-������� </param>
	/// <param name="dateOfBirth"> - ���� ���������� (��) </param>
	/// <param name="address"> - ������ (����) </param>
	/// <param name="phoneNumber"> - ������� </param>
	/// <param name="faculty"> - ��������� (����������) </param>
	/// <param name="course"> - ���� </param>
	Student(const string& surname, const string& name, const string& patronymic, const int& dateOfBirth, const string& address, const string& phoneNumber, const string& faculty, const int& course);

	/// <summary>
	/// ����������� ���������
	/// </summary>
	/// <param name="s"> - ��'���, �� ���������</param>
	Student(const Student& s);


	/// <summary>
	/// ������� ������� ��������
	/// </summary>
	/// <returns> ������� �������� </returns>
	string get_surname()const;
	
	/// <summary>
	/// ������� ��'� ��������
	/// </summary>
	/// <returns> ��'� �������� </returns>
	string get_name()const;
	
	/// <summary>
	/// ������� ��-������� ��������
	/// </summary>
	/// <returns> ��-������� �������� </returns>
	string get_patronymic()const;
	
	/// <summary>
	/// ������� ���� ���������� (��) ��������
	/// </summary>
	/// <returns> ���� ���������� (��) �������� </returns>
	int get_dateOfBirth()const;
	
	/// <summary>
	/// ������� ������ (����) ��������
	/// </summary>
	/// <returns> ������ (����) �������� </returns>
	string get_address()const;
	
	/// <summary>
	/// ������� ������� ��������
	/// </summary>
	/// <returns> ������� �������� </returns>
	string get_phoneNumber()const;

	/// <summary>
	/// ������� ��������� (����������) ��������
	/// </summary>
	/// <returns> ��������� (����������) �������� </returns>
	string get_faculty()const;
	
	/// <summary>
	/// ������� ���� ��������
	/// </summary>
	/// <returns> ���� �������� </returns>
	int get_course()const;


	/// <summary>
	/// ����������� ��� ����� ��������
	/// </summary>
	/// <param name="surname"> - ������� </param>
	/// <param name="name"> - ��� </param>
	/// <param name="patronymic"> - ��-������� </param>
	/// <param name="dateOfBirth"> - ���� ���������� (��) </param>
	/// <param name="address"> - ������ (����) </param>
	/// <param name="phoneNumber"> - ������� </param>
	/// <param name="faculty"> - ��������� (����������) </param>
	/// <param name="course"> - ���� </param>
	void set_all(const string& surname, const string& name, const string& patronymic, const int& dateOfBirth, const string& address, const string& phoneNumber, const string& faculty, const int& course);
	
	/// <summary>
	/// ����������� ������� ��������
	/// </summary>
	/// <param name="surname"> - ������� </param>
	void set_surname(string surname);
	
	/// <summary>
	/// ����������� ���� ��������
	/// </summary>
	/// <param name="name"> - ��� </param>
	void set_name(string name);
	
	/// <summary>
	/// ����������� ��-������� ��������
	/// </summary>
	/// <param name="patronymic"> - ��-������� </param>
	void set_patronymic(string patronymic);
	
	/// <summary>
	/// ����������� ���� ���������� (����) ��������
	/// </summary>
	/// <param name="dateOfBirth"> - ���� ���������� (��) </param>
	void set_dateOfBirth(int dateOfBirth);
	
	/// <summary>
	/// ����������� ������ (����) ��������
	/// </summary>
	/// <param name="address"> - ������ (����) </param>
	void set_address(string address);
	
	/// <summary>
	/// ����������� �������� ��������
	/// </summary>
	/// <param name="phoneNumber"> - ������� </param>
	void set_phoneNumber(string phoneNumber);
	
	/// <summary>
	/// ����������� ���������� (����������) ��������
	/// </summary>
	/// <param name="faculty"> - ��������� (����������) </param>
	void set_faculty(string faculty);
	
	/// <summary>
	/// ����������� ����� ��������
	/// </summary>
	/// <param name="course"> - ���� </param>
	void set_course(int course);


	/// <summary>
	/// �������� � ������� �� ��� ��������
	/// </summary>
	void show()const;


	/// <summary>
	/// ����� ��� � �������� �����
	/// </summary>
	void readbin();
};

/// <summary>
/// ������ �������� �������� ����������
/// </summary>
/// <param name="students"> - ������ �������� (�����) </param>
/// <param name="n"> - ������� �������� </param>
void task1(const Student* students, const int n);

/// <summary>
/// ������ �������� ��� ������� ���������� � �����
/// </summary>
/// <param name="students"> - ������ �������� (�����) </param>
/// <param name="n"> - ������� �������� </param>
void task2(const Student* students, const int n);

/// <summary>
/// ������ ��������, ���������� ����� ��������� ����
/// </summary>
/// <param name="students"> - ������ �������� (�����) </param>
/// <param name="n"> - ������� �������� </param>
void task3(const Student* students, const int n);