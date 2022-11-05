#pragma once


class IntСontainer
{
public:
	IntСontainer() = default;
	IntСontainer(int length);
	~IntСontainer();

	void DeleteCorrectly();// стирать m_data в nullptr 
	int& operator[](int index);//проверка индекса
	void ResizeAndClear(int newLength);// изменяет размер массива. Все существующие элементы будут уничтожены
	void ResizeAndSave(int newLength);//изменяет размер массива. Все существующие элементы будут сохранены.
	void InsertBefore(int value, int index);//вставить элемент
	void remove(int index);//удалить элемент
	void insertAtBeginning(int value);//Вставить в начало
	void insertAtEnd(int value);//вставить в конец
	int getLength() const;//вернуть длинну
	void CheckingTheInput(int length);// проверка входных данных на 0 или меньше 0
	void CheckingTheInput(int length, int index);// проверка входных данных на 0 или меньше 0 и на соответсвие индексу
	void print();

private:
	int m_dlinna;
	int* m_massiv;
};

