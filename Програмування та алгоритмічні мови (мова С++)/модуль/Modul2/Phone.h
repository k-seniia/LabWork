#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Phone
{
	string m_surname;			// �������
	string m_firstName;			// ��'�
	string m_middleName;		// ��-�������
	string m_address;			// ������
	string m_number;			// �����
	int m_localCallTime;		// ��� ��������� ������ ������
	int m_longDistanceCallTime;	// ��� �������� ������
public:
	/// <summary>
	/// ����������� �� �������������
	/// </summary>
	Phone();
	
	/// <summary>
	/// ����������� � �����������
	/// </summary>
	/// <param name="surname"> ������� </param>
	/// <param name="firstName"> ��'� </param>
	/// <param name="middleName"> ��-������� </param>
	/// <param name="address"> ������ </param>
	/// <param name="number"> ����� </param>
	/// <param name="localCallTime"> ��� ��������� ������ ������ </param>
	/// <param name="longDistanceCallTime"> ��� �������� ������ </param>
	Phone(const string& surname, const string& firstName, const string& middleName,
		const string& address, const string& number, int localCallTime, int longDistanceCallTime);

	/// <summary>
	/// ������� �������, ��'�, ��-�������
	/// </summary>
	/// <returns> �������, ��'�, ��-������� </returns>
	string getFullName() const;

	/// <summary>
	/// ������� ������
	/// </summary>
	/// <returns> ������ </returns>
	string getAddress() const;

	/// <summary>
	/// ������� �����
	/// </summary>
	/// <returns> ����� </returns>
	string getNumber() const;

	/// <summary>
	/// ������� ��� ��������� ������ ������
	/// </summary>
	/// <returns> ��� ��������� ������ ������ </returns>
	int getLocalCallTime() const;

	/// <summary>
	/// ������� ��� �������� ������
	/// </summary>
	/// <returns> ��� �������� ������ </returns>
	int getLongDistanceCallTime() const;

	/// <summary>
	/// �������������� ��������� ��������
	/// </summary>
	/// <param name="is"> �������� �������� </param>
	/// <param name="phone"> ������� </param>
	/// <returns> �������� �������� </returns>
	friend istream& operator>>(istream& in, Phone& phone);

	/// <summary>
	/// �������������� ��������� ���������
	/// </summary>
	/// <param name="os"> �������� ��������� </param>
	/// <param name="phone"> ������� </param>
	/// <returns> �������� ��������� </returns>
	friend ostream& operator<<(ostream& out, const Phone& phone);

	/// <summary>
	/// ������� ��� ��������� ���������� �������
	/// </summary>
	void generateRandomData();
};