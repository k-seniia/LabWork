#include <iostream>
#include <cmath>
#include <iomanip>
#include <climits>

using namespace std;

void fill(int* mas, int s, int n); void print(int* mas, int s); void sort(int* arr, int s);
int mean(int* mas, int s); int median(int* mas, int s); int maxe(int* mas, int s); void slide(int* mas, int s);

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int n{}; cout << " n -> "; cin >> n;
    //n = rand() % 5; cout << "n -> " << n << endl;
    int s = n + 15;
    int* mas = new int[s];
    fill(mas, s, n);
    print(mas, s);

    int sa = mean(mas, s); cout << " mean = " << sa << endl;
    int med = median(mas, s); cout << " median = " << med << endl << endl;

    if (med > sa) {
        cout << " median > mean -> " << med << " > " << sa << endl;
        int max = maxe(mas, s); cout << " max = " << max << endl;
        for (int i = 0; i < s; i++)
            mas[i] -= max;
        print(mas, s);
    }
    else {
        cout << " median <= mean -> " << med << " <= " << sa << endl;
        sort(mas, s);
        int** masX = new int* [s];
        for (int i = 0; i < s; i++) {
            masX[i] = mas;
            print(masX[i], s);
            slide(mas, s);
        }
        //for (int i = 0; i < s; i++)
            //delete[] masX[i];
        delete[] masX;
    }
    delete[] mas;
    
    return 0;
}

void fill(int* mas, int s, int n) {
    for (int i = 0; i < s; i++)
        mas[i] = rand() % ((n + 15) - (-n - 15) + 1) + (-n - 15);
}

void print(int* mas, int s) {
    for (int i = 0; i < s; i++)
        cout << setw(5) << mas[i];
    cout << endl;
}

void sort(int* mas, int s) {
    for (int i = 0; i < s - 1; i++)
        for (int j = 0; j < s - i - 1; j++)
            if (mas[j] > mas[j + 1])
                swap(mas[j], mas[j + 1]);
}

void slide(int* mas, int s) {
    int temp = mas[0];
    for (int i = 0; i < s - 1; i++)
        mas[i] = mas[i + 1];
    mas[s - 1] = temp;
}

int mean(int* mas, int s) {
    int sum{};
    for (int i = 0; i < s; i++)
        sum += mas[i];
    return sum / s;
}

int median(int* mas, int s) {
    for (int i = 0; i < s; i++) {
        int max = 0, min = 0;
        for (int j = 0; j < s; j++)
            if (i != j) {
                if (mas[i] > mas[j])
                    min++;
                else
                    max++;
            }
        if (s % 2 == 1 && min == max)
            return mas[i];
        else if (s % 2 == 0 && min == max - 1)
            return mas[i];
    }
}

int maxe(int* mas, int s) {
    int max = INT_MIN;
    for (int i = 0; i < s; i++)
        if (mas[i] > max)
            max = mas[i];
    return max;
}