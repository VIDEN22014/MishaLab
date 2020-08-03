//Варіант 1. Наданий такий клас :
//class Base
//{
//public:
//  virtual void myname() { cout << "This is class Base" << endl; }
//};
//Від цього класу треба створити два похідних класу : DerA і DerB.
//Від класів DerA і DerB шляхом множинного успадкування
//створити клас DerAB.
//Перевизначити у кожному з створених класів функцію myname
//таким чином, щоб вона виводила на екран дійсне ім’я класу об’єкту,
//для якого вона викликається.
//Для кожного з класів створеної ієрархії створити по одному
//об’єкту і для кожного з них викличте функцію myname.
//Створіть масив із 4 покажчиків на базовий клас ієрархії.Для
//кожного з них створіть динамічний об’єкт, по одному для кожного з
//класів ієрархії.Запишіть виклик функції myname для кожного з
//динамічних об’єктів за допомогою покажчиків.
//Поясніть дію функції mymain у всіх випадках.

#include <iostream>

using namespace std;

class Base
{
public:
    virtual void myname() { cout << "This is class Base" << endl; }
};

class DerA : public Base
{
public:
    void myname()
    {
        cout << "This is class DerA" << endl;
    }
};

class DerB : public Base
{
public:
    void myname()
    {
        cout << "This is class DerB" << endl;
    }
};

class DerAB :public Base, public DerA, public DerB
{
public:
    void myname()
    {
        cout << "This is class DerAB" << endl;
    }
};

int main()
{
    Base base;
    DerA a;
    DerB b;
    DerAB ab;

    Base* arr[4];
    Base* ptr = nullptr;
    int chooseClass;
    cout << "Choose class method" << endl
        << "0 - Base" << endl
        << "1 - DerA" << endl
        << "2 - DerB" << endl
        << "3 - DerAB" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "danuy nomer "<<i<<"."<<endl;
        cin >> chooseClass;
        switch (chooseClass)
        {
        case 0:
        {
            ptr = new Base;
            break;
        }
        case 1:
        {
            ptr = new DerA;
            break;
        }
        case 2:
        {
            ptr = new DerB;
            break;
        }
        case 3:
        {
            ptr = new DerAB;
            break;
        }
        default:
            cout << "Error";
            break;
        }
        arr[i] = ptr;
    }
    for (int i = 0; i < 4; i++)
    {
        arr[i]->myname();
    }
    for (int i = 0; i < 4; i++)
    {
        delete arr[i];
    }
    base.myname();
    a.myname();
    b.myname();
    ab.myname();
    cin.get();
    return 0;
}