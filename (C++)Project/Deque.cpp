#include "Deque.h"
#include <iostream>
using namespace std;

void InitDeque(Deque* dq)
{
	if(dq->head != nullptr)
	{
		while (IsEmpty(dq) == false)
		{
			pop_front(dq);
		}
	}

	dq->head = nullptr;
	dq->tail = nullptr;
}

void push_front(Deque* dq, Data value)
{
	auto newNode = new Node;

	newNode->data = value;
	newNode->next = dq->head;

	if(IsEmpty(dq))
	{
		dq->tail = newNode;
	}
	else
	{
		dq->head->prev = newNode;
	}

	dq->head = newNode;
}

void push_back(Deque* dq, Data value)
{
	auto newNode = new Node;

	newNode->data = value;
	newNode->prev = dq->tail;

	if(IsEmpty(dq))
	{
		dq->head = newNode;
	}
	else
	{
		dq->tail->next = newNode;
	}

	dq->tail = newNode;
}

Data pop_front(Deque* dq)
{
	if(IsEmpty(dq))
	{
		cout << "Deque is empty!" << endl;
		return -1;
	}

	auto delNode = dq->head;
	auto retData = delNode->data;

	dq->head = delNode->next;
	delete delNode;

	if(dq->head == nullptr)
	{
		dq->tail = nullptr;
	}
	else
	{
		dq->head->prev = nullptr;
	}

	return retData; 
}

Data pop_back(Deque* dq)
{
	if(IsEmpty(dq))
	{
		cout << "Deque is empty!" << endl;
		return -1;
	}

	auto delNode = dq->tail;
	auto retData = delNode->data;

	dq->tail = delNode->prev;
	delete delNode;

	if(dq->tail == nullptr)
	{
		dq->head = nullptr;
	}
	else
	{
		dq->tail->next = nullptr;
	}

	return retData;
}

Data get_front(Deque* dq)
{
	if(IsEmpty(dq))
	{
		cout << "Deque is empty!" << endl;
		return -1;
	}

	return dq->head->data;
}

Data get_back(Deque* dq)
{
	if (IsEmpty(dq))
	{
		cout << "Deque is empty!" << endl;
		return -1;
	}

	return dq->tail->data;
}

void PrintAllDataFromFront(Deque* dq)
{
	if(IsEmpty(dq))
	{
		cout << "Deque is empty!" << endl;
		return;
	}

	auto start = dq->head;
	while(start != nullptr)
	{
		cout << start->data << " ";
		start = start->next;
	}

	cout << endl << "=================================" << endl << endl;
}

void PrintAllDataFromBack(Deque* dq)
{
	if (IsEmpty(dq))
	{
		cout << "Deque is empty!" << endl;
		return;
	}

	auto start = dq->tail;
	while (start != nullptr)
	{
		cout << start->data << " ";
		start = start->prev;
	}

	cout << endl << "=================================" << endl << endl;
}

bool IsEmpty(Deque* dq)
{
	return dq->head == nullptr;
}
