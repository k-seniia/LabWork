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
//	// Видаляємо символ нового рядка, який додається функцією fgets()
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
//	// Знаходимо позицію останньої букви останнього слова
//	int i = strlen(sent) - 1;
//	while (i >= 0 && sent[i] == ' ')
//		i--;
//	int j = i;
//	// Знаходимо позицію початку останнього слова
//	while (i >= 0 && sent[i] != ' ')
//		i--;
//	// Копіюємо останнє слово до нового масиву
//	int k = 0;
//	memset(lastWord, 0, sizeof(lastWord));
//	for (++i; i <= j; i++)
//		lastWord[k++] = sent[i];
//}