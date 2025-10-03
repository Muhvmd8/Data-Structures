#pragma once
#include<iostream>
using namespace std;

const int MaxListSize = 100;

class Copy
{

private:
	int* _list;

public:
	Copy();
	~Copy();

	void SetData(int index, int value);
	void GetData(int start, int size);

};

Copy::Copy()
{
	_list = new int[MaxListSize];
	for (short i = 0; i < MaxListSize; i++)
		_list[i] = -1;
}

Copy::~Copy()
{
	delete[] _list;
}

void Copy::SetData(int index, int value)
{
	if (index < MaxListSize && index >= 0)
		_list[index] = value;
	else
		cout << "Invalid index.\n";
}

void Copy::GetData(int start, int size)
{
	if ((start < 100 && start >= 0) && size > MaxListSize)
		cout << "Invalid size or start.\n";
	else
		for (short i = start; i < size; i++)
			cout << _list[i] << " ";

	cout << "\n";
}
