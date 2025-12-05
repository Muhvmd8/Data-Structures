#pragma once
#include<iostream>
using namespace std;

template <class T>
class Stack
{
private:
	T* _stack;
	int _size, _top;

public:

	Stack(int size)
	{
		if (size <= 0)
		{
			cout << "Size is not valid." << endl;
			return;
		}
		_size = size;
		_top = -1;
		_stack = new T[_size];
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

	void Push(T value)
	{
		// Check if the stack was full
		if (IsFull())
		{
			cout << "Stack overflow." << endl;
			return;
		}

		_top++;
		_stack[_top] = value;
	}

	T Pop()
	{
		// Check if the stack was empty
		if (IsEmpty())
		{
			cout << "Stack is empty.\n";
			return NULL;
		}

		T removedValue = _stack[_top];

		_top--;
		return removedValue;
	}

	T Top()
	{
		return _stack[_top];
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
		for (int i = _top; i >= 0; i--)
			cout << _stack[i] << " ";

		cout << endl;
	}

	void Reverse()
	{
		if (IsEmpty())
		{
			cout << "Stack is empty." << endl;
			return;
		}

		Stack<T>* newStack = new Stack<T>(_size);
		for (int i = _top; i >= 0; i--)
			newStack->Push(_stack[i]);

		for (int i = _top; i >= 0; i--)
			_stack[i] = newStack->Pop();

		delete[] newStack;
	}
};