//#include <stdio.h>
//#include <stdlib.h>
//
//#define N 5
//
//void mem_matr(int**, int);		// виділення пам’яті
//void free_matr(int**);			// звільнення пам’яті
//void rand_matr(int**, int);		// заповнення матриці
//void print_matr(int**, int);	// виведення матриці
//void swap_row(int**, int);		//
//
//int main() {
//	//srand(time(NULL));
//
//	int m = rand() % 8 + 2;
//	int* arr[N];
//
//	mem_matr(arr, m);
//	rand_matr(arr, m);
//	print_matr(arr, m);
//
//	swap_row(arr, m);
//	print_matr(arr, m);
//
//	free_matr(arr);
//
//	return 0;
//}
//
//void mem_matr(int** arr, int m) {
//	for (int i = 0; i < N; i++)
//		arr[i] = (int*)malloc(m * sizeof(int));
//}
//
//void free_matr(int** arr) {
//	for (int i = 0; i < N; i++)
//		free(arr[i]);
//}
//
//void rand_matr(int** arr, int m) {
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < m; j++)
//			*(arr[i] + j) = rand() % 10 + 1;
//}
//
//void print_matr(int** arr, int m) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < m; j++)
//			printf("%4d", *(arr[i] + j));
//		printf("\n");
//	}
//	printf("\n");
//}
//
//void swap_row(int** arr, int m) {
//	int temp;
//	for (int i = 0; i < N / 2; i++)
//		for (int j = 0; j < m; j++) {
//			temp = *(arr[i] + j);
//			*(arr[i] + j) = *(arr[N - 1 - i] + j);
//			*(arr[N - 1 - i] + j) = temp;
//		}
//}