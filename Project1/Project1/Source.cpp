#include <iostream>
#include <string>
#include  <conio.h>
using namespace std;
class CFile
{
    FILE* f;// ����� ��� �������� ��� ���� ��� ���������� ���� � ����� ���� � ����� ��������� ���� �� �������� � ��������� �������� fopen...  
    char* name;
public:
    virtual void open(char* name2)
    {
        name = name2;
        cout<<"File open";
        f = fopen(name, "r");//������� ���� ���� ��� ������ �� ������������ ���������
    }


    void close()
    {
        fclose(f);//������� ���� ����������� �������� �� ��� ���� ���� ���� �������� ����� �� �������� �� �������(���� �� ��������)
    }

    string seek(string a)
    {
       
    }

    void read()
    {
       
    }

    void write()
    {
       
    }

};

class CMyDataFile : public CFile
{
public:

    v
};

void main(void)
{
    
}