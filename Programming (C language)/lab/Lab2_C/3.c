//# include <stdio.h>
//# include <stdlib.h>
//
//void input_matr(int*, int);	// введення матриці
//void rand_matr(int*, int);	// заповнення матриці
//void print_matr(int*, int);	// виведення матриці
//int ar_pro(int*, int);
//
//int main() {
//	//srand(time(NULL));
//
//	int n = rand() % 5 + 5;
//	int* arr = (int*)malloc(n * sizeof(int));
//
//	input_matr(arr, n);
//	//rand_matr(arr, n);
//	print_matr(arr, n);
//
//	printf("\nprogression difference = %d\n", ar_pro(arr, n));
//
//	free(arr);
//
//	return 0;
//}
//
//void input_matr(int* arr, int n) {
//	for (int i = 0; i < n; i++) {
//		scanf_s("%d", &arr[i]);
//		for (int j = 0; j < i; j++)
//			if (arr[i] == arr[j])
//				i--;
//	}
//}
//
//void rand_matr(int* arr, int n) {
//	arr[0] = 1;
//	for (int i = 1; i < n; i++) {
//		arr[i] = rand() % 50 + 1;
//		for (int j = 0; j < i; j++)
//			if (arr[i] == arr[j])
//				i--;
//	}
//}
//
//void print_matr(int* arr, int n) {
//	for (int i = 0; i < n; i++)
//		printf(" %d ", arr[i]);
//	printf("\n");
//}
//
//int ar_pro(int* arr, int n) {
//	int d = arr[1] - arr[0];
//	for (int i = 2; i < n; i++) {
//		if (arr[i] - i * d != arr[0]) {
//			return 0;
//		}
//	}
//	return d;
//}