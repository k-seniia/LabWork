//#include <stdio.h>
//#include <stdlib.h>
//
//void mem_matr(int**, int, int);			// виділення пам’яті
//void free_matr(int**, int);				// звільнення пам’яті
//void rand_matr(int**, int, int*);		// заповнення матриці
//void print_matr(int**, int, int*);		// виведення матриці
//void swap_row(int**, int, int*, int);	//
//
//int main() {
//	//srand(time(NULL));
//
//	int n = rand() % 8 + 2, max = INT_MIN;
//	int** arr = (int**)malloc(n * sizeof(int*));
//	int* m = (int*)malloc(n * sizeof(int));
//	for (int i = 0; i < n; i++) {
//		m[i] = rand() % 8 + 2;
//		if (m[i] > max)
//			max = m[i];
//	}
//
//	mem_matr(arr, n, max);
//	rand_matr(arr, n, m);
//	print_matr(arr, n, m);
//
//	swap_row(arr, n, m, max);
//	print_matr(arr, n, m);
//
//	free_matr(arr, n);
//	free(m);
//
//	return 0;
//}
//
//void mem_matr(int** arr, int n, int m) {
//	for (int i = 0; i < n; i++)
//		*(arr + i) = (int*)malloc(m * sizeof(int));
//}
//
//void free_matr(int** arr, int n) {
//	for (int i = 0; i < n; i++)
//		free(*(arr + i));
//	free(arr);
//}
//
//void rand_matr(int** arr, int n, int* m) {
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m[i]; j++)
//			*(*(arr + i) + j) = rand() % 10 + 1;
//}
//
//void print_matr(int** arr, int n, int* m) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m[i]; j++)
//			printf("%4d", *(*(arr + i) + j));
//		printf("\n");
//	}
//	printf("\n");
//}
//
//void swap_row(int** arr, int n, int* m, int max) {
//	int temp;
//	for (int i = 0; i < n / 2; i++) {
//		for (int j = 0; j < max; j++) {
//			temp = *(*(arr + i) + j);
//			*(*(arr + i) + j) = *(*(arr + (n - 1 - i)) + j);
//			*(*(arr + (n - 1 - i)) + j) = temp;
//		}
//		temp = m[i];
//		m[i] = m[n - 1 - i];
//		m[n - 1 - i] = temp;
//	}
//}