
#include "stdafx.h"
#include <iostream>
#include "functions.h"

using namespace std;

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

bool* FunctionFk(bool* text, bool* subkey1)
{
	// E/P Expansion permutation
	auto const tempText = new bool[8];
	tempText[0] = text[3] ^ subkey1[0];
	tempText[1] = text[0] ^ subkey1[1];
	tempText[2] = text[1] ^ subkey1[2];
	tempText[3] = text[2] ^ subkey1[3];
	tempText[4] = text[1] ^ subkey1[4];
	tempText[5] = text[2] ^ subkey1[5];
	tempText[6] = text[4] ^ subkey1[6];
	tempText[7] = text[1] ^ subkey1[7];

	//need to input this into S0 and S1

	delete[] text;
	text = tempText;
	return text;
}
