#include <iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

class Word {
	int size;
	 char *w = new char[1];
public:
	Word() {}
	Word(int k) { if (k < 65535) { size = k; w = new char[size]; } else  Word(); }
	~Word() { delete[] w;  }
	Word& operator= (Word& A) { this->w=A.w; }
	friend istream& operator >>(istream& in, Word& word) 
	{

		gets_s(word.w);
	
		return in;

	}
	friend ostream& operator <<(ostream& out, Word& wo) { out << "You input: " << wo.w; return out; }
};

int main() {
	Word t(7);
	cin >> t;
	cout << t;
	

	
	return 0;
}
