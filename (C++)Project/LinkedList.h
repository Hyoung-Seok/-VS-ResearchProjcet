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
	int count = 0;
};

typedef LinkedList List;

void InitList(List* p_list);
void Add(List* p_list, LData data);

bool First(List* p_list, LData* data);
bool Next(List* p_list, LData* data);

LData Remove(List* p_list);

int Count(List* p_list);
