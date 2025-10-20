#include<iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedList list;

	InitList(&list);

	// 10개의 데이터 삽입
	for(int i = 0; i < 10; ++i)
	{
		Add(&list, i + 1);
	}

	// 데이터 확인
	auto data = 0;
	int index = 1;

	if(First(&list, &data) == true)
	{
		cout << index << "번 데이터 : " << data << endl;
		index++;

		while(Next(&list, &data) == true)
		{
			cout << index << "번 데이터 : " << data << endl;
			index++;
		}

		cout << endl;
	}

	//첫 번째 데이터 삭제
	First(&list, &data);
	Remove(&list);
	index = 1;

	if (First(&list, &data) == true)
	{
		cout << index << "번 데이터 : " << data << endl;
		index++;

		while (Next(&list, &data) == true)
		{
			cout << index << "번 데이터 : " << data << endl;
			index++;
		}

		cout << endl;
	}

	// 5번째 데이터 삭제
	RemoveAt(&list, 4);
	index = 0;

	if (First(&list, &data) == true)
	{
		cout << index << "번 데이터 : " << data << endl;
		index++;

		while (Next(&list, &data) == true)
		{
			cout << index << "번 데이터 : " << data << endl;
			index++;
		}

		cout << endl;
	}

	// 0번째 데이터 삭제
	RemoveAt(&list, 0);
	index = 0;

	if (First(&list, &data) == true)
	{
		cout << index << "번 데이터 : " << data << endl;
		index++;

		while (Next(&list, &data) == true)
		{
			cout << index << "번 데이터 : " << data << endl;
			index++;
		}

		cout << endl;
	}

	return 0;
}