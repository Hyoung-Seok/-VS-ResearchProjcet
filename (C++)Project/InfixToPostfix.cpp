#include "InfixToPostfix.h"
#include "linkedstack.h"
#include <cctype>
#include <iostream>
using namespace std;

string InfixToPostfix(const string& infix)
{
	LinkedStack<char> stack;
	string postfix;

	for(char ch : infix)
	{
		// 피연산자(숫자)인 경우
		if(isdigit(ch) != 0)
		{
			//후위 연산자에 저장
			postfix += ch;
		}
		else
		{
			switch (ch)
			{
				// 여는 괄호인 경우
				case '(':
					stack.Push(ch);
					break;

				// 닫는 괄호인 경우
				case ')':
					while(true)
					{
						char pop = stack.Pop();

						// 여는 괄호가 나올 때까지 후위 연산자에 저장
						if(pop == '(')
							break;
						postfix += pop;
					}
					break;

				// 나머지 연산자의 경우
				case '+': case '-':
				case '*': case '/':
					// 스택이 비어있지 않고, 스택의 top 연산자의 우선순위가 현재 연산자보다
					// 높거나 같다면
					while(stack.IsEmpty() == false && 
						CompareOpPrec(stack.Peek(), ch) >= 0)
					{
						postfix += stack.Pop();
					}

					// 아니라면 연산자를 스택에 저장
					stack.Push(ch);
					break;
			}
		}
	}

	// 남아있는 연산을 모두 후위 연산자에 저장
	while (stack.IsEmpty() == false)
	{
		postfix += stack.Pop();
	}

	return postfix;
}

int CalculatePostfix(const string& postfix)
{
	LinkedStack<int> stack;

	for(char ch : postfix)
	{
		// 피연산자(숫자)인 경우
		if(isdigit(ch) != 0)
		{
			stack.Push(ch - '0');
		}
		else
		{
			// 두 개의 피연산자를 꺼냄
			char op2 = stack.Pop();
			char op1 = stack.Pop();

			switch (ch)
			{
				case '+':
					stack.Push(op1 + op2);
					break;
				case '-':
					stack.Push(op1 - op2);
					break;
				case '*':
					stack.Push(op1 * op2);
					break;
				case '/':
					stack.Push(op1 / op2);
					break;
			}
		}
	}

	return stack.Pop();
}

// 연산자 우선순위 반환
int GetOpePrece(char op)
{
	switch (op)
	{
		case '*':
		case '/':
			return 5;

		case '+':
		case '-':
			return 3;

		case '(':
			return 1;

		default:
			return -1;
	}
}

int CompareOpPrec(char op1, char op2)
{
	int prec1 = GetOpePrece(op1);
	int prec2 = GetOpePrece(op2);

	// op1의 우선순위가 더 높다면
	if (prec1 > prec2) return 1;
	// op2의 우선순위가 더 높다면
	if (prec1 < prec2) return -1;
	// 우선순위가 같다면
	return 0;
}
