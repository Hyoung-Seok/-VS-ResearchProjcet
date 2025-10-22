#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

void InitList(List* p_list)
{
	if(p_list == nullptr)
		return;

	// Head가 존재하지 않는 경우
	if(p_list->head == nullptr)
	{
		auto newNode = new Node();

		p_list->head = newNode;
		p_list->cur = newNode;
		p_list->count = 0;

		return;
	}

	// Head와 데이터가 존재하는 경우
	auto iter = p_list->head->next;
	while(iter != nullptr)
	{
		auto del = iter;
		iter = iter->next;
		delete del;
	}

	// Head만 존재하는 경우
	p_list->head->next = nullptr;
	p_list->cur = p_list->head;
	p_list->count = 0;
}

// push_front
void Add(List* p_list, LData data)
{
	if(CheckListNull(p_list) == true)
		return;

	auto newNode = new Node();
	newNode->data = data;

	auto oldFirst = p_list->head->next;

	// 새 노드를 연결
	newNode->prev = p_list->head;
	newNode->next = oldFirst;

	// 기존 노드 연결
	p_list->head->next = newNode;
	if (oldFirst != nullptr)
	{
		oldFirst->prev = newNode;
	}

	p_list->count++;
}

bool First(List* p_list, LData* data)
{
	if (CheckListNull(p_list) == true || p_list->head->next == nullptr)
		return false;

	p_list->cur = p_list->head->next;
	*data = p_list->cur->data;

	return true;
}

bool Next(List* p_list, LData* data)
{
	if(CheckListNull(p_list) == true ||
		p_list->cur->next == nullptr)
		return false;

	p_list->cur = p_list->cur->next;
	*data = p_list->cur->data;

	return true;
}

LData Remove(List* p_list)
{
	if(CheckListNull(p_list) == true || p_list->cur == nullptr)
	{
		return -1;
	}

	auto delNode = p_list->cur; // 삭제할 노드
	auto prev = delNode->prev; // 삭제 노드의 이전 노드(최소 Head)
	auto next = delNode->next; // 삭제 노드의 다음 노드(최대 nullptr)

	// 다음 노드로 이동 가능하면
	if(next != nullptr)
	{
		p_list->cur = next;
	}
	// 이전 노드로 이동하고, 이전 노드가 head가 아니라면
	else if(prev != nullptr && prev != p_list->head)
	{
		p_list->cur = prev;
	}
	// cur가 이동이 불가능한 경우(더 이상 남은 노드 없음)
	else
	{
		p_list->cur = nullptr;
	}

	if (prev != nullptr) prev->next = next;
	if (next != nullptr) next->prev = prev;

	LData result = delNode->data;
	delete delNode;
	p_list->count--;

	return result;
}

LData RemoveAt(List* p_list, int index)
{
	// 리스트가 비어있거나 인덱스가 범위를 벗어난 경우
	if (CheckListNull(p_list) == true || index > p_list->count - 1 
		|| p_list->head->next == nullptr)
	{
		return -1;
	}

	LData data;
	if(First(p_list, &data) == true)
	{
		for(int i = 0; i < index; i++)
		{
			Next(p_list, &data);
		}
	}

	return Remove(p_list);
}

int Count(List* p_list)
{
	return p_list->count;
}

bool CheckListNull(List* p_list)
{
	if (p_list == nullptr || p_list->head == nullptr)
	{
		cout << "List is not initialized Or Empty." << endl;
		return true;
	}

	return false;
}


