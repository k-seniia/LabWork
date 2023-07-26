#pragma once
#include <stdio.h>
#include <stdlib.h>

//`arr[]

#define N 10 // максимальна кількість команд

void mem_matr(int* arr[N], int n);					// виділення пам’яті
void rand_matr(int* arr[N], int n);					// заповнення масивів
void print_matr(int* arr[N], int n);				// виведення таблиці балів
void sum_points(int* tab[N], int sum[N], int n);	// підрахунок суми балів
void print_sum(int arr[N], int n);					// виведення суми балів
void sort_sum(int sum[N], int pos[N], int n);		// сортування за зменшенням суми балів
void swap(int* a, int* b);							// заміна місцями значень
void print_pos(int pos[N], int sum[N], int n);		// виведення результатів
void free_matr(int* arr[N], int n);					// звільнення пам’яті