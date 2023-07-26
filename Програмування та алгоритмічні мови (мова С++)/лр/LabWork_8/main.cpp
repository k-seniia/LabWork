#include"Vector.h"

#define DEBUG

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	srand(time(NULL));
	cout << setprecision(3);

#ifdef DEBUG
	Vector v1(rand() % 100 / 10. - 5, rand() % 100 / 10. - 5, rand() % 100 / 10. - 5);
#else
	Vector v1;
	cout << " Введіть координати вектора v1:" << endl; cin >> v1; cout << endl;
#endif // DEBUG
	cout << " v1 ( " << x(v1) << " , " << y(v1) << " , " << z(v1) << " )" << endl;

	Vector v2(rand() % 100 / 10. - 5, rand() % 100 / 10. - 5, rand() % 100 / 10. - 5);
	cout << " v2 " << v2 << endl;

	cout << "\n Скалярний добуток v1 та v2 -> " << v1 * v2 << endl;

	cout << "\n Довжина вектору v1 -> " << lenght(v1) << endl;
	cout << "\n Довжина вектору v2 -> " << lenght(v2) << endl;

	cout << "\n Кут між двома векторами v1 та v2 -> " << angel(v1, v2) << "°" << endl;

	Vector v3 = v1 ^ v2;
	cout << "\n Векторний добуток двох векторів v1 та v2 -> " << v3 << endl;

	v1 += v2;
	cout << "\n v1 += v2 \t->\tv1 " << v1 << endl;

	v1 -= v2;
	cout << "\n v1 -= v2 \t->\tv1 " << v1 << endl;

	v1 *= v2;
	cout << "\n v1 *= v2 \t->\tv1 " << v1 << endl;

	v3 = v1 + v2;
	cout << "\n v3 = v1 + v2 \t->\tv3 " << v3 << endl;

	v1 = v3 - v2;
	cout << "\n v1 = v3 - v2 \t->\tv1 " << v1 << endl;

	double d = rand() % 50 / 10. + 0.1;
	v3 = v2 * d;
	cout << "\n v3 = v2 * " << d << " \t->\tv3 " << v3 << endl;

	d = rand() % 50 / 10. + 0.1;
	v1 = d * v2;
	cout << "\n v1 = " << d << " * v2 \t->\tv1 " << v1 << endl;

	return 0;
}