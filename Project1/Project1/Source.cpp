#include <iostream>
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
	};
	List* head;

	Catalog() { head = nullptr; }
	~Catalog() {}

	void add_book(List::Book a) {
		if (head==nullptr)
		{
			head = new List(a);
		}
		else {
			List* temp=this->head;
			while (temp->next!=nullptr)
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
			else if(temp->next->next == nullptr) {
				temp->next = nullptr;
			}
			temp = temp->next;
		}
	}
	void show_cataloque() {
		List* temp=head;
		cout << "Books Catalouqe : " << endl;
		while (temp != nullptr) {
			cout << temp->book.author<<" -- " << temp->book.name<<endl;
			temp = temp->next;
		}
		cout << endl;
	}
	void find_by_author(string auth) {
		List* temp = head;
		cout << "Book by author : " << auth << endl;
		while (temp != nullptr&& temp->book.author==auth) {
			cout << temp->book.name << endl;
			temp = temp->next;
		}
	}
};

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
	a.del_book();
	a.show_cataloque();
	a.del_book();
	a.del_book();
	a.del_book();
	return 0;
}
