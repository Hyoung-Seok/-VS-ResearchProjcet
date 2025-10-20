#include<iostream>
#include<random>
#include "LinkedList.h"
using namespace std;

void TestList_1();
int SortedRule(LData d1, LData d2)
{
	if (d1 < d2)
		return 0;
	if(d1 >= d2)
		return 1;
}

int main()
{
	//TestList_1();
	List list;

	InitList(&list);
	SetSortedRule(&list, SortedRule);

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 100);

	for(int i = 0; i < 10; ++i)
	{
		int value = dist(gen);
		Add(&list, value);
	}

	auto data = 0;
	int index = 1;

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

void TestList_1()
{
	LinkedList list;
	InitList(&list);

	// 10개의 데이터 삽입
	for (int i = 0; i < 10; ++i)
	{
		Add(&list, i + 1);
	}

	// 데이터 확인
	auto data = 0;
	int index = 1;

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
}