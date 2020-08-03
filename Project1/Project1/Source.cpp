#include <iostream>
#include <string>
#include  <conio.h>
using namespace std;
class CFile
{
    FILE* f;// такий тип потрібний для того щоб передавати потік з файлу прмо в буфер вказуюючи його як аргумент в наступних функціях fopen...  
    char* name;
public:
    virtual void open(char* name2)
    {
        name = name2;
        cout<<"File open";
        f = fopen(name, "r");//відкриває файл суто для запису по замовчуванню текстовий
    }


    void close()
    {
        fclose(f);//закриває файл обовязковий аргумент це тип файл який після закриття файлу не звязаний із потоком(файл не звязаний)
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