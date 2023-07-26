//#include <stdio.h>
//#include <stdlib.h>
//
//void mem_matr(int**, int, int);		// виділення пам’яті
//void free_matr(int**, int);			// звільнення пам’яті
//void rand_matr(int**, int, int);	// заповнення матриці
//void print_matr(int**, int, int);	// виведення матриці
//void swap_row(int**, int, int);		//
//
//int main() {
//	//srand(time(NULL));
//
//	int n = rand() % 8 + 2, m = rand() % 8 + 2;
//	int** arr = (int**)malloc(n * sizeof(int*));
//
//	mem_matr(arr, n, m);
//	rand_matr(arr, n, m);
//	print_matr(arr, n, m);
//
//	swap_row(arr, n, m);
//	print_matr(arr, n, m);
//
//	free_matr(arr, n);
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
//void rand_matr(int** arr, int n, int m) {
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			*(*(arr + i) + j) = rand() % 10 + 1;
//}
//
//void print_matr(int** arr, int n, int m) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++)
//			printf("%4d", *(*(arr + i) + j));
//		printf("\n");
//	}
//	printf("\n");
//}
//
//void swap_row(int** arr, int n, int m) {
//	int temp;
//	for (int i = 0; i < n / 2; i++)
//		for (int j = 0; j < m; j++) {
//			temp = *(*(arr + i) + j);
//			*(*(arr + i) + j) = *(*(arr + (n - 1 - i)) + j);
//			*(*(arr + (n - 1 - i)) + j) = temp;
//		}
//}