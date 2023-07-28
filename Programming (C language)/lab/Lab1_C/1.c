//# include <stdio.h>
//
//# define N 4
//# define M 3
//
//void input_matr(int A[N][M]);	// введення матриці
//void rand_matr(int A[N][M]);	// заповнення матриці
//void print_matr(int A[N][M]);	// виведення матриці
//int number_row(int A[N][M]);	// кількість стовпців
//
//int main() {
//	//srand(time(NULL));
//
//	int A[N][M];
//
//	//input_matr(A);
//	rand_matr(A);
//	print_matr(A);
//
//	printf("num = %d\n", number_row(A));
//
//	return 0;
//}
//
//void input_matr(int A[N][M]) {
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			scanf_s("%d", &A[i][j]);
//}
//
//void rand_matr(int A[N][M]) {
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			A[i][j] = rand() % 100 + 1;
//}
//
//void print_matr(int A[N][M]) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++)
//			printf("%4d", A[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//}
//
//int number_row(int A[N][M]) {
//	int count = 0, flag = 0;
//	for (int j = 0; j < M; j++) {
//		flag = 1;
//		for (int i = 0; i < N; i++)
//			for (int k = 0; k < N; k++)
//				if (i != k && A[i][j] == A[k][j])
//					flag = 0;
//		if (flag)
//			count++;
//	}
//	return count;
//}