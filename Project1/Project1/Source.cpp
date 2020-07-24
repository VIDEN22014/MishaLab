//На основі 2лб варіанта 2
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;


struct Book;

class Catalog {
public:
	class List {
	public:
		struct Book
		{
			string name;
			string author;

		}book;
		List* next;
		List(Book a, List* p = nullptr) { book = a; next = p; };
		string Get_info() { return book.name + ", " + book.author; }
	};
	List* head;

	Catalog() { head = nullptr; }
	~Catalog() {}

	void insetup(string path = "file.txt", ofstream::openmode mode = 1);
	string outsetup(string path = "file.txt");

	void add_book(List::Book a) {
		if (head == nullptr)
		{
			head = new List(a);
		}
		else {
			List* temp = this->head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new List(a);
		}
	}
	void del_book() {
		List* temp = head;
		while (temp != nullptr)
		{
			if (temp->next == nullptr) {
				head = nullptr;

			}
			else if (temp->next->next == nullptr) {
				temp->next = nullptr;
			}
			temp = temp->next;
		}
	}
	void show_cataloque() {
		List* temp = head;
		cout << "Books Catalouqe : " << endl;
		while (temp != nullptr) {
			cout << temp->book.author << " -- " << temp->book.name << endl;
			temp = temp->next;
		}
		cout << endl;
	}
	void find_by_author(string auth) {
		List* temp = head;
		cout << "Book by author : " << auth << endl;
		while (temp != nullptr && temp->book.author == auth) {
			cout << temp->book.name << endl;
			temp = temp->next;
		}
	}
};

//

void Catalog::insetup(string path, ofstream::openmode mode)
{
	ifstream buf(path);
	string str;
	getline(buf, str);
	buf.close();
	if (str != "Data in queue:")
	{
		ofstream insetup(path);
		if (!insetup.is_open())
		{
			cout << "Помилка запису у файл." << endl;
			return;
		}
		insetup << "Data in queue:" << endl;
		insetup.close();
	}


	ofstream insetup(path, fstream::app);
	if (!insetup.is_open())
	{
		cout << "Помилка запису у файл." << endl;
		return;
	}

	List* scroll = head;
	while (scroll != nullptr)
	{
		insetup << scroll->Get_info() << " " << endl;
		scroll = scroll->next;
	}

	insetup << "----------------------------------" << endl;
	insetup.close();
}

string Catalog::outsetup(string path)
{
	string out = "";
	string buf = "";
	ifstream outsetup(path);
	if (!outsetup.is_open())
	{
		cout << "Помилка читання файлу." << endl;
		return "";
	}

	while (!outsetup.eof())
	{
		getline(outsetup, buf);
		out += buf + "\n";
		buf = "";
	}
	outsetup.close();
	return out;
}
//

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Catalog::List::Book b;
	b.name = "C++ for Begginers";
	b.author = "Byarne Stroustrup";

	Catalog a;
	a.add_book(b);
	b.author = "Bruce Ekkel";
	b.name = "Thinking in C++";
	a.add_book(b);

	a.show_cataloque();

	a.insetup();

	a.del_book();
	a.show_cataloque();
	a.del_book();
	a.del_book();
	a.del_book();
	return 0;
}
// готово епта