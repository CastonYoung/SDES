﻿// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "functions.h"
#include <vector>

using namespace std;

int main()
{
	// Code assistance from http://www.cplusplus.com/forum/beginner/21033/
	int choice;
	auto programRun = true;
	vector<bool> input;
	vector<bool> output;
	vector<bool> key0;
	vector<bool> key1;
	vector<bool> key2;
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
			input = getInput(plain);

			cout << " Enter your 10-bit key: ";
			key0 = getInput(key);
			key1 = GenKey1(key0);
			key2 = GenKey2(key0);

			output = InverseIPFunction(FunctionFk( Switch( FunctionFk(IPFunction(input),key1) ), key2 ));

			for (int i = 0; i < 8; i++)
			{
				if (output[i])	cout << '1';
				else			cout << '0';
			}
			cout << endl;

			break;
			}

		case 2:
			{
			cout << " Enter your 8-bit ciphertext: ";
			input = getInput(cipher);

			cout << " Enter your 10-bit key: ";
			key0 = getInput(key);
			key1 = GenKey1(key0);
			key2 = GenKey2(key0);

			output = InverseIPFunction(FunctionFk( Switch( FunctionFk(IPFunction(input),key2) ), key1 ));

			for (int i = 0; i < 8; i++)
			{
				if (output[i])	cout << '1';
				else			cout << '0';
			}
			cout << endl;

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

	getchar();
	getchar();
    return 0;
}

