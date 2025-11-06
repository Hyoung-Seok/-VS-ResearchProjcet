#pragma once
typedef char Data;

struct Node
{
	Data data = 0;
	Node* next = nullptr;
};

struct LinkedStack
{
	Node* head = nullptr;
};

typedef LinkedStack Stack;

void LInit(Stack* p_stack);				// 스택 초기화

void LPush(Stack* p_stack, Data data);	// 스택에 데이터 넣기
Data LPop(Stack* p_stack);				// 스택에서 데이터 꺼내기
Data LPeek(Stack* p_stack);				// 최상위 데이터 확인

bool LIsEmpty(Stack* p_stack);			// 스택이 비었는지 확인
