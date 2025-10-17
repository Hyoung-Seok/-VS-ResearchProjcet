#include "Point.h"
#include <iostream>

void InitPoint(Point* p, int x, int y)
{
	p->x = x;
	p->y = y;
}

void PrintPoint(const Point* p)
{
	std::cout << "좌표 : " << '(' << p->x << ", " << p->y << ')' << std::endl;
}

int Compare(Point* p1, Point* p2)
{
	// 두 값이 모두 같으면 0
	if (p1->x == p2->x && p1->y == p2->y)
		return 0;
	// x값이 같으면 1
	if (p1->x == p2->x)
		return 1;
	// y값이 같으면 2
	if (p1->y == p2->y)
		return 2;

	return -1;
}
