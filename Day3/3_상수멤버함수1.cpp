// 4_상수멤버함수1.cpp    119 page ~
#include <iostream>
/*
class Point
{
public:
	int x, y; 
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	void print()          // header와 분리해서 void print();로 선언하면, 컴파일러가 이 함수가 값을 바꾸는지 아닌지 판단할 수 없음. 이 안에서 x,y가 바뀔지 안바뀔지 판단 불가
						  // 상수니까 무조건 print 못불러로 한 것임
		                  // 하지만 읽는건 허용해야 하지 않느냐 → 이 안에서 절대 값은 안바꿀게. 상수라고 해도 허용해줘
	{
		std::cout << x << ", " << y << std::endl;
	}
};
int main() 
{
	const Point p(1, 2);
	//p.x = 10;		 // error. public이지만 상수라 값을 바꿀수 없음
	//p.set(10, 20);	 // error
	p.print();		 // error.
}
*/

class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	// 상수 멤버 함수 : 멤버 함수 안에서 멤버 데이터를 수정하지 않을 것이라고 컴파일러에게 알려주는 것
	//                  1. 상수 멤버함수 안에서 멤버 변수를 수정하면 에러
	//                  2. 상수 객체라도 상수 멤버함수는 호출 가능
	// 모든 c++ 개발자는 상수 객체를 만들 수 밖에 없음

	

	void print() const     // header와 분리해서 void print();로 선언하면, 컴파일러가 이 함수가 값을 바꾸는지 아닌지 판단할 수 없음. 이 안에서 x,y가 바뀔지 안바뀔지 판단 불가
						   // const는 반드시 선언부에 놓아야함. 컴파일러에게 "나 값 안바꾸는 함수거든. 혹시 상수 객체라도 나 부를 수 있게 해줘". 정확히는 양쪽에 다 적어야함
	{
		// x = 100; // error. 상수 멤버함수에서는 멤버데이터 수정 안됨.
		std::cout << x << ", " << y << std::endl;
	}
};
int main()
{
	const Point p(1, 2);
	//p.x = 10;		 // error. public이지만 상수라 값을 바꿀수 없음
	//p.set(10, 20);	 // error
	p.print();		 // error.
	                 // 단, print()가 상수 멤버 함수라면 ok.
}


