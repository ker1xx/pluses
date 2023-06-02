#include <Windows.h>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

class Animal {
protected:
    string Name;
public:
    Animal(string Name) {
        this->Name = Name;
    }
    Animal() {};
};
class Pet  {
protected:
      int NeedEat, GiveEat;
public:
    Pet(  int NeedEat,   int GiveEat) {
        this->NeedEat = NeedEat;
        this->GiveEat = GiveEat;
    };
    virtual void feed() {};

};
class Cat : public Animal, Pet {
public:

    Cat(string Name,   int NeedEat,   int GiveEat): Animal(Name), Pet(NeedEat, GiveEat) {
        this->Name = Name;
        this->NeedEat = NeedEat;
        this->GiveEat = GiveEat;
    }
    void feed(string& Name,   int &NeedEat,   int &GiveEat) {
        if (this->GiveEat + 10 < GiveEat || this->GiveEat - 10 > NeedEat)
            cout << "котик сдох(" << endl;
        else
            cout << "УРА КОТ ВЫЖИЛ!!" << endl;
    }
};
class Dog : public Animal, Pet {
public:
    Dog(string Name,   int NeedEat,   int GiveEat) : Animal(Name), Pet(NeedEat, GiveEat) {
        this->Name = Name;
        this->NeedEat = NeedEat;
        this->GiveEat = GiveEat;
    }
    void feed(string& Name,   int& NeedEat,   int& GiveEat) {
        if (this->GiveEat + 10 < GiveEat || this->GiveEat - 10 > NeedEat)
            cout << "собачка сдохла(" << endl;
        else
            cout << "УРА САБАКА ВЫЖИЛА!!" << endl;
    }
};


int main()
{
    setlocale(0, "ru");
    SetConsoleCP(1251);
    srand(time(0));
      int random1 = 1 + rand() % 101;
      int random2 = 1 + rand() % 101;
    string NameOfCat;
    string NameOfDog;
      int InputEatForCat, InputEatForDog;
    cout << "Введите имя кота" << endl;
    cin >> NameOfCat;    
    cout << "Введите количество корма для кота" << endl;
    cin >> InputEatForCat;
    cout << "Введите имя собаки" << endl;
    cin >> NameOfDog;    
    cout << "Введите количество корма для собака" << endl;
    cin >> InputEatForDog;
    Cat newCat(NameOfCat, random1, InputEatForCat);
    Dog NewDog(NameOfDog, random2, InputEatForDog);
    newCat.feed(NameOfCat, random1, InputEatForCat);
    NewDog.feed(NameOfCat, random1, InputEatForCat);
}

