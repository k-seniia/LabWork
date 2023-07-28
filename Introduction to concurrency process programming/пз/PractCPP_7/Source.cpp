#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Account {
public:
	int balance{ 100 };
	mutex m;

	friend void transferMoney(int amount, Account& from, Account& to);
};

void transferMoney(int amount, Account& from, Account& to) {
	unique_lock<mutex> lock_from(from.m, defer_lock);
	unique_lock<mutex> lock_to(to.m, defer_lock);
	lock(lock_from, lock_to);
	if (from.balance >= amount) {
		from.balance -= amount;
		to.balance += amount;
	}
}

int main() {

	Account account1;
	Account account2;

	thread t1(transferMoney, 50, ref(account1), ref(account2));
	thread t2(transferMoney, 130, ref(account2), ref(account1));

	t1.join();
	t2.join();

	cout << "account1.balance -> " << account1.balance << endl;
	cout << "account2.balance -> " << account2.balance << endl;

}