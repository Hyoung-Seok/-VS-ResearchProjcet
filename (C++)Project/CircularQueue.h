#pragma once
constexpr int QUE_LENGTH = 100;
typedef int Data;

struct CircularQueue
{
	Data data[QUE_LENGTH];
	int front;
	int rear;
}; typedef CircularQueue CQueue;

void InitQueue(CQueue* pq);

void Enqueue(CQueue* pq, Data item);
Data Dequeue(CQueue* pq);
Data Peek(CQueue* pq);

bool IsEmpty(const CQueue* pq);