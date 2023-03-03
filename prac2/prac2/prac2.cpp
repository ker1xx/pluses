// prac2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>
//#include
using namespace std;

int enter();
void sum();
void difference();
void multiplication();
void division();
void degree();
void radical();
void procent();


void main()
{
	unsigned short int number_of_operation;
	while (true)
	{
		number_of_operation = enter();
		switch (number_of_operation)
		{
		case 1:
			sum();
			break;
		case 2:
			difference();
			break;
		case 3:
			multiplication();
			break;
		case 4:
			division();
			break;
		case 5:
			degree();
			break;
		case 6:
			radical();
			break;
		case 7:
			procent();
			break;
		case 0:
			return;
			break;
		}
	}
}

int enter()
{
	unsigned short int enter_number;
	int a = 0;
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	cout << "Выберете операцию: \n";
	cout << "1. Сложение \n";
	cout << "2. Вычитание \n";
	cout << "3. Умножение \n";
	cout << "4. Деление \n";
	cout << "5. Возведение в степень \n";
	cout << "6. Вычисление квадратного корня \n";
	cout << "7. Найти процент от числа \n";
	cout << "0. Выйти из программы \n";
	cout << "Введите номер операции без пробела или точки: \n";
	cin >> enter_number;
	return enter_number;
}
void sum()
{
	float first, second;
	cout << "Введите первое число: ";
	cin >> first;
	if (first == 0)
		return;
	cout << "\nВведите второе число: ";
	cin >> second;
	if (second == 0)
		return;
	cout << "Сумма введенных чисел равна: " << first + second<< "\n";
}
void difference()
{
	float first, second;
	cout << "Введите первое число: ";
	cin >> first;
	if (first == 0)
		return;
	cout << "\nВведите второе число: ";
	cin >> second;
	if (second == 0)
		return;
	cout << "Разность введенных чисел равна: " << first - second << "\n";
}
void multiplication()
{
	float first, second;
	cout << "Введите первое число: ";
	cin >> first;
	if (first == 0)
		return;
	cout << "\nВведите второе число: ";
	cin >> second;
	if (second == 0)
		return;
	cout << "Произведение введенных чисел равна: " << first * second << "\n";

}
void division()
{
	float first, second;
	cout << "Введите первое число: ";
	cin >> first;
	if (first == 0)
		return;
	cout << "\nВведите второе число: ";
	cin >> second;
	if (second == 0)
		return;
	cout << "Частное введенных чисел равна: " << first / second << "\n";
}
void degree()
{
	float first, second;
	cout << "Введите первое число: ";
	cin >> first;
	if (first == 0)
		return;
	cout << "\nВведите степень, в которую нужно возвести число: ";
	cin >> second;
	if (second == 0)
		return;
	cout << second << " степень числа " << first << " равна : " << pow(first,second) << "\n";
}
void radical()
{
	float first;
	cout << "Введите число: ";
	cin >> first;
	if (first == 0)
		return;
	cout << "Квадратный корень из числа " << first << " равен " << sqrt(first) << "\n";
}
void procent()
{
	float first;
	cout << "Введите число: ";
	cin >> first;
	if (first == 0)
		return;
	cout << "Процент из числа " << first << " равен " << first/100 << "\n";
}
