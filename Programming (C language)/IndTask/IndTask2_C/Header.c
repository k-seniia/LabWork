#include "Header.h"

int input(char*** arr, const char* name)
{
	// введення довжини масиву
	printf("Enter the number of strings in the %s array: ", name);
	int n;
#ifdef DEBUG
	n = rand() % 9 + 2; printf("%d\n", n);
#else
	scanf_s("%d", &n);
#endif // DEBUG

	// виділення пам'яті для масиву
	* arr = (char**)malloc(n * sizeof(char*));

	// введення рядків масиву
	printf("Enter the strings for the %s array:\n", name);
	for (int i = 0; i < n; i++) {
		(*arr)[i] = (char*)malloc(30 * sizeof(char)); // довжина рядка - 30 символів
		scanf_s("%s", (*arr)[i]);
	}
	printf("\n");

	return n;
}

int result(const char** arr1, const char** arr2, char*** arr3, const int n1, const int n2)
{
	// обчислення розміру третього масиву
	int n3 = n1 + n2;

	// виділення пам'яті для третього масиву
	*arr3 = (char**)malloc(n3 * sizeof(char*));

	// порівняння рядків та заповнення третього масиву
	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2) {
		if (strcmp(arr1[i], arr2[j]) > 0) { // 0 -> str1 = str2, <0 -> str1 < str2, >0 -> str1 > str2
		//if (strlen(arr1[i]) > strlen(arr2[j])) {
			(*arr3)[k] = arr1[i];
			k++;
			(*arr3)[k] = arr2[j];
		}
		else {
			(*arr3)[k] = arr2[j];
			k++;
			(*arr3)[k] = arr1[i];
		}
		i++;
		j++;
		k++;
	}

	// додавання решти рядків з першого масиву
	while (i < n1) {
		(*arr3)[k] = arr1[i];
		i++;
		k++;
	}

	// додавання решти рядків з другого масиву
	while (j < n2) {
		(*arr3)[k] = arr2[j];
		j++;
		k++;
	}

	return n3;
}

void printarr(const char** arr, const int n, const char* name)
{
	printf("the strings of the %s array:\n", name);
	for (int i = 0; i < n; i++) {
		printf("%s ", arr[i]);
	}
	printf("\n");
}
