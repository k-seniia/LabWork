#include "iostream"
#include "fstream"

using namespace std;

//У алфавітному порядку надрукувати усі приголосні та 
//створити усі можливі пари приголосних з голосними, 
//які є у тексті

int main() {

	char buf[100];

	ifstream fin("text.txt");
	fin.getline(buf, 100, '.');
	fin.close();

	char con[20]{}, vow[6]{};

	int b{}, c{}, v{}, count{};

	while (buf[b] != '\0') {
		if (isalpha(buf[b])) {
			buf[b] = tolower(buf[b]);
			if (buf[b] == 97 || buf[b] == 101 || buf[b] == 105 || buf[b] == 111 || buf[b] == 117 || buf[b] == 121) {
					count = 0;
					for (int j = 0; j < v; j++)
						if (buf[b] != vow[j])
							count++;
					if (count == v) {
						vow[v] = buf[b];
						v++;
					}
			}
			else {
					count = 0;
					for (int j = 0; j < c; j++)
						if (buf[b] != con[j])
							count++;
					if (count == c) {
						con[c] = buf[b];
						c++;
					}
			}
		}
		b++;
	}

	for (int i = 0; i < c - 1; i++)
		for (int j = 0; j < c - i - 1; j++)
			if (con[j] > con[j + 1])
				swap(con[j], con[j + 1]);

	ofstream fout("result.txt");
	
	for (int i = 0; i < c; i++) {
		cout << " " << con[i];
		fout << " " << con[i];
	}
	cout << endl;
	fout << endl;

	string* para = new string[b / 2];
	string* parb = new string[b / 2];
	int sa = 0, sb = 0;

	for (int i = 0; i < c; i++)
		for (int j = 0; j < v; j++)
			for (int k = 0; k < strlen(buf); k++)
				if (con[i] == buf[k] && vow[j] == buf[k + 1]) {
					para[sa] = con[i];
					para[sa] += vow[j];
					cout << " " << para[sa];
					fout << " " << para[sa];
					sa++;
					break;
				}

	cout << endl;
	fout << endl;

	for (int i = 0; i < c; i++)
		for (int j = 0; j < v; j++)
			for (int k = 0; k < strlen(buf); k++)
				if (con[i] == buf[k + 1] && vow[j] == buf[k]) {
					parb[sb] = vow[j];
					parb[sb] += con[i];
					cout << " " << parb[sb];
					fout << " " << parb[sb];
					sb++;
					break;
				}

	fout.close();
	cout << endl;

	return 0;
}