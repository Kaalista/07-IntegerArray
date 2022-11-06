#include<iostream>
#include"IntContainer.h"
#include <exception>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    int SIZE = 17;
    IntÑontainer massinInt(SIZE);

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
   std::cout<< "все прошло успешно!"<< std::endl;

   return 0;
}
