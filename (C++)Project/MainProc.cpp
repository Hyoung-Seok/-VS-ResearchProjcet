#include<iostream>
#include "ListQueue.h"
using namespace std;

int main()
{
	LQueue queue;
	InitQueue(&queue);

	for(int i = 1; i < 100; i+=2)
	{
		Enqueue(&queue, i);
	}

	while(IsEmpty(&queue) == false)
	{
		cout << Dequeue(&queue) << " ";
	}

	return 0;
}