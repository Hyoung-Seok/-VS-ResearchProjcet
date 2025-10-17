#pragma once
typedef int LData;
constexpr int LEN = 100;

struct ArrayList
{
	LData arr[LEN];
	int count;
	int cur_position;
};

// 추상 자료형(ADT)
void InitList(ArrayList* pList);
void Insert(ArrayList* pList, LData data);

void First(ArrayList* pList, LData* data);
void Next(ArrayList* pList, LData* data);

LData Remove(ArrayList* pList);
int Count(ArrayList* pList);