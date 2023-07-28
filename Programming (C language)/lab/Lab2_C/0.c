//# include <stdio.h>
//# include <stdlib.h>
//
//void input_matr(int**, int, int);			// введення матриці
//void rand_matr(int**, int, int);			// заповнення матриці
//void print_matr(int**, int, int);			// виведення матриці
//int number_col(int**, int, int, int*);	// кількість стовпців
//void print_col(int**, int, int, int*);	// 
//
//int main() {
//	//srand(time(NULL));
//
//	int n = rand() % 8 + 2, m = rand() % 8 + 2;
//	int** arr = (int**)malloc(n * sizeof(int*)), * ar = (int*)malloc(m * sizeof(int));
//	for (int i = 0; i < n; i++)
//		arr[i] = (int*)malloc(m * sizeof(int));
//
//	//input_matr(arr, n, m);
//	rand_matr(arr, n, m);
//	print_matr(arr, n, m);
//
//	printf("num = %d\n", number_col(arr, n, m, ar));
//	print_col(arr, n, m, ar);
//
//	for (int i = 0; i < n; i++)
//		free(arr[i]);
//	free(arr);
//
//	return 0;
//}
//
//void input_matr(int** arr, int n, int m) {
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			scanf_s("%d", &arr[i][j]);
//}
//
//void rand_matr(int** arr, int n, int m) {
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			arr[i][j] = rand() % 10 + 1;
//}
//
//void print_matr(int** arr, int n, int m) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++)
//			printf("%4d", arr[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//}
//
//int number_col(int** arr, int n, int m, int* ar) {
//	int count = 0, flag = 0;
//	for (int j = 0; j < m; j++) {
//		flag = 1;
//		for (int i = 0; i < n; i++)
//			for (int k = 0; k < n; k++)
//				if (i != k && arr[i][j] == arr[k][j])
//					flag = 0;
//		if (flag) {
//			count++;
//			ar[j] = 1;
//		}
//	}
//	return count;
//}
//
//void print_col(int** arr, int n, int m, int* ar) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++)
//			if (ar[j] == 1)
//				printf("%4d", arr[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//}