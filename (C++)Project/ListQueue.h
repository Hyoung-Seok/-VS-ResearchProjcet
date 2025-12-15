#pragma once
typedef int Data;

struct ListQueueNode
{
	Data data;
	ListQueueNode* next = nullptr;
}; typedef ListQueueNode Node;

struct ListQueue
{
	Node* front = nullptr;
	Node* rear = nullptr;
}; typedef ListQueue LQueue;

void InitQueue(LQueue* pq);

void Enqueue(LQueue* pq, Data item);
Data Dequeue(LQueue* pq);
Data Peek(LQueue* pq);

bool IsEmpty(const LQueue* pq);