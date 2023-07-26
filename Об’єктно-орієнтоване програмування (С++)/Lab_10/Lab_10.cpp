#include <iostream>
#include <iomanip>
#include "Header.h"
#include <cassert>
using namespace std;

template <class T>
T min_(const T& a, const T& b) {
	return (a < b) ? a : b;
}
//template <class T>
//T min(T mas) {
//	T min = mas[0];
//	for (int i = 1; i < size(mas); i++)
//		if (mas[i] < min)
//			min = mas[i];
//	return min;
//}
template <class T>
void sort(T mas) {
	for (int i = 0; i < 10 - 1; i++)
		for (int j = 0; j < 10 - i - 1; j++)
			if (mas[j] > mas[j + 1])
				swap(mas[j], mas[j + 1]);
}
template <class T>
T sum(T mas) {
	T sum; //= mas[0];
	int j;
	for (int i = 0; i < 10; i++)
		if (mas[i] > 0) {
			sum = mas[i];
			j = i;
			break;
		}
	//for (int i = 1; i < 10; i++)
	for (int i = 0; i < 10; i++)
		if (mas[i] > 0 && i != j)
			sum += mas[i];
	return sum;
}

int main() {
	setlocale(LC_ALL, "ru");
	//srand(time(NULL));
	{
		cout << min_(1, 2) << endl;
		cout << min_(-1, -2) << endl;
		cout << min_(1, -2) << endl;

		cout << min_(1.1, 2.2) << endl;
		cout << min_(-1.1, -2.2) << endl;
		cout << min_(1.1, -2.2) << endl;

		cout << min_('a', 'b') << endl;
	}

	/////////////////////////////////////////////////////////////
	{
		int mas1[10]{ 7,10,8,2,4,5,3,1,6,9 };
		int mas2[10]{ 1,2,3,4,5,6,7,8,9,10 };

		sort(mas1);
		for (int i = 0; i < 10; i++)
			cout << mas1[i] << " ";
		cout << endl << endl;

		for (int i = 0; i < 10; i++)
			assert(mas1[i] == mas2[i]);
	}

	{
		double mas1[10]{ 7.7,10.1,8.8,2.2,4.4,5.5,3.3,1.1,6.6,9.9 };
		double mas2[10]{ 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.1 };

		sort(mas1);
		for (int i = 0; i < 10; i++)
			cout << mas1[i] << " ";
		cout << endl << endl;

		for (int i = 0; i < 10; i++)
			assert(mas1[i] == mas2[i]);
	}

	{
		char mas1[10]{ 'g','j','h','b','d','e','c','a','f','i' };
		char mas2[10]{ 'a','b','c','d','e','f','g','h','i','j' };

		sort(mas1);
		for (int i = 0; i < 10; i++)
			cout << mas1[i] << " ";
		cout << endl << endl;

		for (int i = 0; i < 10; i++)
			assert(mas1[i] == mas2[i]);
	}
	/////////////////////////////////////////////////////////////
	//{
	//	int mas[10]{ -5,-4,-3,-2,-1,1,2,3,4,5 };
	//	int summas = sum(mas);
	//	assert(summas == 15);
	//}
	//{
	//	double mas[10]{ -5.5,-4.4,-3.3,-2.2,-1.1,1.1,2.2,3.3,4.4,5.5 };
	//	double summas = sum(mas);
	//	assert(summas == 16.5);
	//}
	//{
	//	char mas2[10]{ 'a','b','c','d','e','f','g','h','i','j' };
	//	char summas = sum(mas);
	//	assert(summas == (char)1015);
	//}


	cout << "\n\n\n\n\n";
	return 0;
}