#pragma once
#include<iostream>
using namespace std;

class Stack
{
private:
	int* _stack;
	int _size, _top;

public:

	Stack(int size)
	{
		this->_size = size;
		_top = -1;
		_stack = new int[_size];
	}

	bool IsEmpty()
	{
		return _top == -1;
	}

	bool IsFull()
	{
		return _top == _size - 1;
	}

	int Peek()
	{
		return _stack[_top];
	}

	void Push(int value)
	{
		// Check if the stack was full
		if (IsFull())
		{
			cout << "Stack is full.\n";
			return;
		}

		_top++;
		_stack[_top] = value;
	}

	int Pop()
	{
		// Check if the stack was empty
		if (IsEmpty())
		{
			cout << "Stack is empty.\n";
			return NULL;
		}

		int removedValue = _stack[_top];

		_top--;
		return removedValue;

	}

	void Display()
	{
		// Check if the stack was empty
		if (IsEmpty())
		{
			cout << "Stack is empty.\n";
			return;
		}

		cout << "Stack Items: ";
		for (int i = _top; i >= 0; i++)
			cout << _stack[i];

		cout << endl;
	}
};