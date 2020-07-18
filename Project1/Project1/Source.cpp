#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

class vector3d {
	vector<vector<vector<int>>> vect;
public:
	void Init();
	void Display();
	
};

void vector3d::Init(){
	cout << "¬вед≥ть ширину, довготу ≥ висоту вектора" << endl;
	int a, b, h;
	cin >> a >> b >> h;
	vect.clear();
	vect.resize(a);

	for (int i = 0; i < a; i++)
	{
		vect[i].resize(b);

		for (int j = 0; j < b; j++)
		{
			vect[i][j].resize(h);

			for (int k = 0; k < h; k++)
			{
				cin >> vect[i][j][k];
			}
		}
	}
}

void vector3d::Display() {
	for (int i = 0; i < vect.size(); i++)
	{
		for (int j = 0; j < vect[i].size(); j++)
		{
			for (int k = 0; k < vect[i][j].size(); k++)
			{
				cout << vect[i][j][k] << " ";
			}
		}
	}
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector3d v;
	v.Init();
	v.Display();
	return 0;
}
