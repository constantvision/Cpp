#include <iostream>

class Point
{
	int x, y;
public:
	void set(int x, int y)
	{
		// this 활용 1. 멤버 데이타 접근을 명확하게 하고 싶을때.
		this->x = x;
		this->y = y;
	}
	// this 활용 2. this를 반환하면 멤버 함수 호출을 연속으로 할수 있습니다.
	Point* foo() { return this; }
	//	Point  goo() { return *this; } // 절대 값 반환하면 안됩니다.
	Point& goo() { return *this; } // 이렇게 해야 합니다.
};
int main()
{
	Point pt;
	Point* p = &pt;

	// 객체는 . 으로 포인터는 ->
//	pt.foo(); // 객체로 . 으로 멤버 함수
//	p->foo(); // 포인터는 ->으로 멤버 접근 

	Point p1;
	p1.set(10, 20);

	p1.foo()->foo()->foo();

	p1.goo().goo().goo();

	// cout 의 원리가 위 코드입니다.
	std::cout << "A" << "B" << "C" << std::endl;
	// cout.operator<<("A").operator<<("B").operator<<("C")
}