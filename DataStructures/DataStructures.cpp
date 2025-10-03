#include <iostream>
#include "Arrays/GenericArray.h"
//#include "PassingAndReturnPointers.h"
using namespace std;

#pragma region Passing & Returning Pointers & Void Pointer
// 
void PassingPointer(int* ptr)
{
	// ptr = &[x = 10]
	// Now x = 11
	(*ptr) += 1;
	cout << "Pointer Value: " << ptr << "  Pointer Address Value: " << *ptr << endl; // Memory address   11
}

int* ReturnAddressOfObjectFromStack()
{
	int number = 10;
	return &number;
}

string* ReturnAddressOfObjectFromHeap()
{
	string* myString = new string;  // new string => Empty String
	return myString;
}

int* GetArray(int size)
{
	int* array = new int[size];
	return array;
}

// Void Pointer => Generic Type Pointer => Can point any address from any data type.  
void VoidPointer()
{
	// Generic 
	// Void Pointer is not a pointer to object type.
	void* ptr;

	int n = 10;
	ptr = &n;
	cout << ptr << endl;

	// To dereference => we must do casting
	// If memory tried to read the value of pointer, 
	// the pointer doesn't know the number of bytes will read.
	cout << (int*)ptr << endl;

	string str = "";
	ptr = &str;
	cout << ptr << endl;

	// To dereference => we must do casting
	cout << (string*)ptr << endl;
	ptr = NULL;

	void* p = new string("Koko");

	cout << p << "   " << *(string*)p << endl;

	delete (string*)p;
	p = NULL;
}

#pragma endregion

int main()
{
	#pragma region Pointers
	// Shallow & Deep Copy
	/// Copy copy;
	/// copy.GetData(0, 5);
	/// 
	/// Copy newCopy = copy; // Copy Constructor
	/// newCopy.SetData(0, 1);
	/// 
	/// copy.GetData(0, 5);

	// Passing Pointer 
	/// int number = 10;
	/// Updating happened on the location of variable.
	/// PassingPointer(&number);
	/// cout << "Number Address: " << &number << " Value After Calling Function: " << number << endl;

	// Return Pointer
	/// Gangling Pointer => is pointing a free | deallocated | deleted memory address.
	/// int* ptr = ReturnAddressOfObjectFromStack();

	/// string* myString = ReturnAddressOfObjectFromHeap();
	/// *myString = "Ahmed"; 
	/// Any object allocated in heap is distroyed by close the program and the RAM are deleted
	/// delete myString;
	/// myString = NULL;
	/// 
	/// cout << *myString << endl;

	/// int* arr = GetArray(5);
	/// free(arr); // = delete[] arr;
	/// arr = NULL;  
	
	#pragma endregion
	
	#pragma region Dynamic & Generic Array
					// Array 
	/// Array<int> numbers(5);
	/// 
	/// numbers.Add(10);
	/// numbers.Add(20);
	/// numbers.Add(30);
	/// numbers.Add(40);
	/// 
	/// cout << "Removed elements is: " << numbers.Remove(3) << endl; // 40
	/// 
	/// numbers.Display();
	/// 
	/// numbers.Add(50);
	/// 
	/// numbers.Display();
	/// 
	/// numbers.Add(60); 
	/// 
	/// if (numbers.IsFull())
	/// {
	/// 	cout << "Array is full.\n\n";
	/// }
	/// 
	/// numbers.Add(70);
	/// 
	/// numbers.Display();
	/// 
	/// Array<string>* names = new Array<string>();
	/// 
	/// names->Add("Ahmed");
	/// names->Add("aaa");
	/// names->Add("Mohamed");
	/// 
	/// cout << names->RetrieveAt(0) << endl;
	/// 
	/// string maxValue;
	/// names->Max(maxValue);
	/// 
	/// cout << maxValue << endl;
	/// 
	/// names->Display();
	/// Array<int> arr1(10);
	/// 
	/// arr1.Add(10);
	/// arr1.Add(20);
	/// arr1.Add(30);
	/// arr1.Add(40);
	/// arr1.Add(50);
	/// 

	/// arr1.Add(10);
	/// arr1.Add(20);
	/// arr1.Add(30);
	/// arr1.Add(40);
	/// arr1.Add(50);

	// Add
	/// arr1.Add(10);
	/// arr1.Add(20);
	/// arr1.Add(30);
	/// arr1.Add(40);
	/// arr1.Add(50);

	// Min & Max Methods
	/// int max = 0;
	/// arr1.Max(max);
	/// cout << "Max: " << max << endl;
	/// 
	/// int min = 0;
	/// arr1.Min(min);
	/// cout << "Min: " << min << endl;

	// Find & RetrieveAt Methods
	/// bool result = arr1.Find(30);
	/// if (result == true)
	/// 	cout << "Element 30 is found in the array.\n";
	/// else
	/// 	cout << "Element 30 is not found in the array.\n";
	/// 
	/// result = arr1.Find(60);
	/// if (result == true)
	/// 	cout << "Element 60 is found in the array.\n";
	/// else
	/// 	cout << "Element 60 is not found in the array.\n";
	/// int item = arr1.RetrieveAt(-1); // 20
	/// if (item != NULL)
	/// 	cout << item << endl;

	// Remove 
	/// arr1.Remove(1);
	/// arr1.Display();

	// Insert 
	/// arr1.Insert(1, 20);
	/// arr1.Display();

	// IsFull & IsEmpty
	/// cout << arr1.IsEmpty() << endl;
	/// cout << arr1.IsFull() << endl;

	// Count (Read Only) & Capacity Property 
	///arr1.Count = 10; // Invalid
	///cout << arr1.Count << endl; 
	/// arr1.Capacity = 15;

	// Display
	/// arr1.Display();
	/// 

	// Array - Try Copy Constructor & Assignment Operator = 
	/// Array<int> arr1(10);
	/// Array<int> arr2 = arr1;
	/// arr2.Add(60);
	/// 
	/// cout << "Array 2: \n";
	/// arr2.Display();
	/// 
	/// cout << "Array 1: \n";
	/// arr1.Display();  
	#pragma endregion

	return 0;
}