//# include <stdio.h>
//
//# define N 4
//
//void input_matr(int A[N][N]);	// �������� �������
//void rand_matr(int A[N][N]);	// ���������� �������
//void null_matr(int A[N][N]);	// ����� ������
//void print_matr(int A[N][N]);	// ��������� �������
//void null_print_matr(int A[N][N]);	// ��������� ������� ��� ����
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
//	null_matr(A);
//	print_matr(A);
//	null_print_matr(A);
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
//void null_matr(int A[N][N]) {
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			if (i <= j)
//				A[i][j] = 0;
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
//void null_print_matr(int A[N][N]) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++)
//			if (i > j)
//				printf("%4d", A[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//}