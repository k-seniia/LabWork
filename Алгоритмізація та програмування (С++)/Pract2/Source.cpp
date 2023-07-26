#include <iostream>
#include <cmath>
#include <iomanip>
//������� ����������� ������. ������� �����.
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	
	//---------------------------------------------------------------------------------------------------------------
	cout << "\n\n----- �������� 1 -----\n\n";

	int const s1 = 14;
	int mas1[s1], count1{};
	
	for (int i = 0; i < s1; i++) {
		//cout << "����i�� " << i << "-� ������� ������ -> ";
		//cin >> mas1[i];
		mas1[i] = rand() % 100 + 1;
		if (mas1[i] % 2 == 0)
			count1++;
	}
	
	cout << "\n����� [";
	for (int i = 0; i < s1; i++) {
		cout << setw(4) << mas1[i];
	}
	cout << "  ]\n\n�i���i��� ������ �������i� = " << count1 << endl;

	
	cout << "\n\n\n"; system("Pause");
	//---------------------------------------------------------------------------------------------------------------
	cout << "\n\n----- �������� 2 -----\n\n";

	int const s2 = 11;
	int mas2[s2], count2{}, sum2{};
	
	for (int i = 0; i < s2; i++) {
		//cout << "����i�� " << i << "-� ������� ������ -> ";
		//cin >> mas2[i];
		mas2[i] = rand() % 100 + 1;
		sum2 += mas2[i];
	}
	
	double mean2 = sum2 / s2;
	
	for (int i = 0; i < s2; i++) {
		if (mas2[i] > mean2)
			count2++;
	}
	
	cout << "\n����� [";
	for (int i = 0; i < s2; i++) {
		cout << setw(4) << mas2[i];
	}
	cout << "  ]\n\n������ ����������� = " << mean2 
		 << "\n\n�i���i��� �������i� �i����� �� �� = " << count2 << endl;


	cout << "\n\n\n"; system("Pause");
	//---------------------------------------------------------------------------------------------------------------
	cout << "\n\n----- �������� 3 -----\n\n";

	int const s3 = 10;
	int mas3[s3], max3 = INT_MIN, max3_i{};
	
	for (int i = 0; i < s3; i++) {
		//cout << "����i�� " << i << "-� ������� ������ -> ";
		//cin >> mas3[i];
		mas3[i] = rand() % 100 + 1;
		if (mas3[i] > max3) {
			max3 = mas3[i];
			max3_i = i;
		}
	}
	
	cout << "\n����� [";
	for (int i = 0; i < s3; i++) {
		cout << setw(4) << mas3[i];
	}
	cout << "  ]\n\nmax = " << max3;
	
	int temp = mas3[0];
	mas3[0] = mas3[max3_i];
	mas3[max3_i] = temp;
	
	cout << "\n\n����� [";
	for (int i = 0; i < s3; i++) {
		cout << setw(4) << mas3[i];
	}
	cout << "  ]" << endl;


	cout << "\n\n\n"; system("Pause");
	//---------------------------------------------------------------------------------------------------------------
	cout << "\n\n----- �������� 4 -----\n\n";

	int const s4 = 20;
	int mas4[s4], count4_p{}, count4_n{};
	
	for (int i = 0; i < s4; i++) {
		//cout << "����i�� " << i << "-� ������� ������ -> ";
		//cin >> mas4[i];
		mas4[i] = rand() % 100 + 1;
		if (mas4[i] % 2 == 0)
			count4_p++;
		else
			count4_n++;
	}
	
	cout << "\n����� [";
	for (int i = 0; i < s4; i++) {
		cout << setw(4) << mas4[i];
	}
	cout << "  ]\n\n�i���i��� ������ �������i� = " << count4_p 
		 << "\n\n�i���i��� �������� �������i� = " << count4_n << endl;
	
	if (count4_p > count4_n)
		cout << "\n������ �������i� �i����" << endl;
	else if (count4_p < count4_n)
		cout << "\n�������� �������i� �i����" << endl;
	else
		cout << "\n������ �� �������� �������i� ���i���" << endl;


	cout << "\n\n\n"; system("Pause");
	//---------------------------------------------------------------------------------------------------------------
	cout << "\n\n----- �������� 5 -----\n\n";

	int const s5 = 16;
	double mas5[s5], max5 = INT_MIN, max5_i{}, min5 = INT_MAX, min5_i{};
	
	for (int i = 0; i < s5; i++) {
		//cout << "����i�� " << i << "-� ������� ������ -> ";
		//cin >> mas5[i];
		mas5[i] = rand() % 100 / (float)10;
		if (mas5[i] > max5) {
			max5 = mas5[i];
			max5_i = i;
		}
		if (mas5[i] < min5) {
			min5 = mas5[i];
			min5_i = i;
		}
	}
	
	cout << "\n����� [";
	for (int i = 0; i < s5; i++) {
		cout << setw(5) << mas5[i];
	}
	cout << "  ]\n\n" << max5_i << "-� ������� ������ - max = " << max5 
		 << "\n\n" << min5_i << "-� ������� ������ - min = " << min5 << endl;


	cout << "\n\n\n"; system("Pause");
	//---------------------------------------------------------------------------------------------------------------
	cout << "\n\n----- �������� 6 -----\n\n";

	int const s6 = 15;
	int mas6[s6], mas6_m[s6], sum6{};
	
	for (int i = 0; i < s6; i++) {
		//cout << "����i�� " << i << "-� ������� ������ -> ";
		//cin >> mas6[i];
		mas6[i] = rand() % 100 + 1;
		sum6 += mas6[i];
	}
	
	double mean6 = sum6 / s6;
	
	cout << "\n����� [";
	for (int i = 0; i < s6; i++) {
		cout << setw(4) << mas6[i];
	}
	cout << "  ]\n\n������ ����������� = " << mean6 << "\n\n����� [";
	for (int i = 0; i < s6; i++) {
		mas6_m[i] = mas6[i] - mean6;
		cout << setw(4) << mas6_m[i];
	}
	cout << "  ]" << endl;


	cout << "\n\n\n"; system("Pause");
	//---------------------------------------------------------------------------------------------------------------
	cout << "\n\n----- �������� 7 -----\n\n";

	int const s7 = 14;
	int mas7[s7], count7{}, sum7{};
	
	for (int i = 0; i < s7; i++) {
		//cout << "����i�� " << i << "-� ������� ������ -> ";
		//cin >> mas7[i];
		mas7[i] = rand() % 100 - 25;
		if (mas7[i] % 2 == 0 && mas7[i] > 0) {
			count7++;
			sum7 += mas7[i];
		}
	}
	
	cout << "\n����� [";
	for (int i = 0; i < s7; i++) {
		cout << setw(4) << mas7[i];
	}
	cout << "  ]\n\n�i���i��� ������ �������� �������i� = " << count7 
		 << "\n\n���� ������ �������� �������i� = " << sum7 << endl;


	cout << "\n\n\n"; system("Pause");
	//---------------------------------------------------------------------------------------------------------------
	cout << "\n\n----- �������� 8 -----\n\n";

	int const s8 = 12;
	double mas8[s8], max8 = INT_MIN, min8 = INT_MAX;
	
	for (int i = 0; i < s8; i++) {
		//cout << "����i�� " << i << "-� ������� ������ -> ";
		//cin >> mas8[i];
		mas8[i] = rand() % 100 / (float)10;
		if (mas8[i] > max8)
			max8 = mas8[i];
		if (mas8[i] < min8)
			min8 = mas8[i];
	}
	
	cout << "\n����� [";
	for (int i = 0; i < s8; i++) {
		cout << setw(5) << mas8[i];
	}
	cout << "  ]\n\n" << "max = " << max8 << "\n+\nmin = " << min8
		 << "\n\nsum = " << max8 + min8 << "\n\n����� [";
	for (int i = 0; i < s8-1; i++) {
		for (int j = 0; j < s8 - i - 1; j++) {
			if (mas8[j] < mas8[j + 1]) {
				double temp = mas8[j];
				mas8[j] = mas8[j + 1];
				mas8[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < s8; i++) {
		cout << setw(5) << mas8[i];
	}
	cout << "  ]" << endl;


	cout << "\n\n\n"; system("Pause");
	//---------------------------------------------------------------------------------------------------------------
	cout << "\n\n----- �������� 9 -----\n\n";

	int const s9 = 17;
	int mas9[s9], sum9{};
	
	for (int i = 0; i < s9; i++) {
		//cout << "����i�� " << i << "-� ������� ������ -> ";
		//cin >> mas9[i];
		mas9[i] = rand() % 50 + 1;
		if (mas9[i] % 2 != 0)
			sum9 += mas9[i];
	}
	
	cout << "\n����� [";
	for (int i = 0; i < s9; i++) {
		cout << setw(4) << mas9[i];
	}
	cout << "  ]\n\n���� �������� �������i� = " << sum9 << "\n\n����� [";
	for (int i = 0; i < s9; i++) {
		if (mas9[i] % 3 == 0)
			mas9[i] = sum9;
		cout << setw(4) << mas9[i];
	}
	cout << "  ]" << endl;


	cout << "\n\n\n"; system("Pause");
	//---------------------------------------------------------------------------------------------------------------
	cout << "\n\n----- �������� 10 -----\n\n";

	int const s10 = 12;
	double mas10[s10], max10 = INT_MIN, max10_i{}, min10 = INT_MAX, min10_i{};
	
	for (int i = 0; i < s10; i++) {
		//cout << "����i�� " << i << "-� ������� ������ -> ";
		//cin >> mas10[i];
		mas10[i] = rand() % 100 / (float)10;
		if (mas10[i] > max10) {
			max10 = mas10[i];
			max10_i = i;
		}
		if (mas10[i] < min10) {
			min10 = mas10[i];
			min10_i = i;
		}
	}
	
	cout << "\n����� [";
	for (int i = 0; i < s10; i++) {
		cout << setw(5) << mas10[i];
	}
	cout << "  ]\n\n" << "max = " << max10 << "\n\nmin = " << min10 
		 << "\n\n�i���i��� ����� �i� max i min = ";
	if (max10_i > min10_i) {
		cout << max10_i - min10_i - 1 << endl;
	}
	if (max10_i < min10_i) {
		cout << min10_i - max10_i - 1 << endl;
	}


	cout << "\n\n\n"; system("Pause");
	//---------------------------------------------------------------------------------------------------------------
	cout << "\n\n\n\n\n";
	return 0;
}