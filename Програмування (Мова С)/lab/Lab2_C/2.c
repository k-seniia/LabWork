//# include <stdio.h>
//# include <stdlib.h>
//
//void input_matr(int*, int);	// введення матриці
//void rand_matr(int*, int);	// заповнення матриці
//void print_matr(int*, int);	// виведення матриці
//int pair(int*, int, int);	//
//
//int main() {
//	//srand(time(NULL));
//
//	int n = rand() % 15 + 5, k = rand() % 15 + 5;
//	int* arr = (int*)malloc(n * sizeof(int));
//
//	//input_matr(arr, n);
//	rand_matr(arr, n);
//	print_matr(arr, n);
//
//	printf("\nk = %d\n\nnumber of pairs = %d\n", k, pair(arr, n, k));
//
//	free(arr);
//
//	return 0;
//}
//
//void input_matr(int* arr, int n) {
//	for (int i = 0; i < n; i++)
//		scanf_s("%d", &arr[i]);
//}
//
//void rand_matr(int* arr, int n) {
//	for (int i = 0; i < n; i++)
//		arr[i] = rand() % 50 + 1;
//}
//
//void print_matr(int* arr, int n) {
//	for (int i = 0; i < n; i++)
//		printf(" %d ", arr[i]);
//	printf("\n");
//}
//
//int pair(int* arr, int n, int k) {
//	int count = 0;
//	for (int i = 0; i < n; i++)
//		if (arr[i] % 2 == 0)
//			for (int j = i + 1; j < n; j++)
//				if (arr[j] % 2 == 0)
//					if (abs(arr[i] - arr[j]) <= k)
//						count++;
//	return count;
//}