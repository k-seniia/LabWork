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
/// зчитує рядки з лог-файлу
/// </summary>
/// <param name="log"> - масив для зберігання рядків </param>
/// <returns> false - у випадку відсутності файлу
/// true - у випадку вдалого зчитування </returns>
bool read_from_file(vector<string>& log);

/// <summary>
/// перебирає масив, видаляючи дублікати
/// </summary>
/// <param name="log"> - масив для зберігання рядків </param>
void dupli(vector<string>& log);

/// <summary>
/// записує рядки у файл без дублікатів
/// </summary>
/// <param name="log"> - масив для зберігання рядків </param>
void write_to_file(const vector<string>& log);