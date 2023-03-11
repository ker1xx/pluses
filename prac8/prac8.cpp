#include <string>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;


void CountWordsFirstString(string str)
{
	vector<string> slova;
	int i = 0;
	string word;
	while (i < str.length())
	{
		word += str[i];
		if (isspace(str[i]) || str[i] == '\n')
		{
			slova.push_back(word);
			word = "";
		}
		i++;
	}
	slova.push_back(word);
	cout << slova.size() << endl;
 	for (int i = 0; i < slova.size(); i++)
		cout << slova[i] << endl;
}
void SearchPhoneNumber(string str)
{
	int last = 0;
	string phonenumber = "";
	bool isplus = false;
	int first = 0;
	for (int i = 0;i <= str.length();i++)
	{
		if (isdigit(str[i]))
		{
			last = str.find_last_of("0123456789");
			if (str[i - 1] == '+')
				isplus = !isplus;
			first = i;
			break;
		}
	}
	if (isplus == true)
		phonenumber = str.substr(first - 1, last);
	else
		phonenumber = str.substr(first, last);
	cout << phonenumber << endl;
}
void CompareStrings(string str1, string str2)
{
	string lowerstr1, lowerstr2;
	for (int i = 0; i < str1.length() - 1;i++)
		lowerstr1 += (tolower(str1[i]));
	for (int i = 0; i < str2.length() - 1;i++)
		lowerstr2 += (tolower(str2[i]));
	bool compare{ lowerstr1 == lowerstr2 };
	if (compare == true)
		cout << "Строки 3 и 4 совпадают" << endl;
	else
		cout << "Строки 3 и 4 не совпадают" << endl;
}
void ReplaceSubString(string str1, string str2, string str3)
{
	unsigned int count{};
	vector<int> indexses;
	size_t index{};
	int lenofsubstr = str2.length() - 1;
	for (unsigned i{} ; i<= str1.length()-str2.length();)
	{
		size_t position = str1.find(str2, i);
		if (position == string::npos) break;
		indexses.push_back(position);
		i = position + 1;
	}
	for (int i = 0; i <= indexses.size()-1;i++)
	{
		str1.replace(indexses[i],str2.size(), str3);
	}
	cout << str1 << endl;
}
void main()
{
	SetConsoleCP(1251);
	setlocale(0, "Russian");
	vector<string> str;
	cout << "Введите 7 строк" << endl;
	for (int i = 0; i < 7;i++)
	{
		string stroka;
		getline(cin, stroka);
		str.push_back(stroka);
	}
	CountWordsFirstString(str[0]);
	SearchPhoneNumber(str[1]);
	CompareStrings(str[2], str[3]);
	ReplaceSubString(str[4], str[5], str[6]);
}