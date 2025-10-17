#pragma once

struct Point
{
	int x;
	int y;
};

void InitPoint(Point* p, int x, int y);
void PrintPoint(const Point* p);
int Compare(Point* p1, Point p2);

