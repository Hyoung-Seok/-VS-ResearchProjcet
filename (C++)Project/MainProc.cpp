#include<iostream>
#include "ArrayList.h"
using namespace std;

int main()
{
	List list;
	Point* pp = nullptr;
	Point comparePoint;

	InitList(&list);

	pp = new Point;
	InitPoint(pp, 2, 1);
	Insert(&list, pp);

	pp = new Point;
	InitPoint(pp, 2, 2);
	Insert(&list, pp);

	pp = new Point;
	InitPoint(pp, 3, 1);
	Insert(&list, pp);

	pp = new Point;
	InitPoint(pp, 3, 2);
	Insert(&list, pp);
	
	// 저장 데이터 출력
	cout << "현재 데이터 수 : " << Count(&list) << endl;

	if(First(&list, &pp))
	{
		PrintPoint(pp);

		while(Next(&list, &pp))
			PrintPoint(pp);
	}

	// 데이터 삭제
	comparePoint.x = 2;
	comparePoint.y = 0;

	if(First(&list, &pp))
	{
		// x가 2인 모든 데이터 삭제
		if(Compare(pp, &comparePoint) == 1)
		{
			pp = Remove(&list);
			delete pp;
		}

		while (Next(&list, &pp))
		{
			if (Compare(pp, &comparePoint) == 1)
			{
				pp = Remove(&list);
				delete pp;
			}
		}
	}

	// 삭제 후 저장 데이터 출력
	cout << "현재 데이터 수 : " << Count(&list) << endl;

	if (First(&list, &pp))
	{
		PrintPoint(pp);

		while (Next(&list, &pp))
			PrintPoint(pp);
	}

	return 0;
}