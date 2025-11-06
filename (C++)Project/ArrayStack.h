#pragma once
constexpr int STACK_LEN = 100;
typedef int Data;

struct ArrayStack
{
	Data arr[STACK_LEN];
	int topIndex;
};

typedef ArrayStack Stack;

void Init(Stack* p_stack);				// 스택 초기화

void Push(Stack* p_stack, Data data);	// 스택에 데이터 넣기
Data Pop(Stack* p_stack);				// 스택에서 데이터 꺼내기
Data Peek(Stack* p_stack);				// 최상위 데이터 확인

bool IsEmpty(Stack* p_stack);			// 스택이 비었는지 확인