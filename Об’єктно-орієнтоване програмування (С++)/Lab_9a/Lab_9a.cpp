#include <iostream>
#include <iomanip>
#include "Header.h"
#include <map>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	//srand(time(NULL));

	map <NAME, NUMBER> book;
	map <NAME, NUMBER> ::iterator it;
	book.insert({ NAME("Newton"), NUMBER("621(93)091-37-91") });
	book.insert({ NAME("Sanders"), NUMBER("4(7603)879-61-75") });
	book.insert({ NAME("Caldwell"), NUMBER("422(219)299-67-97") });
	book.insert({ NAME("Wilson"), NUMBER("355(69)570-18-87") });
	book.insert({ NAME("Simon"), NUMBER("301(3390)991-68-93") });

	for (const auto& b : book)
		cout << b.first << " - " << b.second << endl;
	
	cout << "\n\n\n";

	string N1;
	cout << "Enter name: "; cin >> N1;
	it = book.find(NAME(N1));
	cout << (it == book.end() ? (NUMBER)"Record not found" : (*it).second) << endl; //?

	cout << "\n\n\n";

	for (it = book.lower_bound((NAME)"S"); it != book.lower_bound((NAME)"T"); it++)
		cout << it->first << " - " << (*it).second << endl;

	cout << "\n\n\n";

	/*for (const auto& b : book)
		if () {
			cout << "Deleting: " << b.first << endl;
			it = b;
			book.erase(it);
	}*/
	for (auto p = begin(book); p != end(book); ) {

		if (const_cast<NAME&>(p->first).get_name().substr(0,1) == "S")
			p = book.erase(p);
		else
			p++;
	}


	cout << "\n\n\n";

	for (const auto& b : book)
		cout << b.first << " - " << b.second << endl;

	cout << "\n----\n\n";

	for (const auto& b : book)
		cout << const_cast<NAME&>(b.first).get_name() << " - " << b.second << endl;

	cout << "\n----\n\n";

	for (auto p = begin(book); p != end(book); p++)
		cout << const_cast<NAME&>(p->first).get_name() << endl;

	cout << "\n\n\n\n\n";
	return 0;
}