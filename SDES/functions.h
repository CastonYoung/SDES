#pragma once

enum TextType { plain, cipher, key };

const int S0[][4] = { {1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 0, 3}, {3, 1, 3, 2} };
const int S1[][4] = { {0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 1, 3} };

bool* getInput(int textType);

bool* IPFunction(bool* text);

bool* InverseIPFunction(bool* text);

bool* FunctionFk(bool* text, bool* subkey1);

bool* Switch(bool* text);

bool* GenKey1(bool* text);

bool* GenKey2(bool* text);


