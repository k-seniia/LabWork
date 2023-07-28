#include "Phone.h"

Phone::Phone() = default;

Phone::Phone(const string& surname, const string& firstName, const string& middleName, 
	const string& address, const string& number, int localCallTime, int longDistanceCallTime)
	: m_surname(surname),
	m_firstName(firstName),
	m_middleName(middleName),
	m_address(address),
	m_number(number),
	m_localCallTime(localCallTime),
	m_longDistanceCallTime(longDistanceCallTime) {}

string Phone::getFullName() const
{
	return m_firstName + " " + m_middleName + " " + m_surname;
}

string Phone::getAddress() const
{
	return m_address;
}

string Phone::getNumber() const
{
	return m_number;
}

int Phone::getLocalCallTime() const
{
	return m_localCallTime;
}

int Phone::getLongDistanceCallTime() const
{
	return m_longDistanceCallTime;
}

void Phone::generateRandomData()
{
	static const string surnames[] = { "Smith", "Johnson", "Williams", "Jones", "Brown" };
	static const string firstNames[] = { "John", "Michael", "Robert", "David", "William" };
	static const string middleNames[] = { "Christopher", "Joseph", "Thomas", "Daniel", "Matthew" };
	static const string addresses[] = { "123 Main St", "456 Elm St", "789 Oak St", "321 Pine St", "654 Maple St" };

	m_surname = surnames[rand() % 5];
	m_firstName = firstNames[rand() % 5];
	m_middleName = middleNames[rand() % 5];
	m_address = addresses[rand() % 5];
	m_number = "555-" + to_string(rand() % 9000 + 1000);
	m_localCallTime = rand() % 100;
	m_longDistanceCallTime = rand() % 100;
}

istream& operator>>(istream& in, Phone& phone)
{
	cout << "Enter surname -> "; in >> phone.m_surname;
	cout << "Enter first name -> "; in >> phone.m_firstName;
	cout << "Enter middle name -> "; in >> phone.m_middleName;
	cout << "Enter address -> "; in >> phone.m_address;
	cout << "Enter number -> "; in >> phone.m_number;
	cout << "Enter local call time -> "; in >> phone.m_localCallTime;
	cout << "Enter long distance call time -> "; in >> phone.m_longDistanceCallTime;
	return in;
}

ostream& operator<<(ostream& out, const Phone& phone)
{
	out << "Full Name: " << phone.getFullName()
		<< ", Address: " << phone.m_address
		<< ", Number: " << phone.m_number
		<< ", \nLocal Call Time: " << phone.m_localCallTime
		<< " minutes, Long Distance Call Time: " << phone.m_longDistanceCallTime
		<< " minutes" << endl;
	return out;
}