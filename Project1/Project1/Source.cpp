#include <iostream>
#include <Windows.h>
using namespace std;

class Word {
	int size;
	char *w;
public:
	Word() { size = 1; w = new char[size]; }
	Word(int k) { if (k < 65535) { size = k; w = new char[size]; } else  Word(); }
	~Word() { delete[] w; }
	Word& operator= (Word& A) { strcpy(this->w, A.w); }

};

int main() {
	Word t(7);

	setlocale(LC_ALL, "ru");
	
	return 0;
}
