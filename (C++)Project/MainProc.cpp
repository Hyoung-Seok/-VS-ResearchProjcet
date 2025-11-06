#include<iostream>
//#include"ArrayStack.h"
#include"LinkedStack.h"
using namespace std;

int main()
{
	Stack stack;
	LInit(&stack);

	for(int i = 2; i <= 100; i += 2)
	{
		LPush(&stack, i);
	}

	Data data = LPeek(&stack);
	cout << "최상위 데이터: " << data << endl;

	//모든 데이터 꺼내기
	while(LIsEmpty(&stack) == false)
	{
		data = LPop(&stack);
		cout << data << " ";
	}

	cout << endl;

	return 0;
}