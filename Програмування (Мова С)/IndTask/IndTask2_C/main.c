#include "Header.h"

int main() {
	srand(time(NULL));

	char** arr1, ** arr2, ** arr3;
	int n1, n2, n3;

	n1 = input(&arr1, "first");
	n2 = input(&arr2, "second");
	n3 = result(arr1, arr2, &arr3, n1, n2);

	printarr(arr3, n3, "third");

	system("pause");
	return 0;
}