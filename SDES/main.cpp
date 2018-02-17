// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

enum TextType { plain, cipher, key };

int* getInput(int textType)
{
	auto size = 8;
	if (textType == key) size = 10;

	auto* const inputText = new int[size];

	for(int i{}; i < size; i++)
	{
		char rawInput;
		cin >> rawInput;
		auto const currentBit = rawInput - '0';
		inputText[i] = currentBit;
	}
	
	return inputText;
}

int main()
{
	// Code assistance from http://www.cplusplus.com/forum/beginner/21033/
	int choice;
	auto programRun = true;
	while (programRun)
	{
		cout << "***********SDES Multitool************\n";
		cout << endl;
		cout << " 1 - Encrypt\n";
		cout << " 2 - Decrypt\n";
		cout << " 3 - Exit\n";
		cout << endl;
		cout << " Enter your choice and press return: ";

		cin >> choice;

		cout << endl;

		switch (choice)
		{
		case 1:
			{
			cout << " Enter your 8-bit plaintext: ";
			auto plainText = getInput(plain);

			cout << " Enter your 10-bit key: ";
			auto keyText = getInput(key);

			break;
			}

		case 2:
			{
			cout << " Enter your 8-bit ciphertext: ";

			auto cipherText = getInput(cipher);

			break;
			}

		case 3: 
			cout << "End of Program.\n";
			programRun = false;

		break;

		default: 

		cout << "Not a Valid Choice. \n";
		cout << "Choose again.\n";
		cin >> choice;

		break;
		}
	}
    return 0;
}

