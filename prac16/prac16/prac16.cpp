#include <memory>
#include <Windows.h>
#include <string>
#include <iostream>
#include <regex>
#include <memory>

using namespace std;

class PersonException
{
public:
	PersonException(string message) : message{ message } {}
	string getMessage() const {
		return message;
	}
private:
	string message;
};

class Person {
private:
	string name;
	unsigned short age;
	unsigned short id;
public:
	Person(string name, unsigned short age, unsigned short id) {
		try {
			if (age > 100)
			{
				throw PersonException{ "Invalid age" };
			}
			if (!regex_match(name, regex("^[А-Яа-я]+$")))
			{
				throw PersonException{ "Wrong name" };
			}
			this->name = name;
			this->age = age;
			this->id = id;
		}
		catch (const PersonException error) {
			cout << error.getMessage() << endl;
		}
	}
	string getname() {
		return name;
	}
	unsigned short getage() {
		return age;
	}
	unsigned short getid() {
		return id;
	}
};
shared_ptr <Person> func(string name, unsigned short age, unsigned id)
{
	return shared_ptr <Person>(new Person(name, age, id));
}
shared_ptr <Person> print(shared_ptr <Person> person) {
	cout << "Имя: " << person->getname() << " Возраст: " << person->getage() << " ID: " << person->getid();
	return person;
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	string name;
	unsigned short age, id;
	cout << "введите имя: " << endl;
	cin >> name;
	cout << "введите возраст: " << endl;
	cin >> age;
	cout << "введите id: " << endl;
	cin >> id;
	try
	{
		shared_ptr <Person> newperson(func(name, age, id));
		shared_ptr <Person> newperson2 = print(newperson);
	}
	catch (const char* error)
	{
		cout << "Ошибка: " << error << endl;
	}
}
