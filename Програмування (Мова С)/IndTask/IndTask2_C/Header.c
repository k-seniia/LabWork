#include "Header.h"

int input(char*** arr, const char* name)
{
	// �������� ������� ������
	printf("Enter the number of strings in the %s array: ", name);
	int n;
#ifdef DEBUG
	n = rand() % 9 + 2; printf("%d\n", n);
#else
	scanf_s("%d", &n);
#endif // DEBUG

	// �������� ���'�� ��� ������
	* arr = (char**)malloc(n * sizeof(char*));

	// �������� ����� ������
	printf("Enter the strings for the %s array:\n", name);
	for (int i = 0; i < n; i++) {
		(*arr)[i] = (char*)malloc(30 * sizeof(char)); // ������� ����� - 30 �������
		scanf_s("%s", (*arr)[i]);
	}
	printf("\n");

	return n;
}

int result(const char** arr1, const char** arr2, char*** arr3, const int n1, const int n2)
{
	// ���������� ������ �������� ������
	int n3 = n1 + n2;

	// �������� ���'�� ��� �������� ������
	*arr3 = (char**)malloc(n3 * sizeof(char*));

	// ��������� ����� �� ���������� �������� ������
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

	// ��������� ����� ����� � ������� ������
	while (i < n1) {
		(*arr3)[k] = arr1[i];
		i++;
		k++;
	}

	// ��������� ����� ����� � ������� ������
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
