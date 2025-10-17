#pragma once
#include "Point.h"
typedef Point* LData;
constexpr int LEN = 100;

struct ArrayList
{
	LData arr[LEN];
	int count;
	int curPos;
};

typedef ArrayList List;

// 추상 자료형(ADT)
void InitList(List* pList);
void Insert(List* pList, LData data);

bool First(List* pList, LData* data);
bool Next(List* pList, LData* data);

LData Remove(List* pList);
int Count(List* pList);

void PrintAllValue(const List* const pList);