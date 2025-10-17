#include<iostream>
#include "ArrayList.h"
using namespace std;

int main()
{
	List list;

	InitList(&list);

	// 배열 기반 리스트에 값 삽입
	for(int i = 0; i < 100; ++i)
	{
		Insert(&list, i);
	}

	// 값 확인
	LData data;
	First(&list, &data);
	cout << data << ", ";

	while(Next(&list, &data) == true)
	{
		cout << data << ", ";
	}
	cout << endl;

	// 첫 번째 값 제거
	First(&list, &data);
	data = Remove(&list);

	// 값 제거 후 확인
	cout << "제거된 데이터 : " << data << endl;
	cout << "리스트 수 : " << Count(&list) << endl;

	PrintAllValue(&list);

	return 0;
}