#include<iostream>
#include "Deque.h"
using namespace std;

int main()
{
	Deque dq;
	InitDeque(&dq);

	for(int i = 0; i <= 50; i++)
	{
		if(i % 2 == 0)
		{
			push_front(&dq, i);
		}
		else
		{
			push_back(&dq, i);
		}
	}

	PrintAllDataFromFront(&dq);

	for(int i = 0; i <= 25; i++)
	{
		cout << "Pop Front: " << pop_front(&dq) << endl;
		cout << "Pop Back: " << pop_back(&dq) << endl << endl;
	}

	return 0;
}