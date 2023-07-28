#pragma once
#include <stdio.h>
#include <stdlib.h>

//``arr

void mem_matr(int** arr, int n);				// виділення пам’яті
void rand_matr(int** arr, int n);				// заповнення масивів
void print_matr(int** arr, int n);				// виведення таблиці балів
void sum_points(int** tab, int* sum, int n);	// підрахунок суми балів
void print_sum(int* arr, int n);				// виведення суми балів
void sort_sum(int* sum, int* pos, int n);		// сортування за зменшенням суми балів
void swap(int* a, int* b);						// заміна місцями значень
void print_pos(int* pos, int* sum, int n);		// виведення результатів
void free_matr(int** arr, int n);				// звільнення пам’яті