//  5_연산자재정의 - 182(131) page
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	void print() const 	{ std::cout << x << ", " << y << std::endl;	}
};

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

	// 다음중 어떤 코드가 보기 좋을 까요 ?
	Point p3 = Add(p1, p2);  // Add 함수 만들고 인자 2개를 보냄. C스타일
	Point p4 = p1.Add(p2);   // 멤버함수 사용. 객체지향 스타일
	Point p5 = p1 + p2;      // C++ 창시자의 말 : "단축 표기의 미학"

	// 연산자 재정의의 핵심
	// => 사용자 정의 타입에 대해서는 연산자를 사용할수 있게 하자!!
}

