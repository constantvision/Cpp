#include <iostream>

// const member function (상수 멤버 함수) 라는 문법은

// 1. 선택이 아닌 필수 문법이다.

// 2. 어떤 멤버 함수가 내부적으로 객체의 상태(멤버 데이터)를 수정하지 않는다면
//    반드시 상수 멤버 함수로 해야한다.

// 3. getter(getxxx()류의 함수들)은 반드시 상수 멤버 함수로 하세요


class Rect
{
	int x, y, w, h;
public:
	Rect(int a, int b, int c, int d) : x(a), y(b), w(c), h(d) {} // 초기화

	//int getArea() { return w * h; }   // 내부적으로 값을 바꾸는 코드가 없기 때문에, 이렇게 하면 내부적으로 틀린 것임
	int getArea() const { return w * h; }  // ** 시험문제 !! 상수 객체는 상수 멤버함수만 부를 수 있다. (맞음)

};

//void foo(Rect r)       // 사용자 정의 타입을 call by value로 하는 것은 나쁜 코드
void foo(const Rect& r)  // 어차피 읽기만 할것이면 되도록이면 이렇게 쓰자. 항상 const reference가 좋음
{
	int n = r.getArea(); // error. r은 상수 인데, 상수가 아닌 객체를 부를 수는 없음
}

int main()
{
	Rect r(1, 1, 10, 10);  // 상수 객체 아님
						   // r은 16 Byte인 큰 객체 → 복사본을 만들면 오버헤드가 많이 든다!!


	int n = r.getArea();   // ok. 아무 문제 없음
	
	std::cout << n << std::endl;

	foo(r);
}



