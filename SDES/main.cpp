// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "functions.h"

using namespace std;

enum TextType { plain, cipher, key };

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
			auto* plainText = getInput(plain);

			plainText = IPFunction(plainText);

			cout << " Enter your 10-bit key: ";
			auto* keyText = getInput(key);

			//Do the sdes algorithm stuff
			//output ciphertext, key1 and key2

			delete[] plainText;
			delete[] keyText;
			break;
			}

		case 2:
			{
			cout << " Enter your 8-bit ciphertext: ";
			auto cipherText = getInput(cipher);

			cout << " Enter your 10-bit key: ";
			auto* keyText = getInput(key);

			//Do the sdes algorithm stuff
			//output ciphertext, key1 and key2

			delete[] cipherText;
			delete[] keyText;
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

