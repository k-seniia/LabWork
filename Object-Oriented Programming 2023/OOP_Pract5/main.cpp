#include "DList.h"

int main() {
	/*  DList<int> dlist;
	  dlist.pushFront(50);
	  dlist.pushFront(40);
	  dlist.pushFront(30);
	  dlist.pushFront(20);
	  dlist.pushFront(10);

	  cout << "DList: " << dlist << endl;

	  dlist.removeAt(2);

	  cout << "DList after removing element at position 2: " << dlist << endl;

	  DList<int> otherDList;
	  otherDList.pushFront(50);
	  otherDList.pushFront(40);
	  otherDList.pushFront(30);
	  otherDList.pushFront(20);
	  otherDList.pushFront(10);

	  if (dlist != otherDList) {
		  cout << "DLists are not equal" << endl;
	  }

	  DList<char> charList;
	  charList.pushFront('e');
	  charList.pushFront('d');
	  charList.pushFront('c');
	  charList.pushFront('b');
	  charList.pushFront('a');

	  cout << "CharList: " << charList << endl;

	  DList<int> intList;
	  intList.pushFront(10);
	  intList.pushFront(20);
	  intList.pushFront(30);
	  intList.pushFront(40);
	  intList.pushFront(50);
	  intList.pushFront(60);
	  intList.pushFront(70);
	  intList.pushFront(80);
	  intList.pushFront(90);

	  cout << "Integer List: " << intList << endl;
	  cout << "Size: " << intList.size() << endl;

	  DList<char> charList2;
	  charList2.pushBack('A');
	  charList2.pushBack('B');
	  charList2.pushBack('C');
	  charList2.pushBack('D');
	  charList2.pushBack('E');

	  cout << "Character List: " << charList2 << endl;
	  cout << "Size: " << charList2.size() << endl;

	  DList<double> doubleList;
	  doubleList.pushBack(1.5);
	  doubleList.pushBack(2.5);
	  doubleList.pushBack(3.5);

	  cout << "Double List: " << doubleList << endl;
	  cout << "Size: " << doubleList.size() << endl;*/

	  //try {
	  //    DList<int> myList(5);
	  //    myList.pushFront(10);
	  //    myList.pushFront(20);
	  //    myList.pushFront(30);
	  //    myList.pushFront(40);
	  //    myList.pushFront(50);

	  //    // Генерація виняткової ситуації при спробі додати елемент, коли контейнер вже заповнений
	  //    myList.pushFront(60);
	  //}
	  //catch (const overflow_error& e) {
	  //    cout << "Caught exception: " << e.what() << endl;
	  //}
	  //catch (const out_of_range& e) {
	  //    cout << "Caught exception: " << e.what() << endl;
	  //}

	  //try {
	  //    // Тестування класу DList з типом int
	  //    DList<int> intList(5);
	  //    intList.pushBack(10);
	  //    intList.pushBack(20);
	  //    intList.pushBack(30);
	  //    intList.pushBack(40);
	  //    intList.pushBack(50);
	  //    intList.pushBack(60); // Генерує виняток ContainerFullException
	  //}
	  //catch (const exception& ex) {
	  //    cout << "Exception occurred: " << ex.what() << endl;
	  //}

	  //try {
	  //    // Тестування класу DList з типом char
	  //    DList<char> charList(0); // Генерує виняток invalid_argument
	  //}
	  //catch (const exception& ex) {
	  //    cout << "Exception occurred: " << ex.what() << endl;
	  //}

	  //try {
	  //    // Тестування класу DList з типом double
	  //    DList<double> doubleList(3);
	  //    doubleList.pushBack(1.5);
	  //    doubleList.pushBack(2.5);
	  //    doubleList.pushBack(3.5);
	  //    doubleList.removeInRange(2.0, 4.0);
	  //    double maxItem = doubleList.findMax(); // Генерує виняток EmptyContainerException
	  //}
	  //catch (const exception& ex) {
	  //    cout << "Exception occurred: " << ex.what() << endl;
	  //}

	try {
		DList<B1> listB1;
		listB1.pushFront(B1(1, 1, 1));
		listB1.pushFront(B1(2, 2, 2));
		listB1.pushFront(B1(3, 3, 3));
		listB1.pushFront(B1(4, 4, 4));
		listB1.pushFront(B1(5, 5, 5));

		cout << "DList: " << listB1 << endl;
	}
	catch (const exception& ex) {
		cout << "Exception occurred: " << ex.what() << endl;
	};

	return 0;
}
