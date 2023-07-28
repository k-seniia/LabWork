//# include <stdio.h>
//# include <stdlib.h>
//#include <time.h>
//
//void input_matr(int*, int);				// введення матриці
//void rand_matr(int*, int);				// заповнення матриці
//void print_matr(int*, int);				// виведення матриці
//void separation(int*, int*, int*, int);	//
//
//int main() {
//	srand(time(NULL));
//
//	int n = rand() % 15 + 5;
//	int* arr = (int*)malloc(n * sizeof(int)), * arr1 = (int*)malloc(n * sizeof(int)), * arr2 = (int*)malloc(n * sizeof(int));
//
//	//input_matr(arr, n);
//	rand_matr(arr, n);
//	print_matr(arr, n);
//
//	separation(arr, arr1, arr2, n);
//
//	free(arr);
//	free(arr1);
//	free(arr2);
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
//		arr[i] = rand() % 30 + 1;
//}
//
//void print_matr(int* arr, int n) {
//	for (int i = 0; i < n; i++)
//		printf(" %d ", arr[i]);
//}
//
//void separation(int* arr, int* arr1, int* arr2, int n) {
//	int sum = 0, sum1 = 0, sum2 = 0, dif1 = 0, dif2 = 0, s1 = 0, s2 = n, s = 0;;
//
//	for (int i = 0; i < n; i++)
//		sum += arr[i];
//	printf("  sum = %d\n", sum);
//
//	while (sum1 < sum / 2) {
//		sum1 += arr[s1];
//		s1++;
//	}
//	dif1 = sum1 - (sum - sum1);
//
//	while (sum2 < sum / 2) {
//		s2--;
//		sum2 += arr[s2];
//	}
//	dif2 = sum2 - (sum - sum2);
//
//	if (dif1 <= dif2) {
//		for (int i = 0; i < s1; i++)
//			arr1[i] = arr[i];
//		for (int i = s1; i < n; i++)
//			arr2[i - s1] = arr[i];
//		sum2 = sum - sum1;
//		s = s1;
//	}
//	else {
//		for (int i = 0; i < s2; i++)
//			arr1[i] = arr[i];
//		for (int i = s2; i < n; i++)
//			arr2[i - s2] = arr[i];
//		sum1 = sum - sum2;
//		s = s2;
//	}
//
//	print_matr(arr1, s);
//	printf("  sum = %d\n", sum1);
//	print_matr(arr2, n - s);
//	printf("  sum = %d\n", sum2);
//}