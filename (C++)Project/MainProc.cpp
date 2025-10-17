#include<iostream>
#include "ArrayList.h"
using namespace std;

int main()
{
	ArrayList array_list;

	InitList(&array_list);

	// 배열 기반 리스트에 값 삽입
	for(int i = 0; i < 100; ++i)
	{
		Insert(&array_list, i);
	}

	// 값 확인
	LData data;
	First(&array_list, &data);
	cout << data << ", ";

	while(Next(&array_list, &data) == true)
	{
		cout << data << ", ";
	}
	cout << endl;

	// 첫 번째 값 제거
	First(&array_list, &data);
	data = Remove(&array_list);

	// 값 제거 후 확인
	cout << "제거된 데이터 : " << data << endl;
	cout << "리스트 수 : " << Count(&array_list) << endl;

	PrintAllValue(&array_list);

	return 0;
}