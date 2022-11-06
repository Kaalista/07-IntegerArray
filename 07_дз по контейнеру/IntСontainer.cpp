#include<iostream>
#include"IntContainer.h"
#include <exception>
using namespace std;

IntContainer::IntContainer(int length)
{
	try
	{
		CheckingTheInput(length);
	}
	catch (const exception& ex)
	{
		std::cout << "внимание." << ex.what() << std::endl;
		std::cout << "ввидите новоевую длинну массива" << std::endl;

		int i = 0;
		while (i >= 1) 
		{
			std::cin >> length;
			if (length <= 0)
			{
				std::cout << "ввидите нормальную длинну массива. -_- ну!" << std::endl;
			}
			else
			{
				i = 1;
			}
		};
	}
	catch (...)
	{
		std::cout << "внимание. что то пошло не так 1"  << std::endl;
	}
	m_massiv = new int[length] {};
	m_dlinna = length;
}
IntContainer::~IntContainer()
{
	delete[] m_massiv;
}
void IntContainer :: DeleteCorrectly()
{
	delete[] m_massiv;
	m_massiv = nullptr;
	m_dlinna = 0;
}
int& IntContainer::operator[](int index)
{
	try
	{
		CheckingTheInput(m_dlinna, index);
	}
	catch (const exception& ex)
	{
		std::cout << "внимание." << ex.what() << std::endl;
		std::cout << "ввидите новое значение" << std::endl;
		std::cin >> index;
	}
	catch (...)
	{
		std::cout << "внимание. что то пошло не так 2" << std::endl;
	}
	return m_massiv[index];
}	
void IntContainer::ResizeAndClear(int newdlinna)
{
	DeleteCorrectly();
	if (newdlinna <= 0)
		return;
	m_massiv = new int[newdlinna];
	m_dlinna = newdlinna;
}
void IntContainer::ResizeAndSave(int newdlinna)
{
	if (newdlinna == m_dlinna)
		return;
	if (newdlinna <= 0)
	{
		DeleteCorrectly();
		return;
	}
	int* data{ new int[newdlinna] };
	if (m_dlinna > 0)
	{
		int elementsToCopy{ (newdlinna > m_dlinna) ? m_dlinna : newdlinna };
		for (int index{ 0 }; index < elementsToCopy; ++index)
			data[index] = m_massiv[index];
	}
	delete[] m_massiv;
	m_massiv = data;
	m_dlinna = newdlinna;
}
void IntContainer::InsertBefore(int value, int index)
{ 
	try
	{
		CheckingTheInput(m_dlinna, index);
	}
	catch (const exception& ex)
	{
		std::cout << "внимание." << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "внимание. что то пошло не так 3" << std::endl;
	}
	int* data{ new int[m_dlinna + 1] };
	for (int before{ 0 }; before < index; ++before)
		data[before] = m_massiv[before];
	data[index] = value;
	for (int after{ index }; after < m_dlinna; ++after)
		data[after + 1] = m_massiv[after];
	delete[] m_massiv;
	m_massiv = data;
	++m_dlinna;
}

void IntContainer::remove(int index)
{
	try
	{
		CheckingTheInput(m_dlinna,index);
	}
	catch(const char *ex)
	{
		std::cout<<"внимание."<< ex <<std::endl;
		std::cout << "ввидите новое значение" << std::endl;
		std::cin>> index;
	}
	catch (...)
	{
		std::cout << "внимание. что то пошло не так 4" << std::endl;
	}
	
	if (m_dlinna == 1)
	{
		DeleteCorrectly();
		return;
	}
	int* data{ new int[m_dlinna - 1] };
	for (int before{ 0 }; before < index; ++before)
		data[before] = m_massiv[before];
	for (int after{ index + 1 }; after < m_dlinna; ++after)
		data[after - 1] = m_massiv[after];
	delete[] m_massiv;
	m_massiv = data;
	--m_dlinna;
}
void IntContainer::insertAtBeginning(int value)
{
	InsertBefore(value, 0);
}
void IntContainer::insertAtEnd(int value)
{
	InsertBefore(value, m_dlinna);
}
int IntContainer::getLength() const
{
	return m_dlinna;
}
void IntContainer::CheckingTheInput(int length)
{
	if (length <= 0)
		throw exception("Ай-Яй-яй,\t(|)_0o_(|)\terror: Длинна не может быть меньше или равна 0");
}
void IntContainer::CheckingTheInput(int length, int index)
{
	CheckingTheInput(length);
	if (index > length )
		throw exception("Ну кто так делает!!! Ай-Яй-яй,\t(|)_0o_(|) \t error: Индекс не можем быть больше длинны массива!");
}
void IntContainer::print()
{
	for (int i{ 0 }; i < getLength(); ++i)
		std::cout << m_massiv[i] << ' ';
	std::cout << '\n';
}
