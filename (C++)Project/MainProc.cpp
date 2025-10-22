#include<iostream>
#include<random>
#include "DoublyLinkedList.h"
using namespace std;

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 100);

	List list;
	InitList(&list);

	for(int i = 0; i < 10; i++)
	{
		Add(&list, dist(gen));
	}

	// 저장된 데이터 값 확인
	LData data;
	if(First(&list, &data) == true)
	{
		cout << data << ", ";

		while(Next(&list, &data) == true)
		{
			cout << data << ", ";
		}

		cout << endl << "저장된 데이터 갯수 : " << Count(&list) << endl << endl;
	}

	// 첫 번째 데이터 삭제
	First(&list, &data);
	Remove(&list);

	if (First(&list, &data) == true)
	{
		cout << data << ", ";

		while (Next(&list, &data) == true)
		{
			cout << data << ", ";
		}

		cout << endl << "저장된 데이터 갯수 : " << Count(&list) << endl << endl;
	}

	// 특정 위치 삭제 확인
	RemoveAt(&list, 8);
	if (First(&list, &data) == true)
	{
		cout << data << ", ";

		while (Next(&list, &data) == true)
		{
			cout << data << ", ";
		}

		cout << endl << "저장된 데이터 갯수 : " << Count(&list) << endl << endl;
	}

	return 0;
}