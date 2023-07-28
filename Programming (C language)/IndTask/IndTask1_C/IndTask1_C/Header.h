#pragma once
#include <stdio.h>
#include <stdlib.h>

//arr[][]

#define N 10 // максимальна к≥льк≥сть команд

void rand_matr(int arr[N][N], int n);				// заповненн€ масив≥в
void print_matr(int arr[N][N], int n);				// виведенн€ таблиц≥ бал≥в
void sum_points(int tab[N][N], int sum[N], int n);	// п≥драхунок суми бал≥в
void print_sum(int arr[N], int n);					// виведенн€ суми бал≥в
void sort_sum(int sum[N], int pos[N], int n);		// сортуванн€ за зменшенн€м суми бал≥в
void swap(int* a, int* b);							// зам≥на м≥сц€ми значень
void print_pos(int[N], int[N], int);				// виведенн€ результат≥в