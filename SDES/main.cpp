// SDES.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int* getText()
{

	char c1, c2, c3;
	cin >> c1 >> c2 >> c3;
	bool i = c1 - '0';
	//put into int array from there.

	/*
	auto const size = 10;
	auto* const inputText = new int[size];
	string rawInput;

	cout << " Please enter your 8-bit plaintext.\n";
	cin.ignore();
	getline(cin, rawInput);

	stringstream parser(rawInput);

	//Not reading in as individual ints...
	for (int i = 0; i < size; i++) parser >> inputText[i];
	/*
	int i{};
	while (parser >> inputText[i])
	{
		i++;
	}
	*/
	
	return inputText;
}

int* getKey()
{
	auto* const keyText = new int[10];
	string rawKeyInput;

	cout << " Please enter your 10-bit key.\n";
	cin.ignore();
	getline(cin, rawKeyInput);

	stringstream parser(rawKeyInput);
	auto const size = sizeof(rawKeyInput);

	//for (int i{}; i < size; i++) parser >> keyText[i];

	return keyText;
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


		switch (choice)
		{
		case 1:
			{
			auto plainText = getText();

			break;
			}

		case 2:
			{
			cout << " Please enter your 8-bit ciphertext.\n";

			auto cipherText = getText();

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

