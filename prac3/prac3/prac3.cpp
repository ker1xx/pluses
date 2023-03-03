#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	string input_string;
	int input_number;
	unsigned long long factorial = 1;
	short int sum_of_all_inputed_numbers = 0;
	bool is_digit = true;
	while (input_string != "End")
	{
		is_digit = true;
		cout << "/////////////////////////////////////" << endl;
		cout.clear();
		cout << "Введите ваше число: " << endl;
		cout.clear();
		if (cin >> input_string)
		{
			for (int i = 0; i < input_string.length();i++)
			{
				if (isdigit(input_string[i]) || input_string[i] == '-')
					continue;
				else
				{
					is_digit = false;
					break;
				}
			}
			if (is_digit == true)
			{
				input_number = stoi(input_string);
				if (input_number < 0)
				{
					cout << "Вы ввели отрицательное число" << endl;
					cout.clear();
				}
				else if (input_number == 0)
				{
					cout << "Вы ввели ноль" << endl;
					cout.clear();
				}
				else
				{
					cout << "Вы ввели положительное число" << endl;
					cout.clear();
					for (int i = 1; i <= input_number;i++)
					{
						factorial = factorial * i;
					}
					cout << "Факториал введенного вами числа равен: " << factorial << endl;
					cout.clear();
					factorial = 1;
					sum_of_all_inputed_numbers += input_number;
				}
			}
			else
			{
				cout << "Вы ввели не число" << endl;
				cout.clear();
				cin.clear();
			}
			cout << "/////////////////////////////////////" << endl;
			cout.clear();
		}
		if (input_string == "End")
			break;
		input_string = "";
		cin.clear();
	}
	cout << "Сумма всех введенных чисел равна: " << sum_of_all_inputed_numbers << endl;
}

