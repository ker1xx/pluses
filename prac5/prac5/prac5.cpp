#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

void FillUpMatrix(vector <vector <int>> &matrix, int n, int m)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < m;j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}
void PrintMatrix(vector <vector <int>> matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < m;j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
void FindMinMax(vector <vector <int>> matrix,int n, int m, int &min, int &max)
{
    min = matrix[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (matrix[i][j] < min)
                min = matrix[i][j];
            if (matrix[i][j] > max)
                max = matrix[i][j];
        }

    }
}
void FindAverage(vector <vector <int>> matrix, int n, int m, float &avg)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < m;j++)
        {
            avg += matrix[i][j];
        }
    }
    avg = avg / (n * m);
}

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    int n, m, min, max = 0;
    float avg = 0;
    cout << "Введите количество строк и столбцов в матрице: ";
    cin >> n >> m;
    vector < vector  <int> > matrix(n, vector<int>(m));
    FillUpMatrix(matrix,n,m);
    PrintMatrix(matrix, n, m);
    FindMinMax(matrix, n, m, min, max);
    cout << "\nМинимальное значение в данной матрице: " << min << "\nМаксимальное значение в данной матрице: " << max;
    FindAverage(matrix, n, m, avg);
    cout << "\nСреднее значение матрицы равно: " << avg;

}