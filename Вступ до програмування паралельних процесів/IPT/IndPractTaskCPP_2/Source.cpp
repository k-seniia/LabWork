#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;

bool run = true;

//«курник»
class HenHouse {
	int portions;				// кількість порцій їжі у мисці
	int all_portion;			// загальна кількість порцій
	mutex m;
	condition_variable cv;
public:
	HenHouse(const int& portions) :portions(portions) {
		cout << "\t\tamount of portions " << portions << endl;
		all_portion = portions;
	}

	int get_all() { return all_portion; }

	friend class Chicken;
	friend class Hen;
};

//«курча»
class Chicken {
	int id;					// номер("ім'я") курча
	int ate;				// скільки курча з'їло порцій
	HenHouse& house;
public:
	Chicken(int id, HenHouse& house) :id(id), house(house), ate(0) {}

	void eat_sleep() {
		while (run) {
			unique_lock<mutex>lock(house.m);
			while (house.portions == 0)
				house.cv.wait(lock);
			if (house.portions > 0) {
				house.portions--;
				ate++;
				cout << " chicken " << id << " - eating\t" << "\t rest of portions " << house.portions << endl;
				//this_thread::sleep_for(std::chrono::milliseconds(250));
			}
			lock.unlock();
			house.cv.notify_all();
		}
	}

	friend ostream& operator<<(ostream& out, const Chicken& ch) {
		out << "\tchicken " << ch.id << " ate - " << ch.ate << " portions" << endl;
		return out;
	}
};

//«квочка»
class Hen {
	HenHouse& house;
public:
	Hen(HenHouse& house) :house(house) {}

	void fill() {
		int i{};
		while (run) {
			unique_lock<mutex> lock(house.m);
			while (house.portions > 0)
				house.cv.wait(lock);
			house.portions += rand() % 50 + 1;
			cout << "\t\tHen add " << house.portions << " portions " << endl;
			house.all_portion += house.portions;
			this_thread::sleep_for(std::chrono::milliseconds(500));
			lock.unlock();
			house.cv.notify_all();

			// умова виходу з циклу (зупинки роботи потоків)
			i++;
			if (i == 10)
				run = false;
		}
	}
};


int main() {
	srand(time(nullptr));

	HenHouse house(rand() % 50 + 1);

	Hen hen(house);

	thread hen_thread(&Hen::fill, hen);

	vector<Chicken> chickens;
	for (int i = 0; i < rand() % 20 + 1; i++)
		chickens.emplace_back(i + 1, house);

	cout << "\tamount of chikens " << chickens.size() << endl;

	vector<thread> chickens_threads;
	for (int i = 0; i < chickens.size(); i++)
		chickens_threads.emplace_back(&Chicken::eat_sleep, ref(chickens[i]));

	hen_thread.join();
	for (auto& t : chickens_threads)
		t.join();

	cout << "\n\ttotal amount of portions - " << house.get_all() << endl << endl;
	for (auto& ch : chickens)
		cout << ch;

	return 0;
}