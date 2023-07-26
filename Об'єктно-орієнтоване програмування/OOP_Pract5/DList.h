#pragma once
#include <iostream>
#include <stdexcept>
#include <exception>
#include "B1.h"
using namespace std;

// Виняток, що виникає при перевищенні максимального розміру контейнера
class ContainerFullException : public exception {
public:
	const char* what() const noexcept override {
		return "Container is full";
	}
};

// Виняток, що виникає при некоректному доступі до елементів контейнера
class OutOfBoundsException : public exception {
public:
	const char* what() const noexcept override {
		return "Index out of bounds";
	}
};


// Виняток, що виникає при динамічному виділенні пам’яті.
class MemoryAllocationException : public exception {
public:
	const char* what() const noexcept override {
		return "Memory allocation failed";
	}
};

// Виняток, що виникає при спробі видалити елемент з порожнього контейнера
class EmptyContainerException : public exception {
public:
	const char* what() const noexcept override {
		return "Container is empty";
	}
};

// Оголошення класу DList
template <typename T>
class DList {
private:
	// Оголошення внутрішнього класу Node
	class Node {
	public:
		T data;
		Node* prev;
		Node* next;

		Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
	};

	Node* head;				// вказівник на початок контейнера
	Node* tail;				// вказівник на кінець контейнера
	size_t currentSize;		// поточний розмір контейнера
	size_t maxSize;			// максимальний розмір контейнера

public:
	// конструктори
	DList(size_t maxSize = numeric_limits<size_t>::max()) : head(nullptr), tail(nullptr), currentSize(0), maxSize(maxSize)
	{
		if (maxSize == 0) {
			throw invalid_argument("Max size must be greater than 0");
		}
		if (maxSize > numeric_limits<size_t>::max()) {
			// TODO при спробі створити контейнер більше максимального розміру
		}
	}

	DList(const DList& other) : head(nullptr), tail(nullptr), currentSize(0), maxSize(other.maxSize)
	{
		Node* current = other.head;
		while (current != nullptr) {
			pushBack(current->data);
			current = current->next;
		}
	}

	// деструктор
	~DList()
	{
		while (head != nullptr) {
			Node* nextNode = head->next;
			delete head;
			head = nextNode;
		}
	}

	// перевантажену операцію присвоювання ("=")
	DList& operator=(const DList& other)
	{
		if (this != &other) {
			clear();
			maxSize = other.maxSize;
			Node* current = other.head;
			while (current != nullptr) {
				pushBack(current->data);
				current = current->next;
			}
		}
		return *this;
	}

	// ++ додати елемент в початок (item + dlist)
	void pushFront(const T& value)
	{
		if (currentSize >= maxSize) {
			throw ContainerFullException();
		}

		Node* newNode;
		try {
			newNode = new Node(value);
		}
		catch (const bad_alloc& e) {
			throw MemoryAllocationException();
		}
		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		currentSize++;
		//maxSize = currentSize > maxSize ? currentSize : maxSize;
	}

