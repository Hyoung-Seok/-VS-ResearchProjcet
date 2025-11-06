#include<iostream>
//#include"ArrayStack.h"
//#include"LinkedStack.h"
#include "InfixToPostfix.h"
using namespace std;

int main()
{
	string infixExp = "(1+2*3)/4";
	string postfixExp = InfixToPostfix(infixExp);

	cout << postfixExp << endl;

	return 0;
}