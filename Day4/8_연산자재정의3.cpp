// 5_연산자재정의 - 182(131) page
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

	friend Point operator+(const Point& p1, const Point& p2);
};
// 멤버가 아닌 operator+ 함수
Point operator+(const Point& p1, const Point& p2)
{
	std::cout << "멤버가 아닌 operator+" << std::endl;

	Point temp(p1.x + p2.x, p1.y + p2.y);
	return temp;
}

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

	Point p3 = p1 + p2; // 1) p1.operator+(p2) 가 가능하면 사용 (우선순위 먼저)
						// 2) operator+(p1, p2) 가 가능하면 사용
						// 1, 2 가 모두 실패하면 컴파일 에러.

	p3.print();

	// 연산자 재정의시
	// 멤버 함수와 멤버가 아닌 함수 중 어느것이 좋은가요?

	// 1. "멤버로 하자."  주장의 근거 : private 데이터 접근은 멤버가 편하다.

	// 2. "일반함수로 하자." 주장의 근거 : 멤버 함수로 만들 수 없을 때가 있다.

	// 아래 코드를 "멤버함수"로 만드는 것을 생각해보자
	int n = 3;

	Point p4 = p1 + p2;  // p1.operator+(Point) 가 있으면 ok
	Point p5 = p1 + n;   // p1.operator+(int)  가 있으면 ok
	Point p6 = n + p1;   // n.operator+(Point) 가 있으면 되는데..
						 // 그런데, n는 user type이 아니므로 멤버함수가 없다
						 // 그런데, 멤버가 아닌 함수로는 만들 수 있다.
						 // operator+(int, Point)로 하면 된다.

	// 재미있는 파이썬의 철학
	p6 = p1 + n   // p1.__add__(Int) 

	p7 = n  + p1  // 1. n.__add__(Point) 이 가능하면 사용
				  // 2. p1.__radd__(Int) 를 사용
}

// C#, java : 멤버 함수 개념만 존재..
// swift, python : 멤버 함수, 일반 함수 모두 존재

// python : private 개념이 없으므로 모든 일반 함수에서 멤버 접근 가능
// swift  : 일반 함수에서 private 멤버 접근 안됨.