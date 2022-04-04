#include <iostream>

// 객체지향의 핵심 1. 프로그램에서 필요한 타입을 먼저 설계 하자!!
//				   2. 타입을 만들때 "상태를 나타내는 데이터와  연산을 수행하는 함수"
//                    를 묶어서 타입으로 설계하자

// C언어   : 구조체에 함수를 넣을 수 없다.
// C++언어 : 구조체에 함수를 넣을 수 있다.

struct Rect
{
 	int left;              // 멤버 데이터 또는 필드라고 함
	int top;
	int right;
	int bottom;

	// 멤버 함수 (메소드)라고 합니다.
	int getArea()
	{
		return (right - left) * (bottom - top);
	}
};

int main()
{
	Rect rc = { 0,0,10,10 };

	//int n = getRectArea(rc);
	int n = rc.getArea();
	std::cout << n << std::endl;
}
