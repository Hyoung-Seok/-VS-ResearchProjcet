#include "ArrayList.h"
#include <iostream>
using namespace std;

void InitList(List* pList)
{
	pList->count = 0;
	pList->curPos = 0;
}

void Insert(List* pList, LData data)
{
	if(pList->count >= LEN)
	{
		cout << "더 이상 저장할 수 없습니다." << endl;
		return;
	}

	pList->arr[pList->count++] = data;
}

bool First(List* pList, LData* data)
{
	if (pList->count <= 0)
		return false;

	pList->curPos = 0;
	*data = pList->arr[0];
	return true;
}

bool Next(List* pList, LData* data)
{
	if (pList->curPos >= pList->count - 1)
		return false;

	*data = pList->arr[++pList->curPos];
	return true;
}

LData Remove(List* pList)
{
	if (pList->count <= 0)
	{
		cout << "삭제할 데이터가 없습니다." << endl;
		return LData();
	}

	const LData result = pList->arr[pList->curPos];

	for(int i = pList->curPos; i < pList->count - 1; ++i)
	{
		pList->arr[i] = pList->arr[i + 1];
	}

	pList->count--;
	pList->curPos--;

	return result;
}

int Count(List* pList)
{
	return pList->count;
}

void PrintAllValue(const List* const pList)
{
	for(int i = 0; i < pList->count; ++i)
	{
		cout << pList->arr[i] << ", ";
	}
	cout << endl;
}
