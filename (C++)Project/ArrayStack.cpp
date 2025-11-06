#include "ArrayStack.h"
#include<iostream>
using namespace std;

void Init(Stack* p_stack)
{
	if(p_stack == nullptr)
	{
		cout << "스택이 존재하지 않습니다!" << endl;
		return;
	}

	p_stack->topIndex = -1;
}

void Push(Stack* p_stack, Data data)
{
	if(p_stack == nullptr || p_stack->topIndex + 1 >= STACK_LEN)
	{
		cout << "스택이 존재하지 않거나 더 이상 저장할 수 없습니다!" << endl;
		return;
	}

	p_stack->topIndex++;
	p_stack->arr[p_stack->topIndex] = data;
}

Data Pop(Stack* p_stack)
{
	if(p_stack == nullptr || IsEmpty(p_stack))
	{
		cout << "스택이 존재하지 않거나 꺼낼 데이터가 없습니다!" << endl;
		return -1;
	}

	Data result = p_stack->arr[p_stack->topIndex--];

	return result;
}

Data Peek(Stack* p_stack)
{
	if(p_stack == nullptr || IsEmpty(p_stack))
	{
		cout << "스택이 존재하지 않거나 꺼낼 데이터가 없습니다!" << endl;
		return -1;
	}

	return p_stack->arr[p_stack->topIndex];
}

bool IsEmpty(Stack* p_stack)
{
	return p_stack->topIndex == -1;
}
