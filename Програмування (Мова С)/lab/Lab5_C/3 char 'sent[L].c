//#include <stdio.h>
//#include <string.h>
//#define L 100
//#pragma warning(disable : 4996)
//
//void readSentence(char* sent);
//void printSentence(char* sent[]);
//void reverseWord(char* word);
//int is_palindrome(char* word);
//
//int main() {
//	char sent[L];
//	readSentence(sent);
//
//	char* words[L];
//	char* token = strtok(sent, " ");
//	int n = 0;
//	while (token != NULL) {
//		words[n++] = token;
//		token = strtok(NULL, " ");
//	}
//
//	int wordIndex;
//	printf("Enter index of word to reverse (from 0 to %d): ", n - 1);
//	scanf_s("%d", &wordIndex);
//	if (wordIndex < 0 || wordIndex >= n) {
//		printf("Invalid index!\n");
//		return 1;
//	}
//
//	reverseWord(words[wordIndex]);
//	printf("Reversed word: %s\n", words[wordIndex]);
//
//	if (is_palindrome(words[wordIndex]))	// перевірка на паліндром
//		printf("The word is a palindrome.\n");
//	else
//		printf("The word is not a palindrome.\n");
//
//	return 0;
//}
//
//void readSentence(char* sent) {
//	printf("Enter a sentence: ");
//	fgets(sent, L, stdin);
//	sent[strlen(sent) - 1] = '\0'; // remove trailing newline
//}
//
//void printSentence(char* sent[]) {
//	printf("Sentence: ");
//	int i = 0;
//	while (sent[i] != NULL) {
//		printf("%s ", sent[i]);
//		i++;
//	}
//	printf("\n");
//}
//
//void reverseWord(char* word) {
//	int len = strlen(word);
//	for (int i = 0; i < len / 2; i++) {
//		char temp = word[i];
//		word[i] = word[len - i - 1];
//		word[len - i - 1] = temp;
//	}
//}
//
//int is_palindrome(char* word) {
//	int len = strlen(word);
//	for (int i = 0; i < len / 2; i++)	// перевірити чи є слово паліндромом
//		if (word[i] != word[len - 1 - i])
//			return 0;
//	return 1;
//}