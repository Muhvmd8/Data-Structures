#pragma once
#include<iostream>
#include<string>
using namespace std;

void DeclarePointer()
{
	int* ptr = nullptr; // NULL
	ptr = 0; // Invalid memory
	// Declare a variable of integer type:
	int n = 10;
	// Make the ptr to point to address of n in memory.
	ptr = &n;
	// Print information of pointer and variable 
	cout << "Pointer value | Address of n in memory: " << ptr << "\n";
	cout << "'n' value = " << *ptr << "\n";
	cout << "Pointer address: " << &ptr << "\n";
}

string GetBinary(long long N) {
	return N == 0 || N == 1 ? "1" : GetBinary(N >> 1) + to_string(N & 1);
}

void Why_Pointers_Must_Be_From_The_Same_Type_Of_Pointed_Data()
{
	// Declare 8 bytes in memory
	long long n = 4554587899965; 
	// Print this number with binary 
	cout << GetBinary(n) << endl;
	cout << 0b1000010010001110010100110000000100000111101 << endl;

	// How does the pointer scan, read, and print the long long value:
	// Pointer referes to the first byte:
	cout << "byte 1: " << 0b00111101 << endl; // 61
	// The second byte: 
	cout << "byte 2: " << 0b00001000 << endl; // 8
	cout << "byte 3: " << 0b10011000 << endl; // 152
	cout << "byte 4: " << 0b01110010 << endl; // 144
	cout << "byte 5: " << 0b00100100 << endl; // 36
	cout << "byte 6: " << 0b00000100 << endl; // 4

	// 1 byte of type bool referes to the first byte of long long n
    bool* byte = (bool*)(&n);
	cout << "address of Big Number: " << &n << '\n';
	cout << "address of byte[1] " << byte << " " << *byte << '\n';
	// To make byte pointer indicates to the second byte 
	++byte;
	cout << "address of byte[2] " << byte << " " << *byte << '\n';
	++byte;
	cout << "address of byte[3] " << byte << " " << *byte << '\n';
	++byte;
	cout << "address of byte[4] " << byte << " " << *byte << '\n';
	++byte;
	cout << "address of byte[5] " << byte << " " << *byte << '\n';
	++byte;
	cout << "address of byte[6] " << byte << " " << *byte << '\n';
	++byte;

	/*

	byte 1: 61
	byte 2: 8
	byte 3: 152
	byte 4: 114
	byte 5: 36
	byte 6: 4

	Address of big number: 0x61fee8
	Address of byte[1] 0x61fee8 61
	Address of byte[2] 0x61fee9 8
	Address of byte[3] 0x61feea 152
	Address of byte[4] 0x61feeb 114
	Address of byte[5] 0x61feec 36
	Address of byte[6] 0x61feed 4

	*/

	int size = sizeof(n); // 8
	for (bool* i = (bool*)(&n); i != (byte + sizeof(n)); i++)
		cout << *i << " ";
	// output => 61 8 152 114 36 4 0 0  
	cout << "\n";

	int temp = n;
	cout << temp << '\n';
	cout << 0b01110010100110000000100000111101; // 1922566205
	/*
		4 byte -> int
		byte 1 [00111101]
		byte 2 [00001000]
		byte 3 [10011000]
		byte 4 [01110010]
	*/
}