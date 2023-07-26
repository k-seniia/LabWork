#include <stdio.h>

double recursion(int x, int n) {
	if (n == 0)
		return 1;
	else
		return x * recursion(x, n - 1) / n;
}

int main() {

	int x = 0, n = 0;
	printf("Enter x: ");
	scanf_s("%d", &x);
	printf("Enter n: ");
	scanf_s("%d", &n);
	
	if (n < 0) {
		printf("Erorr n < 0\n");
		exit(1);
	}

	double res = recursion(x, n);
	printf("Result: %.3f\n", res);

	return 0;
}