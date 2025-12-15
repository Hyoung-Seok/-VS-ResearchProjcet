#include "CircularQueue.h"
#include <iostream>
using namespace std;

int NextIndex(int index);

void InitQueue(CQueue* pq)
{
	pq->front = pq->rear = 0;
}

void Enqueue(CQueue* pq, Data item)
{
	auto nextIndex = NextIndex(pq->rear);

	// Queue°¡ °¡µæ Ã¡´ÂÁö È®ÀÎ
	if(nextIndex == pq->front)
	{
		cout << "Queue is Full!" << endl;
		return;
	}

	pq->rear = nextIndex;
	pq->data[pq->rear] = item;
}

Data Dequeue(CQueue* pq)
{
	if(IsEmpty(pq))
	{
		cout << "Queue is Empty!" << endl;
		return -1;
	}

	pq->front = NextIndex(pq->front);
	return pq->data[pq->front];
}

Data Peek(CQueue* pq)
{
	if(IsEmpty(pq))
	{
		cout << "Queue is Empty!" << endl;
		return -1;
	}

	return pq->data[NextIndex(pq->front)];
}

int NextIndex(int index)
{
	return (index + 1 >= QUE_LENGTH - 1)
		? 0 : index + 1;
}

bool IsEmpty(const CQueue* pq)
{
	return pq->front == pq->rear;
}
