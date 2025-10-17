#pragma once
typedef int LData;
constexpr int LEN = 100;

struct ArrayList
{
	LData arr[LEN];
	int count;
	int curPos;
};

// 추상 자료형(ADT)
void InitList(ArrayList* pList);
void Insert(ArrayList* pList, LData data);

bool First(ArrayList* pList, LData* data);
bool Next(ArrayList* pList, LData* data);

LData Remove(ArrayList* pList);
int Count(ArrayList* pList);

void PrintAllValue(const ArrayList* const pList);