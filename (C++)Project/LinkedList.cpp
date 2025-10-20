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

	if(p_list->comp != nullptr)
	{
		auto cur = p_list->head;

		while(cur->nextNode != nullptr &&
			p_list->comp(data, cur->nextNode->data) != 0)
		{
			cur = cur->nextNode;
		}

		node->nextNode = cur->nextNode;
		cur->nextNode = node;
	}
	else
	{
		auto firstNode = p_list->head->nextNode;
		node->nextNode = firstNode;
		p_list->head->nextNode = node;
	}

	p_list->count++;
}

bool First(List* p_list, LData* data)
{
	if(CheckListEmpty(p_list) == true)
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
	if (CheckListEmpty(p_list) == true)
	{
		return false;
	}

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
		return LData();
	}

	auto deleteNode = p_list->cur;
	auto value = deleteNode->data;

	p_list->prev->nextNode = deleteNode->nextNode;
	p_list->cur = p_list->prev;

	delete deleteNode;
	p_list->count--;

	return value;
}

LData RemoveAt(List* p_list, int index)
{
	if(CheckListEmpty(p_list) == true || index > p_list->count - 1 
		|| index < 0)
	{
		cout << "Out of Range!" << endl;
		return LData();
	}

	LData data;

	First(p_list, &data);
	for(int i = 0; i != index; ++i)
	{
		Next(p_list, &data);
	}

	return Remove(p_list);
}

int Count(List* p_list)
{
	return p_list->count;
}

bool CheckListEmpty(List* p_list)
{
	return p_list == nullptr || p_list->head == nullptr 
		|| p_list->head->nextNode == nullptr;
}

void SetSortedRule(List* p_list, int(*comp)(LData d1, LData d2))
{
	p_list->comp = comp;
}
