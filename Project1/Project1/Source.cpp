
//Варіант 1. Створити клас для роботи з трьох вимірними
//векторами.Передбачити функції для виконання наступних операцій :
//консольне введення і виведення значень вектора; ініціалізація вектора;
//складання та віднімання векторів; обчислення довжини вектора.

#include <iostream>

using namespace std;

class Vector3D
{
public:
    float x, y, z;
    void setCoord()
    {
        cout << "Input x : ";
        cin >> x;
        cout << "Input y : ";
        cin >> y;
        cout << "Input z : ";
        cin >> z;
    }
    void getCoord()
    {
        cout << "Vector : (" << x << ", " << y << ", " << z << ")" << endl << endl;
    }
};

Vector3D a, b;

void vecminus()
{
    float x, y, z;
    x = b.x - a.x;
    y = b.y - a.y;
    z = b.z - a.z;
    cout << "Minus : (" << x << ", " << y << ", " << z << ")" << endl;
}

void vecsum()
{
    float x, y, z;
    x = b.x + a.x;
    y = b.y + a.y;
    z = b.z + a.z;
    cout << "Sum : (" << x << ", " << y << ", " << z << ")" << endl;
}

void dovjuna()
{
    float x, y, z, dovjuna;
    x = b.x - a.x;
    y = b.y - a.y;
    z = b.z - a.z;
    dovjuna = pow(pow(x, 2) + pow(y, 2) + pow(z, 2), 1.0 / 2);
    cout << "Dovjuna : " << dovjuna << endl;
}
int main()
{
    cout << "Vector A:" << endl;
    a.setCoord();
    a.getCoord();
    cout << "Vector B:" << endl;
    b.setCoord();
    b.getCoord();
    vecminus();
    vecsum();
    dovjuna();
    cin.get();
    return 0;
}