#pragma once
typedef int Data;

struct DequeNode
{
	DequeNode* prev = nullptr;
	DequeNode* next = nullptr;
	Data data;
}; typedef DequeNode Node;

struct Deque
{
	Node* head = nullptr;
	Node* tail = nullptr;
};

void InitDeque(Deque* dq);

void push_front(Deque* dq, Data value);
void push_back(Deque* dq, Data value);
Data pop_front(Deque* dq);
Data pop_back(Deque* dq);

Data get_front(Deque* dq);
Data get_back(Deque* dq);

void PrintAllDataFromFront(Deque* dq);
void PrintAllDataFromBack(Deque* dq);

bool IsEmpty(Deque* dq);