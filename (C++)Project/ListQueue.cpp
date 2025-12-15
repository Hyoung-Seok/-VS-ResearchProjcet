#include "ListQueue.h"
#include <iostream>
using namespace std;

void InitQueue(LQueue* pq)
{
	if(pq->front != nullptr && pq->rear != nullptr)
	{
		// 기존 노드가 존재한다면 해제
		while(IsEmpty(pq) == false)
		{
			Dequeue(pq);
		}
	}

	pq->front = nullptr;
	pq->rear = nullptr;
}

void Enqueue(LQueue* pq, Data item)
{
	auto node = new Node();
	node->data = item;
	node->next = nullptr;

	if(IsEmpty(pq) == true)
	{
		pq->front = node;
		pq->rear = node;
	}
	else
	{
		pq->rear->next = node;
		pq->rear = node;
	}
}

Data Dequeue(LQueue* pq)
{
	if(IsEmpty(pq))
	{
		cout << "Queue is Empty!" << endl;
		return -1;
	}

	auto delNode = pq->front;
	auto retData = delNode->data;
	pq->front = delNode->next;

	delete delNode;
	return retData;
}

Data Peek(LQueue* pq)
{
	if(IsEmpty(pq))
	{
		cout << "Queue is Empty!" << endl;
		return -1;
	}

	return pq->front->data;
}

bool IsEmpty(const LQueue* pq)
{
	return pq->front == nullptr;
}
