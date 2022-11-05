#include<iostream>
#include"Int—ontainer.h"
//#include<string>
#include <exception>
//#define  MRTDLL 
//#define  _M_CEE

using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    int SIZE = 17;

    Int—ontainer massinInt(SIZE);

    for (int i{ 0 }; i < SIZE; ++i)
    {
        massinInt[i] = i + 1;//rand() % 10;
    };

   massinInt.ResizeAndSave(8);
   massinInt.InsertBefore(20, 5);
   massinInt.remove(3);
   massinInt.insertAtEnd(4);
   massinInt.insertAtBeginning(35);
   massinInt.print();
    std::cout<< "‚ÒÂ ÔÓ¯ÎÓ ÛÒÔÂ¯ÌÓ!"<< std::endl;

    return 0;
}