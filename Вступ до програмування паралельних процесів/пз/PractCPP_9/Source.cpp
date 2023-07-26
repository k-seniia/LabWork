#include <iostream>
#include <vector>
#include <future>
using namespace std;

vector<int> parallel_quick_sort(vector<int> list) {
	if (list.size() < 2)
		return list;

	// �������� ������� �������
	int sup = list[0];

	// ��������� ������ �� �� �������
	auto it = partition(list.begin() + 1, list.end(), [sup](const int& elem) {
		return elem < sup;
		});

	// ������� ������� ������� � ������� �������
	future<vector<int>> left_future = async(parallel_quick_sort, vector<int>(list.begin() + 1, it));
	future<vector<int>> right_future = async(parallel_quick_sort, vector<int>(it, list.end()));

	// �������� ���������� � ������
	vector<int> left = left_future.get();
	vector<int> right = right_future.get();

	// ��'������ ����������
	vector<int> result;
	result.reserve(left.size() + right.size() + 1);
	move(left.begin(), left.end(), back_inserter(result));
	result.push_back(sup);
	move(right.begin(), right.end(), back_inserter(result));

	return result;
}

int main() {
	srand(time(nullptr));

	vector<int> list;
	for (int i = 0; i < rand() % 30; i++)
		list.push_back(rand() % 50);

	cout << "before: ";
	for (auto& a : list)
		cout << a << " ";
	cout << endl;

	list = parallel_quick_sort(list);

	cout << "after: ";
	for (auto& a : list)
		cout << a << " ";
	cout << endl;

	return 0;
}