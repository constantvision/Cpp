//  5_연산자재정의 - 182(131) page
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	void print() const { std::cout << x << ", " << y << std::endl; }

	Point operator+(const Point& pt)
	{
		std::cout << "멤버로 만든 operator+" << std::endl;

		Point temp(x + pt.x, y + pt.y);
		return temp;
	}

};

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

	Point p3 = p1 + p2;  // 1) p1.operator + (p2)가 가능하면 사용
						 // 2) operator+(p1,p2)가 가능하면 사용
						 // 3) 1과 2가 모두 실패하면 컴파일 에러
	Point p4 = p2 + p1;  // p2.operator+(p1) ok..


	p3.print();
}

