#include <vector>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct Person {
public:
    string Name;
    int Age;
    Person(string Name, int Age) {
        this->Name = Name;
        this->Age = Age;
    }
    virtual void displayinfo(Person person)
    {
        cout << "Имя: " << person.Name << ", Возраст: " << person.Age << endl;
    }
};
class People {
    static int PeopleCount;
    vector <Person> collection;
public:
    void addPerson(Person person) {
        collection.push_back(person);
        PeopleCount++;
        cout << person.Name << " добавлен(а) в коллекцию" << endl;
    };
    static void dispalyCount() {
        cout << "Количество людей в коллекции: " << PeopleCount << endl;
    };
    ~People() {
        cout << "Программа завершена. " << endl;
    };
    void showPerson() {
        for (Person p : collection) {
            p.displayinfo(p);
        }
    }

};
int People::PeopleCount = 0;

int main()
{
    setlocale(0, "ru");
    SetConsoleCP(1251);
    People people;
    Person Person1 {"Вася", 25 };
    Person Person2 {"Люся", 35 };
    people.addPerson(Person1);
    people.addPerson(Person2);
    people.dispalyCount();
    people.showPerson();
    return 0;
}
