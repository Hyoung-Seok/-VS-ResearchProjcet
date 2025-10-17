#include "ArrayList.h"
#include <iostream>
using namespace std;

void InitList(ArrayList* pList)
{
	pList->count = 0;
	pList->curPos = 0;
}

void Insert(ArrayList* pList, LData data)
{
	if(pList->count >= LEN)
	{
		cout << "더 이상 저장할 수 없습니다." << endl;
		return;
	}

	pList->arr[pList->count++] = data;
}

bool First(ArrayList* pList, LData* data)
{
	if (pList->count <= 0)
		return false;

	pList->curPos = 0;
	*data = pList->arr[0];
	return true;
}

bool Next(ArrayList* pList, LData* data)
{
	if (pList->curPos >= pList->count - 1)
		return false;

	*data = pList->arr[++pList->curPos];
	return true;
}

LData Remove(ArrayList* pList)
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

int Count(ArrayList* pList)
{
	return pList->count;
}

void PrintAllValue(const ArrayList* const pList)
{
	for(int i = 0; i < pList->count; ++i)
	{
		cout << pList->arr[i] << ", ";
	}
	cout << endl;
}
