
#include "stdafx.h"
#include <iostream>

using namespace std;

enum TextType { plain, cipher, key };

bool* getInput(int textType)
{
	auto size = 8;
	if (textType == key) size = 10;

	auto* const inputText = new bool[size];

	for(int i{}; i < size; i++)
	{
		char rawInput;
		std::cin >> rawInput;
		auto const currentBit = rawInput - '0';
		inputText[i] = currentBit;
	}
	
	return inputText;
}

const int S0[][4] = { {1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 0, 3}, {3, 1, 3, 2} };
const int S1[][4] = { {0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 1, 3} };

bool* IPFunction(bool* text)
{
	auto const tempText = new bool[8];
	tempText[0] = text[1];
	tempText[1] = text[5];
	tempText[2] = text[2];
	tempText[3] = text[0];
	tempText[4] = text[3];
	tempText[5] = text[7];
	tempText[6] = text[4];
	tempText[7] = text[6];

	delete[] text;
	text = tempText;
	return text;
}

bool* InverseIPFunction(bool* text)
{
	auto const tempText = new bool[8];
	tempText[0] = text[3];
	tempText[1] = text[0];
	tempText[2] = text[2];
	tempText[3] = text[4];
	tempText[4] = text[6];
	tempText[5] = text[1];
	tempText[6] = text[7];
	tempText[7] = text[5];

	delete[] text;
	text = tempText;
	return text;
}

bool* FunctionFk(bool* text, bool* subkeyOne)
{
	// E/P Expansion permutation
	auto const tempText = new bool[8];
	tempText[0] = text[3] ^ subkeyOne[0];
	tempText[1] = text[0] ^ subkeyOne[1];
	tempText[2] = text[1] ^ subkeyOne[2];
	tempText[3] = text[2] ^ subkeyOne[3];
	tempText[4] = text[1] ^ subkeyOne[4];
	tempText[5] = text[2] ^ subkeyOne[5];
	tempText[6] = text[4] ^ subkeyOne[6];
	tempText[7] = text[1] ^ subkeyOne[7];

	//need to input this into S0 and S1

	delete[] text;
	text = tempText;
	return text;
}
