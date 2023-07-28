#pragma once
#include <stdio.h>
#include <stdlib.h>

//`arr[]

#define N 10 // ����������� ������� ������

void mem_matr(int* arr[N], int n);					// �������� �����
void rand_matr(int* arr[N], int n);					// ���������� ������
void print_matr(int* arr[N], int n);				// ��������� ������� ����
void sum_points(int* tab[N], int sum[N], int n);	// ��������� ���� ����
void print_sum(int arr[N], int n);					// ��������� ���� ����
void sort_sum(int sum[N], int pos[N], int n);		// ���������� �� ���������� ���� ����
void swap(int* a, int* b);							// ����� ������ �������
void print_pos(int pos[N], int sum[N], int n);		// ��������� ����������
void free_matr(int* arr[N], int n);					// ��������� �����