	// Операція додавання елементу
	void pushBack(const T& value)
	{
		if (currentSize == maxSize) {
			throw overflow_error("List is full");
		}

		Node* newNode;
		try {
			newNode = new Node(value);
		}
		catch (const bad_alloc& e) {
			throw MemoryAllocationException();
		}
		if (tail == nullptr) {
			head = tail = newNode;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		currentSize++;
		//maxSize = currentSize > maxSize ? currentSize : maxSize;
	}

	// - pos видалити елемент списку в позиції pos
	void removeAt(size_t pos)
	{
		if (currentSize == 0) {
			throw logic_error("Container is empty");
		}
		if (pos >= currentSize) {
			throw out_of_range("Invalid position");
		}

		if (pos == 0) {
			Node* temp = head;
			head = head->next;
			if (head != nullptr) {
				head->prev = nullptr;
			}
			else {
				tail = nullptr;
			}
			delete temp;
		}
		else {
			Node* current = head;
			for (size_t i = 0; i < pos; i++) {
				current = current->next;
			}

			Node* prevNode = current->prev;
			Node* nextNode = current->next;
			if (prevNode != nullptr) {
				prevNode->next = nextNode;
			}
			if (nextNode != nullptr) {
				nextNode->prev = prevNode;
			}
			if (current == tail) {
				tail = prevNode;
			}
			delete current;
		}

		currentSize--;
	}

	// додавання елемента до контейнеру
	void insertAt(size_t pos, const T& value)
	{
		if (size == maxSize) {
			throw overflow_error("List is full");
		}
		if (pos > currentSize) {
			throw out_of_range("Invalid position");
		}

		if (pos == 0) {
			pushFront(value);
		}
		else if (pos == currentSize) {
			pushBack(value);
		}
		else {
			Node* current = head;
			for (size_t i = 0; i < pos - 1; i++) {
				current = current->next;
			}

			Node* newNode;
			try {
				newNode = new Node(value);
			}
			catch (const bad_alloc& e) {
				throw MemoryAllocationException();
			}
			Node* nextNode = current->next;

			current->next = newNode;
			newNode->prev = current;
			newNode->next = nextNode;
			nextNode->prev = newNode;

			currentSize++;
		}
		//maxSize = currentSize > maxSize ? currentSize : maxSize;
	}

	// != перевірка на нерівність
	bool operator!=(const DList& other) const
	{
		if (currentSize != other.currentSize) {
			return true;
		}

		Node* current1 = head;
		Node* current2 = other.head;
		while (current1 != nullptr && current2 != nullptr) {
			if (current1->data != current2->data) {
				return true;
			}
			current1 = current1->next;
			current2 = current2->next;
		}

		return false;
	}

	void clear()
	{
		Node* current = head;
		while (current != nullptr) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
		head = tail = nullptr;
		currentSize = 0;
	}

	// Операція доступу до елементу
	T& operator[](size_t pos)
	{
		if (pos >= currentSize || pos < 0) {
			throw OutOfBoundsException();
		}

		Node* current = head;
		for (size_t i = 0; i < pos; i++) {
			current = current->next;
		}

		return current->data;
	}

	const T& operator[](size_t pos) const
	{
		if (pos >= currentSize || pos < 0) {
			throw out_of_range("Invalid position");
		}

		Node* current = head;
		for (size_t i = 0; i < pos; i++) {
			current = current->next;
		}

		return current->data;
	}

	// Пошук елемента в контейнері
	bool findItem(const T& item) const
	{
		Node* current = head;
		while (current != nullptr) {
			if (current->data == item) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	// Пошук мінімального елемента в контейнері
	T findMin() const
	{
		if (currentSize == 0) {
			throw logic_error("List is empty");
		}

		Node* current = head;
		T minValue = current->data;
		while (current != nullptr) {
			if (current->data < minValue) {
				minValue = current->data;
			}
			current = current->next;
		}

		return minValue;
	}

	// Пошук максимального елемента в контейнері
	T findMax() const
	{
		if (currentSize == 0) {
			throw logic_error("List is empty");
		}

		Node* current = head;
		T maxValue = current->data;
		while (current != nullptr) {
			if (current->data > maxValue) {
				maxValue = current->data;
			}
			current = current->next;
		}

		return maxValue;
	}

	// Видалення елементів з контейнера, що належать до заданого діапазону
	void removeInRange(const T& start, const T& end)
	{
		if (currentSize == 0) {
			throw EmptyContainerException();
		}

		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			if (current->data >= start && current->data <= end) {
				if (current == head) {
					head = current->next;
				}
				else {
					current->prev->next = current->next;
				}

				if (current == tail) {
					tail = current->prev;
				}
				else {
					current->next->prev = current->prev;
				}

				delete current;
				--currentSize;
			}
			current = next;
		}
	}

	size_t size() const
	{
		return currentSize;
	}

	size_t getMaxSize() const
	{
		return maxSize;
	}

	// операції введення
	friend istream& operator>>(istream& in, DList& dlist)
	{
		T value;
		while (in >> value) {
			dlist.pushBack(value);
		}
		return in;
	}

	// операції виведення
	friend ostream& operator<<(ostream& out, const DList& dlist)
	{
		Node* current = dlist.head;
		while (current != nullptr) {
			out << current->data << " ";
			current = current->next;
		}
		return out;
	}
};
