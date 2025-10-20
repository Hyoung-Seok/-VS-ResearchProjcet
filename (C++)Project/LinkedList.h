#pragma once
typedef int LData;

struct Node
{
	LData data;
	Node* nextNode = nullptr;
};

struct LinkedList
{
	Node* head = nullptr;
	Node* cur = nullptr;
	Node* prev = nullptr;
	int (*comp)(LData d1, LData d2) = nullptr;
	int count = 0;
};

typedef LinkedList List;

void InitList(List* p_list);
void Add(List* p_list, LData data);

bool First(List* p_list, LData* data);
bool Next(List* p_list, LData* data);

LData Remove(List* p_list);
LData RemoveAt(List* p_list, int index);

int Count(List* p_list);
bool CheckListEmpty(List* p_list);

void SetSortedRule(List* p_list, int (*comp)(LData d1, LData d2));
