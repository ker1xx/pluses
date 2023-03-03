#include <Windows.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int FindAverage(int* array, int size)
{
	int avg = 0;
	for (int i = 0; i < size; i++)
	{
		avg += array[i];
	}
	avg = avg / size;
	return avg;
}
int main()
{
	SetConsoleCP(1251);
	setlocale(0, "Russian");
	int size, avg;
	cout << "Введите размер массива: ";
	cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Введите элемент массива: " << endl;
		cin >> array[i];
		cin.clear();
		cout.clear();
	}
	avg = FindAverage(array, size);
	int *px = &avg;
	cout << "Среднее арифметическое элементов массива равно: " << *px << endl;
}