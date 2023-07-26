//#include <stdio.h>
//#include <string.h>
//
//char removing_spaces(char* ch);		// ������� ������
//char Redword(char* word, char* ch);	// ���������� ������ �����
//void Printword(char* word);			// ��������� ����� � ������� �������
//void PrintRevword(char* word);		// ��������� ����� � ���������� �������
//
//int main() {
//
//	char ch;
//	char word[50];
//	memset(word, 0, sizeof(word));
//	int flag = 1;					// ���� ��� ���������� �������� ���
//
//	printf("Enter a sentence: ");
//	while ((ch = getchar()) != '.')
//		if (ch == ' ') {						// ���� ������ - �����
//			if (strlen(word) > 0) {				// ���� ��� ���� �������� �����
//				if (flag)
//					Printword(word);			// ������� ����� � ������� �������
//				else
//					PrintRevword(word);			// ������� ����� � ���������� �������
//				memset(word, 0, sizeof(word));	// �������� ����� �����
//				flag = !flag;					// ������ ���� �� �����������
//			}
//		}
//		else {
//			ch = removing_spaces(&ch);			// ���������� ���� ������
//			if (ch != '\0')						// ���� ������ �� � ��������� �����
//				Redword(word, &ch);				// ������ ������ �� �����
//		}
//
//	if (strlen(word) > 0)		// ������� ������ �����
//		if (flag)
//			Printword(word);
//		else
//			PrintRevword(word);
//
//	return 0;
//}
//
//char removing_spaces(char* ch) {
//	while (*ch == ' ')		// ���� ������ - �����
//		*ch = getchar();		// ������� ��������� ������
//	return *ch;
//}
//
//char Redword(char* word, char* ch) {
//	int len = strlen(word);
//	word[len] = *ch;			// ������ ������ �� �����
//	return *word;
//}
//
//void Printword(char* word) {
//	for (int i = 0; i < strlen(word); i++)
//		putchar(word[i]);	// ������� ������� ����� � ������� �������
//	putchar(' ');			// ������� ����� ���� �����
//}
//
//void PrintRevword(char* word) {
//	for (int i = strlen(word) - 1; i >= 0; i--)
//		putchar(word[i]);	// ������� ������� ����� � ���������� �������
//	putchar(' ');			// ������� ����� ���� �����
//}