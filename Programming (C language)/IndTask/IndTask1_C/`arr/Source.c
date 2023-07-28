#include "Header.h"

//`arr

void rand_matr(int* arr, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				*(arr + i * n + j) = rand() % 9 + 1;
			else
				*(arr + i * n + j) = 0;
}

void print_matr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf(" Team %d: ", i + 1);
		for (int j = 0; j < n; j++)
			printf("%3d", *(arr + i * n + j));
		printf("\n");
	}
	printf("\n");
}

void sum_points(int* tab, int* sum, int n) {
	for (int i = 0; i < n; i++) {
		*(sum + i) = 0;
		for (int j = 0; j < n; j++)
			*(sum + i) += *(tab + i * n + j);
	}
}

void print_sum(int* arr, int n) {
	for (int i = 0; i < n; i++)
		printf(" Team %d: %3d\n", i + 1, *(arr + i));
	printf("\n");
}

void sort_sum(int* sum, int* pos, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (*(sum + j) < *(sum + j + 1)) {
				swap(&*(sum + j), &*(sum + j + 1));
				swap(&*(pos + j), &*(pos + j + 1));
			}
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_pos(int* pos, int* sum, int n) {
	for (int i = 0; i < n; i++)
		printf(" %d. Team %d: %3d\n", i + 1, *(pos + i), *(sum + i));
	printf("\n");
}
