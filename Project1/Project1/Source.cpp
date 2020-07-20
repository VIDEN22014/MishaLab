/*
¬ар≥ант 12. —творити клас Aqueue Ц структура типу черга, що базуЇтьс€ на масив≥ покажчик≥в ф≥ксованого розм≥ру.
ѕередбачити, щоб черга мала можлив≥сть вм≥щувати значенн€ типу, що в≥дпов≥даЇ б≥бл≥отечному класу string.
ѕередбачити функц≥њ Ц члени класу дл€ виконанн€ таких операц≥й:
аdd() Ц занести у чергу надане значенн€;
pop() Ц добути ≥ вилучити значенн€ ≥з черги;
print() Ц вивести ус≥ значенн€ ≥з черги на екран;
num() Ц повернути к≥льк≥сть значень, що знаход€тьс€ у черз≥;
isempty() Ц повернути значенн€ true (тип bool), €кщо черга пуста.

\\м≥н€й на св≥й
*/

#include <iostream>
#include <Windows.h>
using namespace std;

class aQueue
{
public:
	aQueue();
	aQueue(string x);
	~aQueue();
private:
	class data
	{
	public:
		data(string x)
		{
			this->dani = x;
			this->next = nullptr;
		}
		~data()
		{
			delete next;
		}
		string Getdata() { return dani; }
		data* next;
	private:
		string dani;
	};

	data* head;
	data* tail;

public:

	void add(string x)
	{
		if (head == nullptr)
		{
			tail = head = new data(x);
		}
		else
		{
			tail->next = new data(x);
			tail = tail->next;
		}
	}

	string pop()
	{
		string x = head->Getdata();
		data* del = head;
		head = head->next;
		del->next = nullptr;
		delete del;
		return x;
	}

	void print()
	{
		cout << "¬с≥ дан≥ в черз≥:" << endl;
		data* scroll = head;
		while (scroll != nullptr)
		{
			cout << scroll->Getdata() << " " << endl;
			scroll = scroll->next;
		}
	}
	int num()
	{
		int num = 0;
		data* scroll = head;
		while (scroll != nullptr)
		{
			num++;
			scroll = scroll->next;
		}
		return num;
	}
	bool isempty()
	{
		if (head == nullptr)
		{
			return true;
		}
	}

};

aQueue::aQueue()
{
	tail = head = nullptr;
}

aQueue::aQueue(string x)
{
	tail = head = new data(x);
}

aQueue::~aQueue()
{
	delete head;
	delete tail;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	aQueue x;
	x.add("lol");
	x.add("x");
	x.add("z");

	x.print();
	x.pop();
	x.print();
	//cout << "Hello World!\n";
}
