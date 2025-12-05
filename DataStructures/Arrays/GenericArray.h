#pragma once
#include <iostream>
using namespace std;

// Dynamic & Generic Array

template <class T>
class Array
{

private:

    #pragma region Attributes

    int _capacity, _count;
    T* _list;

    #pragma endregion

    // Resize array on adding | appending if the array was full.
    void _ExpandCapacity(int newCapacity)
    {
        _capacity = newCapacity;
        T* newList = new T[newCapacity];

        for (int i = 0; i < _count; i++)
            newList[i] = _list[i];

        delete[] _list;   
        _list = newList; 
    }

    // Make Count Property Read Only 
    void SetCount(int count)
    {
        _count = count;
    }

public:

    #pragma region Properties
    // Read Only Property 
    __declspec(property(get = GetCount, put = SetCount)) int Count;
    __declspec(property(get = GetCapacity, put = SetCount)) int Capacity;

    #pragma endregion

    #pragma region Constructors

    // Default
    Array()
    {
        // If user called the default constructor, make the capacity with 4 defaultly.
        _capacity = 4; // Default
        _list = new T[_capacity];
        _count = 0;
    }

    Array(int capacity)
    {
        // Validation on the size 
        if (capacity < 1)
            cout << "Capacity must be more than 0.\n";
        else
        {
            this->_capacity = capacity;
            _count = 0;
            _list = new T[_capacity];
        }
    }

    // Copy Constructor to make deep copy 
    // Source is constant to prevent the editing on this object.
    Array(const Array& source)
    {
        // To prevent this line => arr1 = arr1; // Invalid
        if (this != &source)
        {
            delete[] _list; // if the array was pointing to old object in heap i will delete it.

            this->_capacity = source._capacity;
            this->_count = source._count;
            this->_list = new T[_capacity];

            // Copy Array Elements
            for (int i = 0; i < Count; i++)
                _list[i] = source._list[i];
        }
    }

    #pragma endregion

    #pragma region Methods

    bool IsEmpty()
    {
        return _count == 0;
    }

    bool IsFull()
    {
        return _count == _capacity;
    }

    int GetCapacity()
    {
        return _capacity;
    }

    void SetCapacity(int value) {
        if (value >= 1)
            _capacity = value;
        else 
            cout << "Capacity must be more than 0.\n";
    }

    int GetCount() {
        return _count;
    }

    // Add items in the end of array.
    void Add(T value)   
    {
        if (IsFull())
            _ExpandCapacity(_capacity + 4);

        _list[_count] = value;
        _count++;
    }

    // Add items in a specific index.
    void Insert(int index, T value)
    { 
        if (index < 0 || index > _capacity - 1)
        {
            throw out_of_range("Invalid index");
            return;
        }

        if (IsFull())
            _ExpandCapacity(_capacity + 4);

        /*if (IsEmpty() && _capacity > index) 
            Add(value);*/

        if (_count == index)
        {
            Add(value);
            return;
        }

        // 1 2 3 4 5 - - -   |   Capacity = 8,   Count = 5  index = 2, value = 2
        // 1 2 - 3 4 5 - -       => Shifting Right

        for (int i = _count; i > index; i--)
            _list[_count] = _list[_count - 1];

        _list[index] = value;
        _count++;

    }

    // Remove item from a specific index.
    T Remove(int index)
    {
        if (IsEmpty() || index >= _count) 
            throw out_of_range("Invalid index");

        T removedItem = _list[index];

        T* newList = new T[_capacity]; 

        for (int i = 0; i < index; i++)
            newList[i] = _list[i];

        for (int i = index + 1; i <= _count; i++)
            newList[i - 1] = _list[i];

        delete[] _list;
        _list = newList;

        _count--;

        return removedItem;
    }

    // Linear Search
    bool Find(T value) // Linear Search
    {
        if (IsEmpty()) return false;

        for (int i = 0; i < _count; i++)
            if (_list[i] == value) return true;

        return false;
    }

    // Get item of index N
    T RetrieveAt(int index)
    {
        if (index < 0 || index > _capacity - 1)
        {
            cout << "Invalid index\n";
            return NULL;;
        }

        if (IsEmpty())
        {
            cout << "Array is empty\n";
            return NULL;
        }

        return _list[index];
    }

    void Display()
    {
        if (IsEmpty())
        {
            cout << "Array is empty!\n\n";
            return;
        }

        cout << "Capacity of the Array = " << _capacity << endl;
        cout << "Length of the Array = " << _count << endl << endl;

        cout << "Elements: \n";
        for (int i = 0; i < _count; i++)
            cout << _list[i] << " ";

        cout << endl << endl;
    }

    void Max(T& maxValue)
    {
        if (IsEmpty())
        {
            cout << "Array is empty!\n\n";
            return;
        }

        maxValue = _list[0];
        for (int i = 1; i < _count; i++)
            if (maxValue < _list[i])
                maxValue = _list[i];
    }

    void Min(T& minValue)
    {
        if (IsEmpty())
        {
            cout << "Array is empty!\n\n";
            return;
        }

        minValue = _list[0];
        for (int i = 1; i < _count; i++)
            if (minValue > _list[i])
                minValue = _list[i];
    }

    #pragma endregion

    #pragma region Operators

    // Assignment Operator to copy array object into another array.
    void operator =(const Array& source)
    {
        if (this != &source)
        {
            this->Capacity = source._capacity;
            this->Count = source._capacity;
            this->_list = new T[Capacity];

            // Copy Array
            for (int i = 0; i < Count; i++)
                _list[i] = source._list[i];
        }
    }

    #pragma endregion

};