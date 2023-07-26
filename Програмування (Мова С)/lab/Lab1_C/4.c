//# include <stdio.h>
//
//# define N 9
//
//void input_matr(int A[N][N]);		// введення матриці
//void rand_matr(int A[N][N]);		// заповнення матриці
//int lower_min_matr(int A[N][N]);	// мінімальний елемент нижче побічної діагоналі
//void print_matr(int A[N][N]);		// виведення матриці
//void lower_print_matr(int A[N][N]);	// виведення матриці нижче побічної діагоналі
//
//int main() {
//	//srand(time(NULL));
//
//	int A[N][N];
//
//	//input_matr(A);
//	rand_matr(A);
//	print_matr(A);
//
//	printf(" min = %d\n", lower_min_matr(A));
//	lower_print_matr(A);
//
//	return 0;
//}
//
//void input_matr(int A[N][N]) {
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			scanf_s("%d", &A[i][j]);
//}
//
//void rand_matr(int A[N][N]) {
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			A[i][j] = rand() % 100 + 1;
//}
//
//int lower_min_matr(int A[N][N]) {
//	int min = A[N - 1][1];
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			if (i + j >= N && A[i][j] < min)
//				min = A[i][j];
//	return min;
//}
//
//void print_matr(int A[N][N]) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++)
//			printf("%4d", A[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//}
//
//void lower_print_matr(int A[N][N]) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++)
//			if (i + j >= N)
//				printf("%4d", A[i][j]);
//			else
//				printf("    ");
//		printf("\n");
//	}
//	printf("\n");
//}