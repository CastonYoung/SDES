#pragma once

enum TextType { plain, cipher, key };
enum menuSel { encrypt = 1, decrypt, exitProgram };

bool* getInput(int textType);

void IPFunction(bool* textIP);

void InverseIPFunction(bool textIIP[]);

void FunctionFk(bool textFFK[], bool output[], bool subkey1[]);

void SwitchFn(bool textSW[]);

void GenKey1(bool textG2[], bool* keyG1);

void GenKey2(bool textG2[], bool* keyG2);

bool* getKey(int textType);

int binaryConversion(bool one, bool two);

void decimalConversion(int decimal, bool p4h[]);

