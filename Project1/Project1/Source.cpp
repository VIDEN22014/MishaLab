#include <iostream>
#include <vector>
#include<iterator>
#include <Windows.h>
using namespace std;

class vector3d {
	vector<int> vect;
public:
	vector3d(){}
	vector3d(int k, int n, int b) {vect.push_back(k); vect.push_back(n); vect.push_back(b);}
	~vector3d(){}
	void Cin();
	void Cout();
	vector3d minus(vector<int> a, vector<int> b)
	{
		vector<int> temp;
		/*temp.resize(3);*/
		cout << "Minus : ";
		for (int i = 0; i < 3; i++) {
			temp[i]=a[i] - b[i];
			cout << temp[i] << " ";
		}
		cout << endl;
	}

	vector3d sum(vector<int> a, vector<int> b)
	{
		vector<int> temp;
		/*temp.resize(3);*/
		cout << "Sum : ";
		for (int i = 0; i < 3; i++) {
			temp[i] = a[i] + b[i];
			cout << temp[i] << " ";
		}
		cout << endl;
	}

	void dovjuna(vector<int> a)
	{
		int dovjuna;
		
		dovjuna = pow(pow(a[1], 2) + pow(a[2], 2) + pow(a[3], 2), 1.0 / 2);
		cout << "Dovjuna : " << dovjuna << endl;
	}
	
};

void vector3d::Cin() {
	cout << "¬вед≥ть трьохвим≥рний вектор: ";
	for (int i = 0; i < 3; i++) {
		vect.resize(3);
		cin >> vect[i];
	}
	
}

void vector3d::Cout() {
		copy(vect.begin(), vect.end(), ostream_iterator<int>(cout, " "));
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector3d v(10,3,2);
	v.Cin();
	v.Cout();
	return 0;
}
