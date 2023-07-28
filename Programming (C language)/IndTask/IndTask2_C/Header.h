#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG

/// <summary>
/// введення масиву рядків
/// </summary>
/// <param name="arr"> - масив рядків </param>
/// <param name="name"> - ім'я масиву </param>
/// <returns> розмір масиву </returns>
int input(char*** arr, const char* name);

/// <summary>
/// Створення нового масиву рядків за таким правилом: 
/// якщо рядок першого масиву більше відповідного рядка другого масиву, 
/// то поточним елементом третього масиву є рядок з першого масиву, 
/// а наступним – рядок з другого масиву, якщо ні, то навпаки.
/// </summary>
/// <param name="arr1"> - перший масив </param>
/// <param name="arr2"> - другий масив </param>
/// <param name="arr3"> - новий масив (результат) </param>
/// <param name="n1"> - розмір першого масиву </param>
/// <param name="n2"> - розмір другого масиву </param>
/// <returns> розмір нового масиву (результату) </returns>
int result(const char** arr1, const char** arr2, char*** arr3, const int n1, const int n2);

/// <summary>
/// виведення масиву рядків у консоль
/// </summary>
/// <param name="arr"> - масив, що виводиться</param>
/// <param name="n"> - розмір масиву </param>
/// <param name="name"> - ім'я масиву </param>
void printarr(const char** arr, const int n, const char* name);