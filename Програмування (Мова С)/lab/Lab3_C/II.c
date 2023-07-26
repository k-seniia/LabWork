//#include <stdio.h>
//#include <stdlib.h>
//
//void rand_matr(int*, int, int);		// заповнення матриці
//void print_matr(int*, int, int);	// виведення матриці
//void swap_row(int*, int, int);		//
//
//int main() {
//	//srand(time(NULL));
//
//	int n = rand() % 8 + 2, m = rand() % 8 + 2;
//	int* arr = (int*)malloc(n * m * sizeof(int*));
//
//	rand_matr(arr, n, m);
//	print_matr(arr, n, m);
//
//	swap_row(arr, n, m);
//	print_matr(arr, n, m);
//
//	free(arr);
//
//	return 0;
//}
//
//void rand_matr(int* arr, int n, int m) {
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			*(arr + i * m + j) = rand() % 10 + 1;
//}
//
//void print_matr(int* arr, int n, int m) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++)
//			printf("%4d", *(arr + i * m + j));
//		printf("\n");
//	}
//	printf("\n");
//}
//
//void swap_row(int* arr, int n, int m) {
//	int temp;
//	for (int i = 0; i < n / 2; i++)
//		for (int j = 0; j < m; j++) {
//			temp = *(arr + i * m + j);
//			*(arr + i * m + j) = *(arr + (n - 1 - i) * m + j);
//			*(arr + (n - 1 - i) * m + j) = temp;
//		}
//}