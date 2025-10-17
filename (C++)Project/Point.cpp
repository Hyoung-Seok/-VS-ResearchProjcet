#include "Point.h"
#include <iostream>

void InitPoint(Point* p, int x, int y)
{
	p->x = x;
	p->y = y;
}

void PrintPoint(const Point* p)
{
	std::cout << "��ǥ : " << '(' << p->x << ', ' << p->y << ')' << std::endl;
}

int Compare(Point* p1, Point p2)
{
	// �� ���� ��� ������ 0
	if (p1->x == p2.x && p1->y == p2.y)
		return 0;
	// x���� ������ 1
	if (p1->x == p2.x)
		return 1;
	// y���� ������ 2
	if (p1->y == p2.y)
		return 2;

	return -1;
}
