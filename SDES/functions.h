#pragma once

enum TextType { plain, cipher, key };

bool* getInput(int textType);

bool* IPFunction(bool* text);

bool* InverseIPFunction(bool* text);

bool* FunctionFk(bool* text, bool* subkey1);

bool* Switch(bool* text);

bool* GenKey1(bool* text);

bool* GenKey2(bool* text);

int binaryConversion(bool one, bool two);

bool* decimalConversion(int decimal);

