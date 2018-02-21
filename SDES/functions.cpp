
#include "stdafx.h"
#include <iostream>
#include "functions.h"

using namespace std;

int S0[4][4] = { { 1,0,3,2 },
{ 3,2,1,0 },
{ 0,2,1,3 },
{ 3,1,3,2 } };

int S1[4][4] = { { 0,1,2,3 },
{ 2,0,1,3 },
{ 3,0,1,0 },
{ 2,1,0,3 } };

vector<bool> getInput(int textType)
{
	int size;
	if (textType == key) size = 10;
	else size = 8;

	vector<bool> inputText;
	inputText.resize(size);

	for(int i{}; i < size; i++)
	{
		char rawInput;
		cin >> rawInput;
		auto const currentBit = rawInput - '0';
		inputText[i] = currentBit;
	}
	
	return inputText;
}


vector<bool> IPFunction(const vector<bool> text)
{
	vector<bool> tempText;
	tempText.resize(8);
	tempText[0] = text[1];
	tempText[1] = text[5];
	tempText[2] = text[2];
	tempText[3] = text[0];
	tempText[4] = text[3];
	tempText[5] = text[7];
	tempText[6] = text[4];
	tempText[7] = text[6];
	
	return tempText;
}

vector<bool> InverseIPFunction(const vector<bool> text)
{
	vector<bool> tempText;
	tempText.resize(8);
	tempText[0] = text[3];
	tempText[1] = text[0];
	tempText[2] = text[2];
	tempText[3] = text[4];
	tempText[4] = text[6];
	tempText[5] = text[1];
	tempText[6] = text[7];
	tempText[7] = text[5];

	return tempText;
}

vector<bool> FunctionFk(vector<bool> text, const vector<bool> subkey1)
{
	// E/P Expansion permutation
	vector<bool> eP; //vlaues for the text being permutated
	eP.resize(8);
	vector<int> p4Decimal; //decimal values returned from the tables
	p4Decimal.resize(2);
	vector<bool> p4Binary; //binary values from the decimal values
	p4Binary.resize(4);
	vector<bool> tR; //table result container (from positions in s0 and s1)
	tR.resize(4);

	eP[0] = text[3] ^ subkey1[0];
	eP[1] = text[0] ^ subkey1[1];
	eP[2] = text[1] ^ subkey1[2];
	eP[3] = text[2] ^ subkey1[3];

	eP[4] = text[1] ^ subkey1[4];
	eP[5] = text[2] ^ subkey1[5];
	eP[6] = text[3] ^ subkey1[6];
	eP[7] = text[0] ^ subkey1[7];


	//get values from table
	p4Decimal[0] = S0[binaryConversion(eP[0], eP[3])][binaryConversion(eP[1], eP[2])];
	p4Decimal[1] = S1[binaryConversion(eP[4], eP[7])][binaryConversion(eP[5], eP[6])];

	vector<bool> p4Holder1 = decimalConversion( p4Decimal[0] );
	vector<bool> p4Holder2 = decimalConversion( p4Decimal[2] );

	tR[0] = p4Holder1[0];
	tR[1] = p4Holder1[1];
	tR[2] = p4Holder2[0];
	tR[3] = p4Holder2[1];

	return tR;
}

vector<bool> Switch(const vector<bool> text)//Switches the first and second halves of 8 bit data.
{
	vector<bool> tempText;
	tempText.resize(8);
	tempText[0] = text[4];
	tempText[1] = text[5];
	tempText[2] = text[6];
	tempText[3] = text[7];
	tempText[4] = text[0];
	tempText[5] = text[1];
	tempText[6] = text[2];
	tempText[7] = text[3];

	return tempText;
}

vector<bool> GenKey1(const vector<bool> text)
{
	vector<bool> key1;
	key1.resize(8);
	key1[0] = text[5];
	key1[1] = text[4];
	key1[2] = text[9];
	key1[3] = text[1];
	key1[4] = text[0];
	key1[5] = text[6];
	key1[6] = text[7];
	key1[7] = text[8];

	return key1;
}

vector<bool> GenKey2(const vector<bool> text)
{
	vector<bool> key2;
	key2.resize(8);
	key2[0] = text[7];
	key2[1] = text[2];
	key2[2] = text[5];
	key2[3] = text[4];
	key2[4] = text[9];
	key2[5] = text[1];
	key2[6] = text[8];
	key2[7] = text[0];

	return key2;
}


int binaryConversion(bool one, bool two)
{
	/**/ if ( one && two )	return 3;
	else if ( one &&!two )	return 2;
	else if (!one && two )	return 1;
	else					return 0;
}

vector<bool> decimalConversion(int decimal)
{
	vector<bool> bits;
	bits.resize(2);

	if (decimal = 3)
	{
		bits[0] = 1;
		bits[1] = 1;
	} else if (decimal = 2)
	{
		bits[0] = 1;
		bits[1] = 0;
	}
	else if (decimal = 1)
	{
		bits[0] = 0;
		bits[1] = 1;
	}
	else
	{
		bits[0] = 0;
		bits[1] = 0;
	}
		
	return bits;
}