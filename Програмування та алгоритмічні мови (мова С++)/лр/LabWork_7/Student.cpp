#include "Student.h"

Student::Student()
	:surname("-"), name("-"), patronymic("-"), dateOfBirth(0), address("-"), phoneNumber("+380__-___-__-__"), faculty("-"), course(0) {}

Student::Student(const string& surname, const string& name, const string& patronymic, const int& dateOfBirth, const string& address, const string& phoneNumber, const string& faculty, const int& course)
	:surname(surname), name(name), patronymic(patronymic), dateOfBirth(dateOfBirth), address(address), phoneNumber(phoneNumber), faculty(faculty), course(course) {}

Student::Student(const Student& s)
	:surname(s.surname), name(s.name), patronymic(s.patronymic), dateOfBirth(s.dateOfBirth), address(s.address), phoneNumber(s.phoneNumber), faculty(s.faculty), course(s.course) {}


string Student::get_surname() const { return surname; }
string Student::get_name() const { return name; }
string Student::get_patronymic() const { return patronymic; }
int Student::get_dateOfBirth() const { return dateOfBirth; }
string Student::get_address() const { return address; }
string Student::get_phoneNumber() const { return phoneNumber; }
string Student::get_faculty() const { return faculty; }
int Student::get_course() const { return course; }


void Student::set_all(const string& surname, const string& name, const string& patronymic, const int& dateOfBirth, const string& address, const string& phoneNumber, const string& faculty, const int& course)
{
	this->surname = surname;
	this->name = name;
	this->patronymic = patronymic;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
	this->phoneNumber = phoneNumber;
	this->faculty = faculty;
	this->course = course;
}
void Student::set_surname(string surname) { this->surname = surname; }
void Student::set_name(string name) { this->name = name; }
void Student::set_patronymic(string patronymic) { this->patronymic = patronymic; }
void Student::set_dateOfBirth(int dateOfBirth) { this->dateOfBirth = dateOfBirth; }
void Student::set_address(string address) { this->address = address; }
void Student::set_phoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }
void Student::set_faculty(string faculty) { this->faculty = faculty; }
void Student::set_course(int course) { this->course = course; }

void Student::show() const
{
	cout << "ПІБ: " << surname << " " << name << " " << patronymic << endl;
	cout << dateOfBirth << "p.,  м. " << address << ",  т. " << phoneNumber << endl;
	cout << "факультет " << faculty << ", " << course << "-й курс" << endl << endl;
}

void Student::readbin()
{
	writebin();

	ifstream fin("data.bin", ios::binary);
	if (fin) {
		string buf;
		int len{};
		fin.read((char*)&len, sizeof(len));
		buf.resize(len);
		fin.read(&buf[0], len);
		fin.close();

		size_t pos = buf.find(';');
		surname = buf.substr(0, pos);
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		name = buf.substr(0, pos);
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		patronymic = buf.substr(0, pos);
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		dateOfBirth = stoi(buf.substr(0, pos));
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		address = buf.substr(0, pos);
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		phoneNumber = buf.substr(0, pos);
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		faculty = buf.substr(0, pos);
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		course = stoi(buf.substr(0, pos));
	}
	else {
		cout << "File not found." << endl;
		fin.close();
	}
}

