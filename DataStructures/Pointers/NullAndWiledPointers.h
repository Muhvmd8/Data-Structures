#pragma once
#include <iostream>
using namespace std;

// Any pointer can referes to (null | nullptr | 0) and caled Null Pointer.
// Null pointer referes to invalid memory.
// If you tried to dereference the Null Pointer, the application will crash and throw exception.

void TryNullPointerProblems()
{
	double* dblPointer = nullptr;
	
	// cout << *dblPointer << endl; // Application will crash.
	// To handle this exception, i must write a protective code.

	// Check if pointer is refere to null to avoid accessing null:
	if (dblPointer == nullptr)
		cout << "Pointer doesn't indicate a memory address.";
	else
		cout << "Pointer address value:" << * dblPointer << endl;
}

void TryWiledPointerProblems()
{
	// int* wiledPointer; // Pointer that is not initialized. 

	// *wiledPointer = 50; //Program will crash.
	//cout << "Address value: " << *wiledPointer << endl;
}