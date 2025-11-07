#pragma once
#include <string>
using namespace std;

string InfixToPostfix(const string& infix);
int CalculatePostfix(const string& postfix);

int GetOpePrece(char op);
int CompareOpPrec(char op1, char op2);

