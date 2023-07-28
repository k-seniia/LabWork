#include "Header.h"

int main() {
	//srand(time(NULL));

	printf("task ``arr\n\n");

	int n = rand() % 8 + 2; //scanf_s("%d", &n);

	int** tab = (int**)malloc(n * sizeof(int*));	// початкова таблиця результатів
	int* sum = (int*)malloc(n * sizeof(int));		// сума очок для кожної команди
	int* pos = (int*)malloc(n * sizeof(int));		// місце кожної команди в новій таблиці

	for (int i = 0; i < n; i++)
		*(pos + i) = i + 1;

	mem_matr(tab, n);

	rand_matr(tab, n);
	print_matr(tab, n);
	sum_points(tab, sum, n);
	print_sum(sum, n);
	sort_sum(sum, pos, n);
	print_pos(pos, sum, n);

	free_matr(tab, n);
	free(sum);
	free(pos);

	return 0;
}
