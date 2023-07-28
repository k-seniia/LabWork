#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define DEBUG

/// <summary>
/// 1. З клавіатури вводиться текстовий рядок. Скласти програму, яка підраховує кількість слів, 
/// які мають непарну довжину; виводить на екран частоту кожної літери
/// </summary>
void task1();

/// <summary>
/// зчитує рядок buf з файлу
/// </summary>
/// <param name="buf"> - рядок, у який зчитується текст з файлу </param>
/// <returns> false - у випадку відсутності файлу
/// true - у випадку вдалого зчитування </returns>
bool read_from_file_task1(string& buf);

/// <summary>
/// підраховує кількість слів, які мають непарну довжину; 
/// підраховує частоту кожної літери
/// </summary>
/// <param name="buf"> - рядок з вхідними даними </param>
/// <param name="count"> - кількість слів, які мають непарну довжину </param>
/// <param name="let"> - літери у рядку </param>
/// <param name="num"> - кількість повторів кожної літери у рядку </param>
/// <param name="n"> - кількість літер у рядку </param>
void do_task1(string& buf, int& count, char let[], int num[], int& n);

/// <summary>
/// сортує літери у алфавітному порядку
/// </summary>
/// <param name="let"> - літери у рядку </param>
/// <param name="num"> - кількість повторів кожної літери у рядку </param>
/// <param name="n"> - кількість літер у рядку </param>
void sort(char* let, int* num, const int& n);

/// <summary>
/// записує результат виконання до файлу
/// </summary>
/// <param name="count"> - кількість слів, які мають непарну довжину </param>
/// <param name="let"> - літери у рядку </param>
/// <param name="num"> - кількість повторів кожної літери у рядку </param>
/// <param name="n"> - кількість літер у рядку </param>
void write_to_file_task1(const int& count, const char* let, const int* num, const int& n);

/// <summary>
/// записує у файл групи випадкових літер випадкової величини
/// </summary>
void debug_file_task1();

/// <summary>
/// 2. Вводиться з клавіатури час у форматі хв:сек наприклад 12: 11.
/// Записати даний час текстом : Дванадцять хвилин одинадцять секунд.
/// Перед виведенням результат помістити в об‘єкт типу string.
/// </summary>
void task2();

/// <summary>
/// зчитує рядок buf з файлу
/// </summary>
/// <param name="buf"> - рядок, у який зчитується текст з файлу </param>
/// <returns> false - у випадку відсутності файлу
/// true - у випадку вдалого зчитування </returns>
bool read_from_file_task2(string& buf);

/// <summary>
/// виділяє та перетворює у цілочисельний тип хвилини та секунди
/// </summary>
/// <param name="buf"> - рядок з вхідними даними </param>
/// <returns> рядок з часом у текстовому вигляді </returns>
string do_task2(const string& buf);

/// <summary>
/// перетворює з цілочисельного типу у текст, з відповідною розмірність хв/сек
/// </summary>
/// <param name="mm"> - хвилини </param>
/// <param name="ss"> - секунди </param>
/// <returns> рядок з часом у текстовому вигляді </returns>
string do_string(const int& mm, const int& ss);

/// <summary>
/// записує результат виконання до файлу
/// </summary>
/// <param name="time"> - рядок з часом у текстовому вигляді </param>
void write_to_file_task2(const string& time);

/// <summary>
/// записує у файл поточний час хв/сек
/// </summary>
void debug_file_task2();