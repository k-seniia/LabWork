#include <iostream>
#include "Header.h"
using namespace std;

int main() {

	Dog d1("d1", 5, 2);
	d1.show_dog();
	//Master m1("HetKs", 3101, "d1", 5, 2);
	//m1.set_Master("HetKs", 3101, d1);
	//Master m1("HetKs", 3101, d1);
	Master m1("HetKs", 3101);
	m1.set_dog(d1, 1);
	m1.show_Master();
	
	Dog d2("d2", 2, 5);
	m1.add_dog(d2);
	m1.show_Master();

	m1.add_dog("d3", 7, 3);
	m1.show_Master();

	Master m2("HetKs", 131, "d4", 10, 4);
	m2.show_Master();

	m2.set_Master("KesHt", 54535);
	m2.show_Master();

	cout << "\n\n\n\n\n";
	return 0;
}