void Student::writebin()
{
	string buf;

	string surnames[] = { "Муляр","Юрчак","Місевич","Овдієнко","Міняйло","Боровко","Найда","Коломиєць","Носаль","Юзвенко" };
	buf = surnames[rand() % surnames->size()] + ';';

	string namesM[] = { "Остап","Василь","Слава","Костянтин","Юрій","Кирило","Олексій" };
	string namesW[] = { "Єкатерина","Ірина","Діана","Зоряна","Леся","Барбара","Тетяна" };
	string patronymics[] = { "Ярослав","Валентин","Іван","Костянтин","Федор","Денис","Юхим","Ігор","Леонід","Максим" };
	string name, patronymic;
	if (rand() % 2 == 0) {
		buf += namesW[rand() % namesW->size()] + ';';
		buf += patronymics[rand() % patronymics->size()] + "івна" + ';';
	}
	else {
		buf += namesM[rand() % namesM->size()] + ';';
		buf += patronymics[rand() % patronymics->size()] + "ович" + ';';
	}

	buf += to_string(rand() % 51 + 1955) + ';';

	string cities[] = { "Городенка","Ківерці","Перещепине","Тлумач","Світловодськ","Маріуполь","Дунаївці","Бердичів","Герца","Красногорівка" };
	buf += cities[rand() % cities->size()] + ';';

	string codes[] = { "050","063","066","067","068","093","094","095","096","097","098","099" };
	buf += "+38" + codes[rand() % codes->size()] + "-";
	for (int i = 0; i < 7; i++) {
		buf += to_string(rand() % 10);
		if (i == 2 || i == 4)
			buf += "-";
	}
	buf += ';';

	string faculties[] = { "КН", "КІУ", "АКТ", "ІТМ", "ІК", "ЕЛБІ", "ІРТЗІ" };
	buf += faculties[rand() % (sizeof(faculties) / sizeof(faculties[0]))] + ';';

	buf += to_string(rand() % 6 + 1) + ';';

	ofstream fout("data.bin", ios::binary);
	int len = buf.size();
	fout.write((char*)&len, sizeof(int));
	fout.write(buf.data(), buf.size());
	fout.close();
}

void task1(const Student* students, const int n)
{
	bool flag = true;
	string f{ "" };
	cout << "Введіть факультет з доступного переліку: КН, КІУ, АКТ, ІТМ, ІК, ЕЛБІ, ІРТЗІ\n -> ";
	cin >> f; cout << endl;
	if (f == "КН" || f == "КІУ" || f == "АКТ" || f == "ІТМ" || f == "ІК" || f == "ЕЛБІ" || f == "ІРТЗІ") {
		flag = true;
		for (int i = 0; i < n; i++)
			if (students[i].get_faculty() == f) {
				students[i].show();
				flag = false;
			}
		if (flag)
			cout << "У списку немає студентів обраного факультету" << endl;
	}
	else
		cout << "Невірно введена назва факультету або такий факультет відсутній в університеті" << endl;
}

void task2(const Student* students, const int n)
{
	bool flag = true;
	string faculties[] = { "КН", "КІУ", "АКТ", "ІТМ", "ІК", "ЕЛБІ", "ІРТЗІ" };
	for (int j = 0; j < sizeof(faculties) / sizeof(faculties[0]); j++) {
		cout << "\tФакультет " << faculties[j] << ":\n" << endl;
		flag = true;
		for (int i = 0; i < n; i++)
			if (students[i].get_faculty() == faculties[j]) {
				students[i].show();
				flag = false;
			}
		if (flag)
			cout << "У списку немає студентів даного факультету\n" << endl;
	}
	for (int j = 1; j <= 6; j++) {
		cout << "\t" << j << "й курс:\n" << endl;
		flag = true;
		for (int i = 0; i < n; i++)
			if (students[i].get_course() == j) {
				students[i].show();
				flag = false;
			}
		if (flag)
			cout << "У списку немає студентів даного факультету\n" << endl;
	}
}

void task3(const Student* students, const int n)
{
	bool flag = true;
	int y{};
	cout << "Введіть рік (1955-2005)\n -> ";
	cin >> y; cout << endl;
	if (y >= 1955 && y <= 2005) {
		flag = true;
		for (int i = 0; i < n; i++)
			if (students[i].get_dateOfBirth() > y) {
				students[i].show();
				flag = false;
			}
		if (flag)
			cout << "У списку немає студентів народжених після цього року" << endl;
	}
	else
		cout << "Введений рік не знаходиться у доступному діапазоні" << endl;
}