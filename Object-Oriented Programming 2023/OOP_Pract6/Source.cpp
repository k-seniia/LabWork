#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

#define DEBUG

bool In_30_70(int x) {
	return x > 30 && x < 70;
}

int main() {
	setlocale(LC_ALL, "ru");

	int N;
	cout << "  ����i�� ����i� ������ -> "; cin >> N;

	vector<int> v(N);
#ifdef DEBUG
	// 1. I�i�i��i���i� ������ � ����������� ����������
	cout << "\n1. I�i�i��i���i� ������ � ����������� ����������" << endl;
	int range;
	cout << "  ����i�� �i������ [-N, N] ��� ���������� ������� -> "; cin >> range;

	// I�i�i��i���i� ���������� �� ������i��
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(-range, range);
	generate(v.begin(), v.end(), [&] {return distribution(generator); });

	/*vector<double> v5(N);
	srand(time(NULL));
	int rangemin, rangemax;
	cout << "min -> "; cin >> rangemin;
	cout << "max -> "; cin >> rangemax;
	for (int i = 0; i < N; i++) {
		v5[i] = (double)rand() / RAND_MAX * (rangemax - rangemin) + rangemin;
	}

	copy(v5.begin(), v5.end(), ostream_iterator<double>(cout, " "));
	cout << endl;*/

#else
	// 1. I�i�i��i���i� ������ � ����i�����
	cout << "\n1. I�i�i��i���i� ������ � ����i�����" << endl;
	cout << "  ����i�� �������� ������ -> ";
	for (auto& a : v) {
		cin >> a;
	}
#endif // DEBUG

	// ��������� ����������� ������
	cout << "    ���������� �����: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "    ����i� ������: " << v.size() << endl;

	// 3. ����������� �i�i�������� �� ������������� �������� ������ ������
	cout << "\n3. ����������� �i�i�������� �� ������������� �������� ������ ������" << endl;
	int min = *min_element(v.begin(), v.end());
	int max = *max_element(v.begin(), v.end());

	cout << "\t�i�i������ �������� ������ ������: " << min << endl;
	cout << "\t����������� �������� ������ ������: " << max << endl;

	// 3. ����������� �i�i�������� �� ������������� �������� �������� �I�������
	cout << "\n3. ����������� �i�i�������� �� ������������� �������� �������� �I�������" << endl;
	int rangeStart, rangeEnd;
	cout << "  ����i�� ������� �i������� �i� 0 �� " << v.size() - 1 << " -> "; cin >> rangeStart;
	cout << "  ����i�� �i���� �i������� �i� " << rangeStart + 1 << " �� " << v.size() - 1 << " -> "; cin >> rangeEnd;

	min = *min_element(v.begin() + rangeStart, v.begin() + rangeEnd + 1);
	max = *max_element(v.begin() + rangeStart, v.begin() + rangeEnd + 1);

	cout << "    ������� �i������: ";
	copy(v.begin() + rangeStart, v.begin() + rangeEnd + 1, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "\t�i�i������ �������� �������� �I�������: " << min << endl;
	cout << "\t����������� �������� �������� �I�������: " << max << endl;

	// 4. ���������� ������ �� ��i��������
	cout << "\n4. ���������� ������ �� ��i��������" << endl;
	sort(v.begin(), v.end());

	cout << "    ����� �i��� ���������� �� ��i��������: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// 5. ������� �������i� � �����ί �����I� � �����
	cout << "\n5. ������� �������i� � �����ί �����I� � �����" << endl;
	int position, numElements;
	cout << "  ����i�� �����i� ��� ������� �������i� �i� 0 �� " << v.size() - 1 << " -> "; cin >> position;
	cout << "  ����i�� �i���i��� �������i� ��� ������� -> "; cin >> numElements;

	vector<int> elements(numElements);
	cout << "  ����i�� �������� �������i� -> ";
	for (int i = 0; i < numElements; i++) {
		cin >> elements[i];
	}

	v.insert(v.begin() + position, elements.begin(), elements.end());

	cout << "    ����� �i��� ������� �������i�: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "    ����i� ������: " << v.size() << endl;

	// 6. ��������� �������i� � �����ί �����I� � �����i
	cout << "\n6. ��������� �������i� � �����ί �����I� � �����i" << endl;
	cout << "  ����i�� �����i� ��� ��������� �������i� �i� 0 �� " << v.size() - 1 << " -> "; cin >> position;
	cout << "  ����i�� �i���i��� �������i� ��� ��������� �� " << v.size() - position << " -> "; cin >> numElements;

	v.erase(v.begin() + position, v.begin() + position + numElements);

	cout << "    ����� �i��� ��������� �������i�: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "    ����i� ������: " << v.size() << endl;

	// 7. ���������� �������� �I������� ������ �� ����������
	cout << "\n7. ���������� �������� �I������� ������ �� ����������" << endl;
	cout << "  ����i�� ������� �i������� �i� 0 �� " << v.size() - 1 << " -> "; cin >> rangeStart;
	cout << "  ����i�� �i���� �i������� �i� " << rangeStart + 1 << " �� " << v.size() - 1 << "-> "; cin >> rangeEnd;

	stable_sort(v.begin() + rangeStart, v.begin() + rangeEnd + 1, greater<int>());

	cout << "    ����� �i��� ���������� �������� �i������� �� ����������: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "I����i������� ��������" << endl;

	// ��������� �� i�i�i��i���i� ������i� v1 �� v2
	vector<int> v1;
	vector<int> v2(10, 0);

	vector<int> values = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	v1.insert(v1.end(), values.begin(), values.end());

	cout << "  ��������� ���������� ������i�:" << endl;
	cout << "    ������ v1: ";
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "    ������ v2: ";
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	replace_copy_if(v1.begin(), v1.end(), v2.begin(), In_30_70, 5);

	cout << "��������� ������������ ������i�:" << endl;
	cout << "    ������ v1: ";
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "    ������ v2: ";
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
