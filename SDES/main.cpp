// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "functions.h"

using namespace std;

int main()
{

	int choice;
	bool programRun = true;

	while (programRun)
	{
		
		bool input2[8]{};
		bool *input{};
		bool output[8]{};
		bool* key0{};
		bool key1[8]{};
		bool key2[8]{};

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
			cout << endl;

			for (int i = 0; i < 8; i++) input2[i] = input[i];

			cout << " Enter your 10-bit key: ";
			key0 = getKey(key);
			cout << endl;

			GenKey1(key0, key1);
			GenKey2(key0, key2);
			
			IPFunction(input2);

			FunctionFk(input2, output, key1);
			SwitchFn (output);

			for (int i = 0; i < 4; i++) output[i] = input2[i + 4];

			FunctionFk(output, output, key2);
			InverseIPFunction(output);

			cout << " The 8-bit cypertext is: ";

			break;
			}

		case decrypt:
			{
			cout << " Enter your 8-bit ciphertext: ";
			input = getInput(cipher);
			cout << endl;

			for (int i = 0; i < 8; i++) input2[i] = input[i];

			cout << " Enter your 10-bit key: ";
			key0 = getKey(key);
			cout << endl;

			GenKey1(key0, key1);
			GenKey2(key0, key2);

			IPFunction(input2);

			FunctionFk(input2, output, key2);
			SwitchFn (output);

			for (int i = 0; i < 4; i++) output[i] = input2[i + 4];

			FunctionFk(output, output, key1);
			InverseIPFunction(output);

			cout << " The 8-bit plaintext is: ";

			break;
			}

		case 3: 
			cout << " End of Program.\n";
			programRun = false;
			return 0;

			break;

		default: 
			cout << " Not a Valid Choice. Choose again. \n";
			cin >> choice;
			cout << endl;

			break;
		}

		//Output the resulting text
		for (int i = 0; i < 8; i++)
		{
			if (output[i]) cout << '1';
			else cout << '0';
		}

		cout << endl << endl;
		cout << " SubKey 1 is: ";

		//Output Key1
		for (int i = 0; i < 8; i++)
		{
			if (key1[i]) cout << '1';
			else cout << '0';
		}

		cout << endl << endl;
		cout << " SubKey 2 is: ";

		//Output Key2
		for (int i = 0; i < 8; i++)
		{
			if (key2[i]) cout << '1';
			else cout << '0';
		}

		cout << endl << endl;
		system("PAUSE");
		system("CLS");
	}

    return 0;
}

