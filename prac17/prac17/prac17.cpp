#include <iostream>
#include <string>
#include <list>
#include <forward_list>
#include <queue>
#include <stack>
#include <array>
#include <Windows.h>

using namespace std;

struct Book {
private:
	string name;
	string author;
	string genre;
	int year;
public:
	Book(string name, string author, string genre, int year)
	{
		this->name = name;
		this->genre = genre;
		this->author = author;
		this->year = year;
	}
	string getname()
	{
		return name;
	}
	string getauthor() {
		return author;
	}
	string getgenre() {
		return genre;
	}
	int getyear() {
		return year;
	}
};

void showbook(Book book) {
	cout << "название: " << book.getname() << "\tавтор: " << book.getauthor() << "\tжанр: " << book.getgenre() << "\tгод: " << book.getyear() << endl;
}
Book createbook() {
	string name, author, genre;
	int year;
	cout << "введите название: " << endl;
	cin >> name;
	cout << "введите автора: " << endl;
	cin >> author;
	cout << "введите жанр: " << endl;
	cin >> genre;
	cout << "введите год издания: " << endl;
	cin >> year;
	Book book{ name,author,genre,year };
	return book;
}
bool comparingyear(Book book1, Book book2)
{
	if (book1.getyear() < book2.getyear())
		return true;
	else
		return false;
}

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	array<Book, 5> ar{ Book{"","","",0},Book{"","","",0},Book{"","","",0},Book{"","","",0},Book{"","","",0} };
	vector<Book> vct{};
	list<Book> lt;
	forward_list<Book> flt;
	for (int i = 0; i < 5; i++)
	{
		Book newbook = createbook();
		ar[i] = newbook;
		vct.push_back(newbook);
		lt.push_back(newbook);
		flt.push_front(newbook);
	}
	cout << "это стек:" << endl;
	for (int i = vct.size()-1; i >= 0; i--)
	{
		
		showbook(vct[i]);
	}
	list<Book> temp = lt;
	cout << "это куеуе: " << endl;
	for (int i = 0; i < lt.size(); i++)
	{
		showbook(temp.front());
		temp.pop_front();
	}
	priority_queue <int> year;
	cout << " это приорити куеуе: " << endl;
	for (int i = 0; i < ar.size(); i++)
	{
		year.push(ar[i].getyear());
	}
	priority_queue <int> year1; 
	year1.swap(year);
	for (int i = year1.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < vct.size(); j++)
		{
			if (year1.top() == vct[j].getyear())
			{
				showbook(vct[j]);
				year1.pop();
				break;
			}
		}
	}
}