#pragma once
#include<iostream>
using namespace std;

// Simple Queue
template <class T>
class Queue
{
private:
	T* _queue;
	int _size, _front, _rear;

public: 

	__declspec(property(get = GetSize, put = SetSize)) int Size;
	__declspec(property(get = GetFront)) T Front; // read only property
	__declspec(property(get = GetRear)) T Rear; // read only property

	Queue(int size)
	{
		if (size <= 0)
		{
			cout << "Size is not valid.";
			return;
		}

		_size = size;
		_front = _rear = -1;
		_queue = new T[_size];
	}

	int GetSize()
	{
		return _size;
	}

	void SetSize(int size)
	{
		if (size <= 0)
		{
			cout << "Size is not valid.";
			return;
		}

		_size = size;
	}

	bool IsEmpty()
	{
		return _front == -1;
	}

	bool IsFull()
	{
		return _rear == _size - 1;
	}

	bool Enqueue(T value)
	{
		if (IsFull())
		{
			cout << "Queue is full.";
			return false;
		}

		if (IsEmpty()) _front = _rear = 0;
		else _rear++;

		_queue[_rear] = value;
		return true;
	}

	T Dequeue()
	{
		T removedElement;

		if (IsEmpty())
		{
			cout << "Queue is empty.";
			return NULL;
		}

		if (_rear == _front)
		{
			removedElement = _queue[_front];
			_front = _rear = -1;
			return removedElement;
		}

		removedElement = _queue[_front];
		_front++;

		return removedElement;
	}

	T GetFront()
	{
		if (IsEmpty())
		{
			cout << "Queue is empty.";
			return NULL;
		}

		return _queue[_front];
	}

	T GetRear()
	{
		if (IsEmpty())
		{
			cout << "Queue is empty.";
			return NULL;
		}

		return _queue[_rear];
	}

	void Display()
	{
		if (IsEmpty())
		{
			cout << "Queue is empty." << endl;
			return;
		}

		cout << "Queue Items:- ";
		for (int i = _front; i < _rear; i++)
			cout << _queue[i] << " ";
		cout << endl;
	}
};