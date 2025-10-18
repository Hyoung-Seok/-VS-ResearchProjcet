#include "LinkedList.h"
#include "iostream"
using namespace std;

void InitList(List* p_list)
{
	if (p_list == nullptr) return;

	// head가 존재하지 않는다면
	if(p_list->head == nullptr)
	{
		p_list->head = new Node;
		return;
	}

	// head에 다음 데이터가 존재한다면
	if(p_list->head->nextNode != nullptr)
	{
		auto cur = p_list->head->nextNode;
		while(cur != nullptr)
		{
			auto next = cur->nextNode;
			delete cur;
			cur = next;
		}

		p_list->head->nextNode = nullptr;
		p_list->cur = nullptr;
		p_list->count = 0;
	}
}

void Add(List* p_list, LData data)
{
	auto node = new Node;
	node->data = data;

	auto firstNode = p_list->head->nextNode;
	node->nextNode = firstNode;
	p_list->head->nextNode = node;

	p_list->count++;
}

bool First(List* p_list, LData* data)
{
	if(p_list == nullptr || p_list->head == nullptr)
	{
		cout << "저장된 데이터가 없습니다!" << endl;
		return false;
	}

	p_list->cur = p_list->head->nextNode;
	p_list->prev = p_list->head;

	*data = p_list->cur->data;

	return true;
}

bool Next(List* p_list, LData* data)
{
	if(p_list->cur->nextNode == nullptr)
	{
		return false;
	}

	p_list->prev = p_list->cur;
	p_list->cur = p_list->cur->nextNode;

	*data = p_list->cur->data;
	return true;
}

LData Remove(List* p_list)
{
	if(p_list->count == 0)
	{
		cout << "삭제할 데이터가 없습니다." << endl;
	}

	auto deleteNode = p_list->cur;
	auto value = deleteNode->data;

	p_list->prev->nextNode = deleteNode->nextNode;
	p_list->cur = p_list->prev;

	delete deleteNode;
	p_list->count--;

	return value;
}

int Count(List* p_list)
{
	return p_list->count;
}
