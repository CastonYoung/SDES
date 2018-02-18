
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

bool* GenKey1(bool* text)//[10]
{
	/*auto const keypart1 = new bool[5];
	auto const keypart2 = new bool[5];
	keypart1[0] = text[2];
	keypart1[1] = text[4];
	keypart1[2] = text[1];
	keypart1[3] = text[6];
	keypart1[4] = text[3];

	keypart2[0] = text[9];
	keypart2[1] = text[0];
	keypart2[2] = text[8];
	keypart2[3] = text[7];
	keypart2[4] = text[5];

	auto const newpart1 = new bool[5];
	auto const newpart2 = new bool[5];
	auto size = sizeof(keypart1)/sizeof(keypart1[0]);
	memcpy_s(newpart1, size, keypart1, size);
	memcpy_s(newpart2, size, keypart2, size);

	newpart1[0] = newpart1[3];
	newpart1[1] = newpart1[4];
	newpart1[2] = newpart1[0];
	newpart1[3] = newpart1[1];
	newpart1[4] = newpart1[2];

	newpart2[0] = newpart2[3];
	newpart2[1] = newpart2[4];
	newpart2[2] = newpart2[0];
	newpart2[3] = newpart2[1];
	newpart2[4] = newpart2[2];*/

	auto const key1 = new bool[8];
	key1[0] = text[5];
	key1[1] = text[4];
	key1[2] = text[9];
	key1[3] = text[1];
	key1[4] = text[0];
	key1[5] = text[6];
	key1[6] = text[7];
	key1[7] = text[8];

	delete[] text;
	text = key1;
	return text;
}

bool* GenKey2(bool* text)//[10]
{
	auto const key2 = new bool[8];
	key2[0] = text[7];
	key2[1] = text[2];
	key2[2] = text[5];
	key2[3] = text[4];
	key2[4] = text[9];
	key2[5] = text[1];
	key2[6] = text[8];
	key2[7] = text[0];

	delete[] text;
	text = key2;
	return text;
}