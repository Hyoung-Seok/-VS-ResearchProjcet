#include<iostream>
#include"ArrayStack.h"
using namespace std;

int main()
{
	Stack stack;
	Data data = 0;

	Init(&stack);

	for(int i = 1; i <= 99; i += 2)
	{
		Push(&stack, i);
	}

	data = Peek(&stack);
	cout << "최상위 데이터: " << data << endl;

	while(IsEmpty(&stack) == false)
	{
		data = Pop(&stack);
		cout << data << " ";
	}

	cout << endl;
	return 0;
}