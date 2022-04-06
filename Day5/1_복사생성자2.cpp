// 1_복사생성자  92 page  **중요한 예제 시험문제 나옴
#include <iostream>

class Point
{
	int x, y;
public:
	Point() : x(0), y(0) {} // 1
	Point(int a, int b) : x(a), y(b) {} // 2

	Point(const Point& pt) : x(pt.x), y(pt.y)
	{
		std::cout << "복사생성자" << std::endl;
	}
};

void f1(Point pt) {}  // Point pt = p1 ( 함수 인자가 넘어가는 모양은 이것이다!)
//void f1(Point& pt) {}  // Point& pt = p1   (함수 인자가 안불린다 !! ) *** 문제

Point f2()   // return 시 값 타입. pt를 복사한 temporary를 만들어서 갖다 줌 (이 때 복사 생성자를 만들것임)
{
	Point pt;
	return pt;
}

int main()
{
	// 시험 !!
	// 복사 생성자가 호출되는 3가지 경우

	// 1. 객체 생성시 자신과 동일 타입의 객체로 초기화 될때
	Point p1(1, 2);
	Point p2 = p1;   // Point p2(p1) 과 동일.  <== 이 순간 복사 생성자 호출

	// 2. 함수 호출시 인자를 call by value로 받을때
	f1(p1);

	// 3. 함수가 객체를 "값 타입"으로 반환 할 때
	//    임시 객체로 반환되는데, 임시 객체를 만들 때 복사 생성자 호출
	f2();
}
