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

	// ����� ������ �� Ȯ��
	LData data;
	if(First(&list, &data) == true)
	{
		cout << data << ", ";

		while(Next(&list, &data) == true)
		{
			cout << data << ", ";
		}

		cout << endl << "����� ������ ���� : " << Count(&list) << endl << endl;
	}

	// ù ��° ������ ����
	First(&list, &data);
	Remove(&list);

	if (First(&list, &data) == true)
	{
		cout << data << ", ";

		while (Next(&list, &data) == true)
		{
			cout << data << ", ";
		}

		cout << endl << "����� ������ ���� : " << Count(&list) << endl << endl;
	}

	// Ư�� ��ġ ���� Ȯ��
	RemoveAt(&list, 8);
	if (First(&list, &data) == true)
	{
		cout << data << ", ";

		while (Next(&list, &data) == true)
		{
			cout << data << ", ";
		}

		cout << endl << "����� ������ ���� : " << Count(&list) << endl << endl;
	}

	return 0;
}