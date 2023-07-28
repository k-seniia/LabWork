//#include <stdio.h>
//#include <string.h>
//
//char removing_spaces(char* ch);		// пропуск пробілів
//char Redword(char* word, char* ch);	// зчитування одного слова
//void Printword(char* word);			// виведення слова в прямому порядку
//void PrintRevword(char* word);		// виведення слова в зворотному порядку
//
//int main() {
//
//	char ch;
//	char word[50];
//	memset(word, 0, sizeof(word));
//	int flag = 1;					// флаг для відстеження непарних слів
//
//	printf("Enter a sentence: ");
//	while ((ch = getchar()) != '.')
//		if (ch == ' ') {						// якщо символ - пробіл
//			if (strlen(word) > 0) {				// якщо вже було записано слово
//				if (flag)
//					Printword(word);			// вивести слово в прямому порядку
//				else
//					PrintRevword(word);			// вивести слово в зворотному порядку
//				memset(word, 0, sizeof(word));	// очистити масив слова
//				flag = !flag;					// змінити флаг на протилежний
//			}
//		}
//		else {
//			ch = removing_spaces(&ch);			// пропустити зайві пробіли
//			if (ch != '\0')						// якщо символ не є переносом рядку
//				Redword(word, &ch);				// додати символ до слова
//		}
//
//	if (strlen(word) > 0)		// вивести останнє слово
//		if (flag)
//			Printword(word);
//		else
//			PrintRevword(word);
//
//	return 0;
//}
//
//char removing_spaces(char* ch) {
//	while (*ch == ' ')		// якщо символ - пробіл
//		*ch = getchar();		// зчитати наступний символ
//	return *ch;
//}
//
//char Redword(char* word, char* ch) {
//	int len = strlen(word);
//	word[len] = *ch;			// додати символ до слова
//	return *word;
//}
//
//void Printword(char* word) {
//	for (int i = 0; i < strlen(word); i++)
//		putchar(word[i]);	// вивести символи слова в прямому порядку
//	putchar(' ');			// вивести пробіл після слова
//}
//
//void PrintRevword(char* word) {
//	for (int i = strlen(word) - 1; i >= 0; i--)
//		putchar(word[i]);	// вивести символи слова в зворотному порядку
//	putchar(' ');			// вивести пробіл після слова
//}