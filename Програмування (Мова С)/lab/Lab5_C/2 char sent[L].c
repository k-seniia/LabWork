//#include <stdio.h>
//#include <string.h>
//#define L 100
//
//void getLastWord(char* sent, char* lastWord);
//
//int main() {
//	char sent[L];
//	printf("Enter a sentence: ");
//	fgets(sent, L, stdin);
//
//	// ��������� ������ ������ �����, ���� �������� �������� fgets()
//	sent[strcspn(sent, "\n")] = 0;
//
//	char lastWord[L];
//	getLastWord(sent, lastWord);
//	printf("Last word: %s\n", lastWord);
//
//	return 0;
//}
//
//void getLastWord(char* sent, char* lastWord) {
//	// ��������� ������� �������� ����� ���������� �����
//	int i = strlen(sent) - 1;
//	while (i >= 0 && sent[i] == ' ')
//		i--;
//	int j = i;
//	// ��������� ������� ������� ���������� �����
//	while (i >= 0 && sent[i] != ' ')
//		i--;
//	// ������� ������ ����� �� ������ ������
//	int k = 0;
//	memset(lastWord, 0, sizeof(lastWord));
//	for (++i; i <= j; i++)
//		lastWord[k++] = sent[i];
//}