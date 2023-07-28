#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

struct TList {
	int x;
	TList* next, * prev;

	TList() : x(0), prev(NULL), next(NULL) {}
	TList(int tt) : x(tt), prev(NULL), next(NULL) {}
};
TList* head = NULL;
TList* tail = NULL;

mutex someM;

void create(int tt);				//Функція створення списку
void print_from_head();				//Функція друку списку з початку
void print_from_tail();				//Функція друку списку з кінця
void insert_befor(int el, int tt);	//Функція додавання перед заданим 
void insert_after(int el, int tt);	//Функція додавання після заданого
void erase(int el);					//Функція видалення елемента списку
bool check_symmetry();				//Функція перевірки на симетрію

int main() {
	//srand(time(NULL));

	for (int i = 0; i < 10; i++)
		create(i * 10);

	int el = rand() % 10 * 10; // 10
	thread th1(insert_befor, el, 111);
	thread th2(print_from_head);
	el = rand() % 10 * 10; // 70
	thread th3(insert_after, el, 222);
	thread th4(print_from_tail);
	el = rand() % 10 * 10; // 40
	thread th5(erase, el);
	thread th6(print_from_head);
	thread th7([]() {cout << "Check for symmetry -> " << boolalpha << check_symmetry() << endl; });

	th1.join();
	th2.join();
	th3.join();
	th4.join();
	th5.join();
	th6.join();
	th7.join();

	return 0;
}

void create(int tt) {
	TList* temp = new TList;

	if (head == NULL) {		//перший елемент (список пустий)
		temp->prev = NULL;
		head = tail = temp;
	}
	else {					//не перший елемент (список не пустий)
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	temp->x = tt;
	temp->next = NULL;
}

void print_from_head() {
	lock_guard<mutex> lockM(someM);
	TList* temp = head;			//вказівник temp на початок списку

	while (temp != NULL) {
		cout << temp->x << " ";
		temp = temp->next;		//перехід до наступного елементу
	}
	cout << endl;
}

void print_from_tail() {
	lock_guard<mutex> lockM(someM);
	TList* temp = tail;			//вказівник temp на кінець списку

	while (temp != NULL) {
		cout << temp->x << " ";
		temp = temp->prev;		//перехід до попереднього елементу
	}
	cout << endl;
}

void insert_befor(int el, int tt) {
	lock_guard<mutex> lockM(someM);
	TList* temp_pos = head;

	while (temp_pos != NULL && temp_pos->x != el) {
		temp_pos = temp_pos->next;
	}
	if (temp_pos == NULL) {
		cout << "Element not found!" << endl;
		return;
	}
	TList* temp = new TList(tt);
	if (temp_pos == head) {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else {
		temp->prev = temp_pos->prev;
		temp->next = temp_pos;
		temp_pos->prev->next = temp;
		temp_pos->prev = temp;
	}
}

void insert_after(int el, int tt) {
	lock_guard<mutex> lockM(someM);
	TList* temp_pos = head;

	while (temp_pos != NULL && temp_pos->x != el) {
		temp_pos = temp_pos->next;
	}
	if (temp_pos == NULL) {
		cout << "Element not found!" << endl;
		return;
	}
	TList* temp = new TList(tt);
	if (temp_pos == tail) {
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	else {
		temp->prev = temp_pos;
		temp->next = temp_pos->next;
		temp_pos->next->prev = temp;
		temp_pos->next = temp;
	}
}

void erase(int el) {
	lock_guard<mutex> lockM(someM);
	TList* temp_pos = head;

	while (temp_pos != NULL && temp_pos->x != el) {
		temp_pos = temp_pos->next;
	}
	if (temp_pos == NULL) {
		cout << "Element not found!" << endl;
		return;
	}
	if (temp_pos == head) {
		head = temp_pos->next;
		if (head != NULL)
			head->prev = NULL;
	}
	else if (temp_pos == tail) {
		tail = temp_pos->prev;
		tail->next = NULL;
	}
	else {
		temp_pos->prev->next = temp_pos->next;
		temp_pos->next->prev = temp_pos->prev;
	}
	delete temp_pos;
}

bool check_symmetry() {
	lock_guard<mutex> lockM(someM);
	TList* left = head;
	TList* right = tail;

	while (left != right && left->prev != right) {
		if (left->x != right->x) {
			return false;
		}
		left = left->next;
		right = right->prev;
	}
	return true;
}