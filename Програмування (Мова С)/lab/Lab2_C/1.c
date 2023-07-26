//# include <stdio.h>
//# include <stdlib.h>
//
//void input_matr(int*, int);	// введення матриці
//void rand_matr(int*, int);	// заповнення матриці
//void print_matr(int*, int);	// виведення матриці
//void two_matr(int*, int*, int*, int, int*, int*);
//
//int main() {
//	//srand(time(NULL));
//
//	int n = rand() % 15 + 5, b = 0, c = 0;
//	int* arr = (int*)malloc(n * sizeof(int)), * arrb = (int*)malloc(n * sizeof(int)), * arrc = (int*)malloc(n * sizeof(int));
//
//	//input_matr(arr, n);
//	rand_matr(arr, n);
//	printf("arr [%d] { ", n);
//	print_matr(arr, n);
//
//	two_matr(arr, arrb, arrc, n, &b, &c);
//
//	printf("arrb [%d] { ", b);
//	print_matr(arrb, b);
//	printf("arrc [%d] { ", c);
//	print_matr(arrc, c);
//
//	free(arr);
//	free(arrb);
//	free(arrc);
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
//		arr[i] = rand() % 101 - 50;
//}
//
//void print_matr(int* arr, int n) {
//	for (int i = 0; i < n; i++)
//		printf(" %d ", arr[i]);
//	printf(" }\n\n");
//}
//
//void two_matr(int* arr, int* arrb, int* arrc, int n, int* b, int* c) {
//	for (int i = 0; i < n; i++)
//		if (arr[i] < 0)
//			arrc[(*c)++] = arr[i];
//		else
//			arrb[(*b)++] = arr[i];
//	//arrb = (int*)realloc(arrb, (*b) * sizeof(int));
//	//arrc = (int*)realloc(arrc, (*c) * sizeof(int));
//}