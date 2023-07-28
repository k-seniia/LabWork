#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Phone
{
	string m_surname;			// Прізвище
	string m_firstName;			// Ім'я
	string m_middleName;		// По-батькові
	string m_address;			// Адреса
	string m_number;			// Номер
	int m_localCallTime;		// Час внутрішньо міських розмов
	int m_longDistanceCallTime;	// Час міжміських розмов
public:
	/// <summary>
	/// Конструктор за замовчуванням
	/// </summary>
	Phone();
	
	/// <summary>
	/// Конструктор з параметрами
	/// </summary>
	/// <param name="surname"> Прізвище </param>
	/// <param name="firstName"> Ім'я </param>
	/// <param name="middleName"> По-батькові </param>
	/// <param name="address"> Адреса </param>
	/// <param name="number"> Номер </param>
	/// <param name="localCallTime"> Час внутрішньо міських розмов </param>
	/// <param name="longDistanceCallTime"> Час міжміських розмов </param>
	Phone(const string& surname, const string& firstName, const string& middleName,
		const string& address, const string& number, int localCallTime, int longDistanceCallTime);

	/// <summary>
	/// Повертає Прізвище, Ім'я, По-батькові
	/// </summary>
	/// <returns> Прізвище, Ім'я, По-батькові </returns>
	string getFullName() const;

	/// <summary>
	/// Повертає Адресу
	/// </summary>
	/// <returns> Адреса </returns>
	string getAddress() const;

	/// <summary>
	/// Повертає Номер
	/// </summary>
	/// <returns> Номер </returns>
	string getNumber() const;

	/// <summary>
	/// Повертає Час внутрішньо міських розмов
	/// </summary>
	/// <returns> Час внутрішньо міських розмов </returns>
	int getLocalCallTime() const;

	/// <summary>
	/// Повертає Час міжміських розмов
	/// </summary>
	/// <returns> Час міжміських розмов </returns>
	int getLongDistanceCallTime() const;

	/// <summary>
	/// Перевантаження оператора введення
	/// </summary>
	/// <param name="is"> Оператор введення </param>
	/// <param name="phone"> Абонент </param>
	/// <returns> Оператор введення </returns>
	friend istream& operator>>(istream& in, Phone& phone);

	/// <summary>
	/// Перевантаження оператора виведення
	/// </summary>
	/// <param name="os"> Оператор виведення </param>
	/// <param name="phone"> Абонент </param>
	/// <returns> Оператор виведення </returns>
	friend ostream& operator<<(ostream& out, const Phone& phone);

	/// <summary>
	/// Функція для генерації випадкових значень
	/// </summary>
	void generateRandomData();
};