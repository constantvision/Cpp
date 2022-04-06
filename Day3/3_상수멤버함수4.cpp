// 파일 분할
#include <iostream>

class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0);

	void set(int a, int b);

	void print() const;  // 선언부에 const 있어야함

};

Point::Point(int a = 0, int b = 0) : x(a), y(b) 
{
}

void Point::set(int a, int b) 
{ 
	x = a; 
	y = b;
}

void Point::print() const   // 비상수 함수로 오해 안하도록 선언과 구현 두 부분 모두 const 붙여야함
{

	std::cout << x << ", " << y << std::endl;
}


