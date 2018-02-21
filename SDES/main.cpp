﻿// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "functions.h"

using namespace std;

int main()
{

	int choice;
	bool input2[8] = { 0,0,0,0,0,0,0,0 };
	bool *input = {};
	bool output[8] = {0,0,0,0,0,0,0,0};
	bool* key0 = {};
	bool key1[8] = {0,0,0,0,0,0,0,0};
	bool key2[8] = { 0,0,0,0,0,0,0,0 };
	bool programRun = true;
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
		case encrypt:
			{
			cout << " Enter your 8-bit plaintext: ";
			input = getInput(plain);

			for (int i = 0; i < 8; i++) input2[i] = input[i];
				

			cout << " Enter your 10-bit key: ";
			key0 = getKey(key);
			GenKey1(key0, key1);
			GenKey2(key0, key2);
			
			IPFunction(input2);

			FunctionFk(input2, output, key1);
			SwitchFn (output);

			for (int i = 0; i < 4; i++) output[i] = input2[i + 4];

			FunctionFk(output, output, key2);
			InverseIPFunction(output);

			break;
			}

		case decrypt:
			{
			cout << " Enter your 8-bit ciphertext: ";
			input = getInput(cipher);

			cout << " Enter your 10-bit key: ";
			key0 = getInput(key);
			GenKey1(key0, key1);
			GenKey2(key0, key2);

			IPFunction(input2);

			//InverseIPFunction(FunctionFk( Switch( FunctionFk(input2,key2) ), key1 ));

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

		//Output the resulting text
		for (int i = 0; i < 8; i++)
		{
			if (output[i])
				cout << '1';
			else
				cout << '0';
		}
		cout << endl;

	}

	getchar();
	getchar();
    return 0;
}

