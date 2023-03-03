#include <string>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> FromSmallest(vector <int> vect)
{
    sort(vect.begin(), vect.end());
    return vect;
}
vector<int> FromBiggest(vector <int> vect)
{
    sort(vect.begin(), vect.end());
    reverse(vect.begin(), vect.end());
    return vect;

}
vector<int> Operation(vector<int>(*op)(vector<int>), vector <int> vect)
{
    return op(vect);
}
int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    int size,result;
    vector<int> vect;
    srand(time(0));
    cout << "Введите размер массива: " << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        vect.push_back(rand() % 100);
        cout << vect.at(i) << "\t";
    }
    cout << endl;
    vect = Operation(FromSmallest, vect);
    for (int i = 0; i < size; i++)
    {
        vect.push_back(rand() % 100);
        cout << vect.at(i) << "\t";
    }
    cout << endl;
    vect = Operation(FromBiggest, vect);
    for (int i = 0; i < size; i++)
    {
        vect.push_back(rand() % 100);
        cout << vect.at(i) << "\t";
    }
}

