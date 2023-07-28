//# include <stdio.h>
//
//# define N 10
//
//void fill_matr(int A[N][N]);	// заповнення матриці
//void print_matr(int A[N][N]);	// виведення матриці
//
//int main() {
//
//	int A[N][N];
//
//	fill_matr(A);
//	print_matr(A);
//
//	return 0;
//}
//
//void fill_matr(int A[N][N]) {
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			if (i <= j)
//				A[i][j] = j - i + 1;
//			else
//				A[i][j] = 0;
//}
//
//void print_matr(int A[N][N]) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++)
//			printf("%3d", A[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//}