#pragma once
#include <stdio.h>
#include <stdlib.h>

//`arr

void rand_matr(int* arr, int n);				// ���������� ������
void print_matr(int* arr, int n);				// ��������� ������� ����
void sum_points(int* tab, int* sum, int n);		// ��������� ���� ����
void print_sum(int* arr, int n);				// ��������� ���� ����
void sort_sum(int* sum, int* pos, int n);		// ���������� �� ���������� ���� ����
void swap(int* a, int* b);						// ����� ������ �������
void print_pos(int* pos, int* sum, int n);		// ��������� ����������