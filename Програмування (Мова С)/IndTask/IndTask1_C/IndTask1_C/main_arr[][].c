#include "Header.h"

int main() {
	//srand(time(NULL));

	printf("task arr[][]\n\n");

	int tab[N][N];	// початкова таблиця результатів
	int sum[N];		// сума очок для кожної команди
	int pos[N];		// місце кожної команди в новій таблиці

	int n = rand() % 8 + 2; //scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
		pos[i] = i + 1;

	rand_matr(tab, n);
	print_matr(tab, n);
	sum_points(tab, sum, n);
	print_sum(sum, n);
	sort_sum(sum, pos, n);
	print_pos(pos, sum, n);

	return 0;
}