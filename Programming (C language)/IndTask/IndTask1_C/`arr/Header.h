#pragma once
#include <stdio.h>
#include <stdlib.h>

//`arr

void rand_matr(int* arr, int n);				// заповненн€ масив≥в
void print_matr(int* arr, int n);				// виведенн€ таблиц≥ бал≥в
void sum_points(int* tab, int* sum, int n);		// п≥драхунок суми бал≥в
void print_sum(int* arr, int n);				// виведенн€ суми бал≥в
void sort_sum(int* sum, int* pos, int n);		// сортуванн€ за зменшенн€м суми бал≥в
void swap(int* a, int* b);						// зам≥на м≥сц€ми значень
void print_pos(int* pos, int* sum, int n);		// виведенн€ результат≥в