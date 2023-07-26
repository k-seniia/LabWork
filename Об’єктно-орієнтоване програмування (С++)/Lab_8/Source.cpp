#include "Header.h"
#include <iomanip>
#include <cassert>

template <class T> MAS<T>::MAS() :size(100), ind(0) {}

template <class T> void MAS<T>::fill(const int& ind) {
	assert(ind < size);
	this->ind = ind;
	if (sizeof(mas[0]) == sizeof(int))
		mas[ind] = rand() % 50;
	else if (sizeof(mas[0]) == sizeof(double))
		mas[ind] = (double)(rand() % 50) / 10;
	else if (sizeof(mas[0]) == sizeof(char))
		mas[ind] = 'a' + rand() % 26;
}

template <class T> T MAS<T>::sum(){
	T sum = mas[0];
	for (int i = 1; i < ind; i++)
		sum += mas[i];
	return sum;
}

template <class T> T MAS<T>::SA(){
	return this->sum() / (T)ind;
}

template <class T> void MAS<T>::print(){
	if (sizeof(mas[0]) == sizeof(int))
		for (int i = 0; i < ind; i++)
			cout << setw(4) << mas[i];
	else if (sizeof(mas[0]) == sizeof(double))
		for (int i = 0; i < ind; i++)
			cout << setw(5) << mas[i];
	else if (sizeof(mas[0]) == sizeof(char))
		for (int i = 0; i < ind; i++)
			cout << setw(2) << "'" << mas[i] << "'";
	cout << endl;
}

//template <class TT> ostream& operator<<(ostream& out, const MAS<TT>& ob) {
//	if (sizeof(ob.mas[0]) == sizeof(int))
//		for (int i = 0; i < ob.ind; i++)
//			out << setw(4) << ob.mas[i];
//	else if (sizeof(ob.mas[0]) == sizeof(double))
//		for (int i = 0; i < ob.ind; i++)
//			out << setw(5) << ob.mas[i];
//	else if (sizeof(ob.mas[0]) == sizeof(char))
//		for (int i = 0; i < ob.ind; i++)
//			out << setw(3) << ob.mas[i];
//	out << endl;
//	return out;
//}


template <class T> T MAS<T>::operator[](int li){
	assert(li <= ind);
	T max = mas[0];
	for (int i = 1; i < li; i++)
		if (max < mas[i])
			max = mas[i];
	return max;
}
template <class T> MAS<T>::~MAS() { delete [] mas; }

template MAS<int>;
template MAS<double>;
template MAS<char>;