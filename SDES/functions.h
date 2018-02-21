#pragma once

#include <vector>

enum TextType { plain, cipher, key };

vector<bool> getInput(int textType);

vector<bool> IPFunction(const vector<bool> text);

vector<bool> InverseIPFunction(const vector<bool> text);

vector<bool> FunctionFk(vector<bool> text, const vector<bool> subkey1);

vector<bool> Switch(const vector<bool> text);

vector<bool> GenKey1(const vector<bool> text);

vector<bool> GenKey2(const vector<bool> text);

int binaryConversion(bool one, bool two);

vector<bool> decimalConversion(int decimal);

