//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define L 100
//
//char* getLastWord(char* sent);
//
//int main() {
//	char* sent = (char*)malloc(L * sizeof(char));
//	printf("Enter a sentence: ");
//	fgets(sent, L, stdin);
//
//	char* lastWord = getLastWord(sent);
//	printf("Last word: %s\n", lastWord);
//
//	free(sent);
//	free(lastWord);
//	return 0;
//}
//
//char* getLastWord(char* sent) {
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
//	char* lastWord = (char*)malloc(sizeof(char) * (j - i));
//	for (++i; i <= j; i++)
//		lastWord[k++] = sent[i];
//	return lastWord;
//}