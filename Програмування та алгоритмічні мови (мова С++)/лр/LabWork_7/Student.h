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
	string surname;		// прізвище
	string name;		// ім’я
	string patronymic;	// по-батькові
	int dateOfBirth;	// дата народження (рік)
	string address;		// адреса (місто)
	string phoneNumber;	// телефон
	string faculty;		// факультет (абревіатура)
	int course;			// курс

	/// <summary>
	/// Записує випадкові дані у бінарний файл
	/// </summary>
	void writebin();
public:
	/// <summary>
	/// Конструктор за замовчуванням
	/// </summary>
	Student();

	/// <summary>
	/// Конструктор ініціалізації
	/// </summary>
	/// <param name="surname"> - прізвище </param>
	/// <param name="name"> - ім’я </param>
	/// <param name="patronymic"> - по-батькові </param>
	/// <param name="dateOfBirth"> - дата народження (рік) </param>
	/// <param name="address"> - адреса (місто) </param>
	/// <param name="phoneNumber"> - телефон </param>
	/// <param name="faculty"> - факультет (абревіатура) </param>
	/// <param name="course"> - курс </param>
	Student(const string& surname, const string& name, const string& patronymic, const int& dateOfBirth, const string& address, const string& phoneNumber, const string& faculty, const int& course);

	/// <summary>
	/// Конструктор копіювання
	/// </summary>
	/// <param name="s"> - об'єкт, що копіюється</param>
	Student(const Student& s);


	/// <summary>
	/// Повертає прізвище студента
	/// </summary>
	/// <returns> Прізвище студента </returns>
	string get_surname()const;
	
	/// <summary>
	/// Повертає ім'я студента
	/// </summary>
	/// <returns> Ім'я студента </returns>
	string get_name()const;
	
	/// <summary>
	/// Повертає по-батькові студента
	/// </summary>
	/// <returns> По-батькові студента </returns>
	string get_patronymic()const;
	
	/// <summary>
	/// Повертає дата народження (рік) студента
	/// </summary>
	/// <returns> Дата народження (рік) студента </returns>
	int get_dateOfBirth()const;
	
	/// <summary>
	/// Повертає адреса (місто) студента
	/// </summary>
	/// <returns> Адреса (місто) студента </returns>
	string get_address()const;
	
	/// <summary>
	/// Повертає телефон студента
	/// </summary>
	/// <returns> Телефон студента </returns>
	string get_phoneNumber()const;

	/// <summary>
	/// Повертає факультет (абревіатура) студента
	/// </summary>
	/// <returns> Факультет (абревіатура) студента </returns>
	string get_faculty()const;
	
	/// <summary>
	/// Повертає курс студента
	/// </summary>
	/// <returns> Курс студента </returns>
	int get_course()const;


	/// <summary>
	/// Ініціалізація усіх даних студента
	/// </summary>
	/// <param name="surname"> - прізвище </param>
	/// <param name="name"> - ім’я </param>
	/// <param name="patronymic"> - по-батькові </param>
	/// <param name="dateOfBirth"> - дата народження (рік) </param>
	/// <param name="address"> - адреса (місто) </param>
	/// <param name="phoneNumber"> - телефон </param>
	/// <param name="faculty"> - факультет (абревіатура) </param>
	/// <param name="course"> - курс </param>
	void set_all(const string& surname, const string& name, const string& patronymic, const int& dateOfBirth, const string& address, const string& phoneNumber, const string& faculty, const int& course);
	
	/// <summary>
	/// Ініціалізація прізвища студента
	/// </summary>
	/// <param name="surname"> - прізвище </param>
	void set_surname(string surname);
	
	/// <summary>
	/// Ініціалізація імені студента
	/// </summary>
	/// <param name="name"> - ім’я </param>
	void set_name(string name);
	
	/// <summary>
	/// Ініціалізація по-батькові студента
	/// </summary>
	/// <param name="patronymic"> - по-батькові </param>
	void set_patronymic(string patronymic);
	
	/// <summary>
	/// Ініціалізація дати народження (року) студента
	/// </summary>
	/// <param name="dateOfBirth"> - дата народження (рік) </param>
	void set_dateOfBirth(int dateOfBirth);
	
	/// <summary>
	/// Ініціалізація адреси (міста) студента
	/// </summary>
	/// <param name="address"> - адреса (місто) </param>
	void set_address(string address);
	
	/// <summary>
	/// Ініціалізація телефону студента
	/// </summary>
	/// <param name="phoneNumber"> - телефон </param>
	void set_phoneNumber(string phoneNumber);
	
	/// <summary>
	/// Ініціалізація факультету (абревіатури) студента
	/// </summary>
	/// <param name="faculty"> - факультет (абревіатура) </param>
	void set_faculty(string faculty);
	
	/// <summary>
	/// Ініціалізація курсу студента
	/// </summary>
	/// <param name="course"> - курс </param>
	void set_course(int course);


	/// <summary>
	/// Виводить у консоль усі дані студента
	/// </summary>
	void show()const;


	/// <summary>
	/// Зчитує дані з бінарного файлу
	/// </summary>
	void readbin();
};

/// <summary>
/// Перелік студентів заданого факультету
/// </summary>
/// <param name="students"> - список студентів (масив) </param>
/// <param name="n"> - кількість студентів </param>
void task1(const Student* students, const int n);

/// <summary>
/// Перелік студентів для каждого факультета и курса
/// </summary>
/// <param name="students"> - список студентів (масив) </param>
/// <param name="n"> - кількість студентів </param>
void task2(const Student* students, const int n);

/// <summary>
/// Список студентів, родившихся после заданного года
/// </summary>
/// <param name="students"> - список студентів (масив) </param>
/// <param name="n"> - кількість студентів </param>
void task3(const Student* students, const int n);