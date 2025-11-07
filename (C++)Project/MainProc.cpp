#include<iostream>
//#include"ArrayStack.h"
//#include"LinkedStack.h"
#include "InfixToPostfix.h"
using namespace std;

int main()
{
	string infixExp = "(4+8)*(6-5)/((3-2)*(2+2))";
	string postfixExp = InfixToPostfix(infixExp);

	cout << postfixExp << endl;

	return 0;
}