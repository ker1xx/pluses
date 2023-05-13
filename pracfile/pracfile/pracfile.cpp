#include <fstream>
#include <string>
#include <Windows.h>
#include <iostream>
using namespace std;

template <class T> 
class Serialization {
public:
void    Serializtion() {};
    void save(string file_name, T object);
    void load(string file_name, T& object);
};
template <class T> 
void Serialization<T>::save(string fileNmae, T object) {
    object.write(fileNmae);
}
template<class T>
void Serialization<T>::load(string fileNmae, T& object) {
    object.read(fileNmae);
}
class Person {
public:
    string name;
    int age;
    Person(string name, int age);
    Person() {};
    void write(string fileNmae);
    void read(string fileNmae);
};
Person::Person(string name, int age) {
    this->name = name;
    this->age = age;
}
void Person::write(string fileNmae) {
std:ofstream out(fileNmae);
    out << name << " " << age << endl;
    out.close();
}
void Person::read(string fileNmae) {
    ifstream in(fileNmae);
    if (in.is_open()) {
        getline(in, name);
        in >> age;
    }
    in.close();
}

void main()
{
    setlocale(0, "ru");
    SetConsoleCP(0);
    Person p("sanya", 25);
    Serialization<Person> s;
    s.save("file.txt", p);

    Person new_p("",0);
    s.load("file.txt", new_p);
    new_p.age = stoi(new_p.name.substr(new_p.name.find_last_of(" ")));
    new_p.name = new_p.name.substr(0, new_p.name.find_last_of(" "));
    cout << new_p.name << " - " << new_p.age << endl;
}
