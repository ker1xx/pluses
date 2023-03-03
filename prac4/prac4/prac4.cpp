#include <iostream>
#include <Windows.h>
using namespace std;

unsigned long long int number;
unsigned long long int iterrations_count = 0;
unsigned long long int factorial_number = 1;
void factorial(unsigned long long int &number)
{
	iterrations_count++;
	factorial_number = factorial_number * iterrations_count;
	if (iterrations_count != number)
		factorial(number);
	else
		return;
}

void main()
{
	SetConsoleCP(1251);
	setlocale(0, "");
	cout << "Введите число, факториал которого нужно вычислить: " << endl;
	cin >> number;
	if (number == 0)
		cout << "Факториал введенного числа равен: 1";
	else
	{
		factorial(number);
		cout << "Факториал введенного числа равен : " << factorial_number << endl;
	}
}
