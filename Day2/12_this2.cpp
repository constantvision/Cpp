#include <iostream>

class Point
{
	int x, y;
public:
	void set(int x, int y) 
	{
		x = x;	
		y = y;
	}
	Point* foo() { return this; }

};
int main()
{
	Point p1;
	p1.set(10, 20);
}
