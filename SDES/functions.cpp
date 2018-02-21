
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

bool* getInput(int textType)
{

	bool* inputText = new bool[8];


	for (int i{}; i < 8; i++)
	{
		char rawInput;
		cin >> rawInput;
		auto const currentBit = rawInput - '0';
		inputText[i] = currentBit;
	}

	return inputText;
}
bool* getKey(int textType)
{

	bool* inputText = new bool[10];


	for (int i{}; i < 10; i++)
	{
		char rawInput;
		cin >> rawInput;
		auto const currentBit = rawInput - '0';
		inputText[i] = currentBit;
	}

	return inputText;
}


void IPFunction(bool textIP[])
{
	bool tempIP[8];

	tempIP[0] = textIP[1];
	tempIP[1] = textIP[5];
	tempIP[2] = textIP[2];
	tempIP[3] = textIP[0];
	tempIP[4] = textIP[3];
	tempIP[5] = textIP[7];
	tempIP[6] = textIP[4];
	tempIP[7] = textIP[6];

	for (int i = 0; i < 8; i++) textIP[i] = tempIP[i];
	
}

void InverseIPFunction(bool textIIP[])
{
	bool tempIIP[8];
	tempIIP[0] = textIIP[3];
	tempIIP[1] = textIIP[0];
	tempIIP[2] = textIIP[2];
	tempIIP[3] = textIIP[4];
	tempIIP[4] = textIIP[6];
	tempIIP[5] = textIIP[1];
	tempIIP[6] = textIIP[7];
	tempIIP[7] = textIIP[5];

	for (int i = 0; i < 8; i++) textIIP[i] = tempIIP[i];
}

bool* FunctionFk(bool textFFK[], bool subkey1[])
{
	// E/P Expansion permutation
	bool eP[8]; //vlaues for the text being permutated
	int p4Decimal[2]; //decimal values returned from the tables
	bool tR[4]; //table result container (from positions in s0 and s1)

	eP[0] = textFFK[3] ^ subkey1[0];
	eP[1] = textFFK[0] ^ subkey1[1];
	eP[2] = textFFK[1] ^ subkey1[2];
	eP[3] = textFFK[2] ^ subkey1[3];

	eP[4] = textFFK[1] ^ subkey1[4];
	eP[5] = textFFK[2] ^ subkey1[5];
	eP[6] = textFFK[3] ^ subkey1[6];
	eP[7] = textFFK[0] ^ subkey1[7];


	//get values from table
	p4Decimal[0] = S0[binaryConversion(eP[0], eP[3])][binaryConversion(eP[1], eP[2])];
	p4Decimal[1] = S1[binaryConversion(eP[4], eP[7])][binaryConversion(eP[5], eP[6])];

	int first = p4Decimal[0];
	int second = p4Decimal[1];

	bool p4Holder1[2] = { 0,0 };
	decimalConversion(first, p4Holder1);
	bool p4Holder2[2] = { 0,0 };
	decimalConversion(second, p4Holder2);

	tR[0] = p4Holder1[1];
	tR[1] = p4Holder2[1];
	tR[2] = p4Holder2[0];
	tR[3] = p4Holder1[1];

	return tR;
}

bool* Switch(bool textSW[])//Switches the first and second halves of 8 bit data.
{
	bool tempTextSW[8];
	tempTextSW[0] = textSW[4];
	tempTextSW[1] = textSW[5];
	tempTextSW[2] = textSW[6];
	tempTextSW[3] = textSW[7];
	tempTextSW[4] = textSW[0];
	tempTextSW[5] = textSW[1];
	tempTextSW[6] = textSW[2];
	tempTextSW[7] = textSW[3];

	return tempTextSW;
}

void GenKey1(bool textG1[], bool* keyG1)
{
	
	bool tempG1[8];

	tempG1[0] = textG1[5];
	tempG1[1] = textG1[4];
	tempG1[2] = textG1[9];
	tempG1[3] = textG1[1];
	tempG1[4] = textG1[0];
	tempG1[5] = textG1[6];
	tempG1[6] = textG1[7];
	tempG1[7] = textG1[8];

	keyG1[0] = tempG1[0];
	keyG1[1] = tempG1[1];
	keyG1[2] = tempG1[2];
	keyG1[3] = tempG1[3];
	keyG1[4] = tempG1[4];
	keyG1[5] = tempG1[5];
	keyG1[6] = tempG1[6];
	keyG1[7] = tempG1[7];
	

}

void GenKey2(bool textG2[], bool* keyG2)
{
	bool tempG2[8];

	tempG2[0] = textG2[7];
	tempG2[1] = textG2[2];
	tempG2[2] = textG2[5];
	tempG2[3] = textG2[4];
	tempG2[4] = textG2[9];
	tempG2[5] = textG2[1];
	tempG2[6] = textG2[8];
	tempG2[7] = textG2[0];

	keyG2[0] = tempG2[0];
	keyG2[1] = tempG2[1];
	keyG2[2] = tempG2[2];
	keyG2[3] = tempG2[3];
	keyG2[4] = tempG2[4];
	keyG2[5] = tempG2[5];
	keyG2[6] = tempG2[6];
	keyG2[7] = tempG2[7];


}


int binaryConversion(bool one, bool two)
{

	if (one && two)
		return 3;
	else if (one && !two)
		return 2;
	else if (!one && two)
		return 1;
	else
		return 0;

}

void decimalConversion(int decimal, bool ph4[])
{
	bool bits[2]{};

	if (decimal == 3)
	{
		bits[0] = 1;
		bits[1] = 1;
	} else if (decimal == 2)
	{
		bits[0] = 1;
		bits[1] = 0;
	}
	else if (decimal == 1)
	{
		bits[0] = 0;
		bits[1] = 1;
	}
	else
	{
		bits[0] = 0;
		bits[1] = 0;
	}
		
	ph4[0] = bits[0];
	ph4[1] = bits[1];

}