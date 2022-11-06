#pragma once


class IntСontainer
{
public:
	IntСontainer() = default;
	IntСontainer(int length);
	~IntСontainer();

	void DeleteCorrectly();
	int& operator[](int index);
	void ResizeAndClear(int newLength);
	void ResizeAndSave(int newLength);
	void InsertBefore(int value, int index);
	void remove(int index);
	void insertAtBeginning(int value);
	void insertAtEnd(int value);
	int getLength() const;
	void CheckingTheInput(int length);
	void CheckingTheInput(int length, int index);
	void print();

private:
	int m_dlinna;
	int* m_massiv;
};

