#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <conio.h>
using namespace std;
class CFile
{
    //FILE* f;// ����� ��� �������� ��� ���� ��� ���������� ���� � ����� ���� � ����� ��������� ���� �� �������� � ��������� �������� fopen...  
    fstream f;
    string name;
    char* br;
public:
    virtual void open(string name2)
    {
        name = name2;
        cout << "File open";
        //f = fopen(name, "r");//������� ���� ���� ��� ������ �� ������������ ���������
        f.open(name);
    }


    void close()
    {
        //fclose(f);//������� ���� ����������� �������� �� ��� ���� ���� ���� �������� ����� �� �������� �� �������(���� �� ��������)
        f.close();
    }

    char seek(char* a)
    {
        int k = 0;
        for (int i = 0, j = 0; i < strlen(br); i++) {
            if (br[i] == a[j]) {
                j++; k++;
                if (br[i + 1] != a[j + 1]) {
                    j--;
                }
            }
            if (strlen(a) == k) { cout << a << endl; }
        }
    }

    void read()
    {
        ifstream in;
        //char *br;
        char ch;
        int i = 0;
        while (in.get(ch)) {
            cout << ch;
            br[i] = ch;
            i++;
        }

    }

    void write()
    {
        string k;
        ofstream out;
        cout << "Input need string for writing: " << endl;
        cin >> k;
        out << k << endl;

    }

};

class CMyDataFile : public CFile
{
public:
    CMyDataFile() {}
    ~CMyDataFile() {}

};

void main(void)
{
    string g;
    cin >> g;
    CMyDataFile a;
    a.open(g);
}
// ��� ���������