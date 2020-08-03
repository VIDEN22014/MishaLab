//������ 1. ������� ����� ���� :
//class Base
//{
//public:
//  virtual void myname() { cout << "This is class Base" << endl; }
//};
//³� ����� ����� ����� �������� ��� �������� ����� : DerA � DerB.
//³� ����� DerA � DerB ������ ���������� ������������
//�������� ���� DerAB.
//������������� � ������� � ��������� ����� ������� myname
//����� �����, ��� ���� �������� �� ����� ����� ��� ����� �ᒺ���,
//��� ����� ���� �����������.
//��� ������� � ����� �������� �������� �������� �� ������
//�ᒺ��� � ��� ������� � ��� �������� ������� myname.
//������� ����� �� 4 ��������� �� ������� ���� ��������.���
//������� � ��� ������� ��������� �ᒺ��, �� ������ ��� ������� �
//����� ��������.�������� ������ ������� myname ��� ������� �
//��������� �ᒺ��� �� ��������� ���������.
//������� �� ������� mymain � ��� ��������.

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