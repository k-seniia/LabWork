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

struct tourist {	// Турист:
	string name;	// прізвище
	int age;		// вік
	char gender;	// стать
};

/// <summary>
/// зчитує з файлу необхідні дані та записує їх у відповідні змінні
/// </summary>
/// <param name="t"> перелік туристів </param>
/// <returns> false - у випадку відсутності файлу або некоректних даних
/// true - у випадку вдалого зчитування </returns>
bool read_from_file(vector<tourist>& t);

/// <summary>
/// вносить у файл необхідні дані для тестування
/// </summary>
void debug();

/// <summary>
/// розраховує середній вік всіх туристів
/// </summary>
/// <param name="t"> перелік туристів </param>
/// <returns> середній вік всіх туристів </returns>
int middle_age(const vector<tourist>& t);

/// <summary>
/// обирає жінок черед туристів, та записує їх прізвища у окремий масив
/// </summary>
/// <param name="t"> перелік туристів </param>
/// <param name="w_name"> прізвища всіх жінок </param>
void woman_name(const vector<tourist>& t, vector<string>& w_name);

/// <summary>
/// записує результати виконання програми у файл у бінарному вигляді
/// </summary>
/// <param name="m_age"> середній вік всіх туристів </param>
/// <param name="w_name"> прізвища всіх жінок </param>
void write_to_file(const int& m_age, const vector<string>& w_name);