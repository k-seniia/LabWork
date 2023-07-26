#include "Phone.h"
#define DEBUG

int main() {
	// ��������� ��������� ��� ��������
	vector<Phone> phoneBook;
	int n{}; cout << "\tEnter the number of users -> "; cin >> n;
	phoneBook.resize(n);
#ifdef DEBUG
	for (int i = 0; i < phoneBook.size(); ++i) {
		phoneBook[i].generateRandomData();
		cout << phoneBook[i] << endl;
	}
#else
	cout << "\tEnter details for " << n << " users:\n";
	for (int i = 0; i < phoneBook.size(); ++i) {
		cout << "\n\tUser " << i + 1 << ":\n";
		cin >> phoneBook[i];
	}
#endif // DEBUG
	bool flag = false;

	// �) ³������ ��� ��������, ��� ��������� ������ ������ ���� �������� �������
	int localCallTime{}; cout << "\n\tEnter a local time limit -> "; cin >> localCallTime;
	cout << "\tAbonents with local call time exceeding " << localCallTime << " minutes:\n";
	for (int i = 0; i < phoneBook.size(); ++i) {
		if (phoneBook[i].getLocalCallTime() > localCallTime) {
			cout << phoneBook[i] << endl;
			flag = true;
		}
		if (i == phoneBook.size() - 1 && !flag) {
			cout << "Not found" << endl;
		}
	}

	flag = false;

	// �) ³������ ��� ��������, �� ������������ �������� ��'�����
	cout << "\n\tAbonents who used long distance calls:\n";
	for (int i = 0; i < phoneBook.size(); ++i) {
		if (phoneBook[i].getLongDistanceCallTime() > 0) {
			cout << phoneBook[i] << endl;
			flag = true;
		}
		if (i == phoneBook.size() - 1 && !flag) {
			cout << "Not found" << endl;
		}
	}

	// �) ������ ������� "�����" ����� �������� �� ������� ����� ����������
	cout << "\n\tInformation about the first 'Ivan' in the phone book:\n";
	for (int i = 0; i < phoneBook.size(); ++i) {
		if (phoneBook[i].getFullName().find("Ivan") != string::npos) {
			cout << phoneBook[i] << endl;
			break;
		}
		if (i == phoneBook.size() - 1) {
			cout << "Not found" << endl;
		}
	}

	return 0;
}