#include "InfixToPostfix.h"
#include "linkedstack.h"
#include <cctype>
#include <iostream>
using namespace std;

// 쟁반
Stack stack;

string InfixToPostfix(const string& infix)
{
	string postfix;
	LInit(&stack);

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
					LPush(&stack, ch);
					break;

				// 닫는 괄호인 경우
				case ')':
					while(true)
					{
						char pop = LPop(&stack);

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
					while(LIsEmpty(&stack) == false && 
						CompareOpPrec(LPeek(&stack), ch) >= 0)
					{
						postfix += LPop(&stack);
					}

					// 아니라면 연산자를 스택에 저장
					LPush(&stack, ch);
					break;
			}
		}
	}

	// 남아있는 연산을 모두 후위 연산자에 저장
	while (LIsEmpty(&stack) == false)
	{
		postfix += LPop(&stack);
	}

	return postfix;
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
