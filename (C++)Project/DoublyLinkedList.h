#pragma once
typedef int LData;

struct Node
{
	LData data;
	Node* prev = nullptr;
	Node* next = nullptr;
};

struct DoublyLinkedList
{
	Node* head = nullptr;
	Node* cur = nullptr;
	int count = 0;
};

typedef DoublyLinkedList List;

void InitList(List* p_list);
void Add(List* p_list, LData data);

bool First(List* p_list, LData* data);
bool Next(List* p_list, LData* data);

LData Remove(List* p_list);
LData RemoveAt(List* p_list, int index);

int Count(List* p_list);
bool CheckListNull(List* p_list);