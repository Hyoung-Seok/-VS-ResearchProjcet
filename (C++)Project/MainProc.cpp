#include<iostream>
#include "CircularQueue.h"
using namespace std;

int main()
{
	CQueue queue;
	InitQueue(&queue);

	for(int i = 2; i <= 100; i += 2)
	{
		Enqueue(&queue, i);
	}

	while(!IsEmpty(&queue))
	{
		cout << Dequeue(&queue) << " ";
	}
	return 0;
}