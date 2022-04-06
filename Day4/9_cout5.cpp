// 189(138)page
#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
};

std::ostream& operator<<(std::ostream& os, const Point& pt) // ostream& os는 const 붙이면 안됨. <<가 상수함수가 아니기 때문에 os에는 붙이면 안됨. 뒤의 pt는 읽기만 할것이므로 const 붙임
{
	os << pt.x << ", " << pt.y;
	return os;
}

int main()
{
	Point p(1, 2);

	std::cout << p ;  // cout.operator<<(Point) 가 있어야 한다.
					  // 그런데, Point는 사용자가 만든 타입이므로 당연히 없다.
					  // => cout은 이미 만들어진 표준 클래스이므로 멤버추가가 안됨
					  // 멤버로 안되면 일반함수로 가능
					  // operator<<(ostream, Point) . cout의 정체가 ostream, p의 정체가 pointer
					
	std::ostream&       os1 = cout;           // os는 cout 별명입니다.
	const std::ostream& os2 = cout;

	os1 << "A";  // ok    os1.operator<<("A")
	//os2 << "A";  // error os1.operator<<("A")  <= 상수 멤버 함수가 아님

										
}


