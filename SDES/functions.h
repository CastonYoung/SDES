#pragma once

enum TextType { plain, cipher, key };
enum menuSel { encrypt = 1, decrypt, exitProgram };

bool* getInput(int textType);

bool* getKey(int textType);

void IPFunction(bool textIP[]);

void InverseIPFunction(bool textIIP[]);

void FunctionFk(const bool textFFK[], bool output[], const bool subkey1[]);

void SwitchFn(bool textSW[]);

void GenKey1(const bool key0[], bool* key1);

void GenKey2(const bool key0[], bool* key2);

int binaryConversion(bool one, bool two);

void decimalConversion(int decimal, bool ph4[]);

