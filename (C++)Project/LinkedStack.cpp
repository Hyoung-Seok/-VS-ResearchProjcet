#include "LinkedStack.h"
#include <iostream>
using namespace std;

void LInit(Stack* p_stack)
{
	if (p_stack == nullptr)
	{
		return;
	}

	// 헤드 노드만 존재하는 경우
	if(p_stack->head == nullptr)
	{
		p_stack->head = new Node();
	}

	// 데이터가 존재하는 경우
	auto cur = p_stack->head->next;

	while (cur != nullptr)
	{
		auto next = cur->next;
		delete cur;
		cur = next;
	}

	p_stack->head->next = nullptr;
}

void LPush(Stack* p_stack, Data data)
{
	if(p_stack == nullptr || p_stack->head == nullptr)
	{
		return;
	}

	auto newNode = new Node();
	newNode->data = data;

	// 기존 노드 연결
	newNode->next = p_stack->head->next;

	// 헤드 노드와 새 노드 연결
	p_stack->head->next = newNode;
}

Data LPop(Stack* p_stack)
{
	if(p_stack == nullptr || LIsEmpty(p_stack))
	{
		cout << "스택이 존재하지 않거나 꺼낼 데이터가 없습니다!" << endl;
		return -1;
	}

	auto result = p_stack->head->next->data;
	auto delNode = p_stack->head->next;

	p_stack->head->next = delNode->next;
	delete delNode;

	return result;
}

Data LPeek(Stack* p_stack)
{
	if (p_stack == nullptr || LIsEmpty(p_stack))
	{
		cout << "스택이 존재하지 않거나 꺼낼 데이터가 없습니다!" << endl;
		return -1;
	}

	return p_stack->head->next->data;
}

bool LIsEmpty(Stack* p_stack)
{
	return p_stack->head->next == nullptr;
}
