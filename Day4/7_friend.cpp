#include <iostream>

class Bike
{
	int gear = 0;
public:
//	void setGear(int n) { gear = n; }

	// friend 함수 : 멤버 함수는 아니지만 private에 접근 가능하게 해달라는 것
	// Q1. 멤버로 하면 되는데 ..왜?   : "멤버함수로 만들수 없을 때가 있다. (연산자 재정의)"
	// 
	// Q2. set/get 만들면 되는데 왜 ? : get/set을 제공하는 것은 모든곳에서 접근 허용하겠다는 의미..
	//									아래 코드는 fixBike 에서만 접근하겠다는 것.
	
	// 캡슐화를 위배하므로 좋지 않은 문법이라고 평가됨.
	// 그래서, C++을 제외한 대부분의 객체지향언어에는 이 문법이 없음
	// 하지만, C++에서는 꽤 자주 활용됩니다.

	friend void fixBike(Bike& b); // friend 파생클래스에 상속은 안됨 .
};

void fixBike(Bike& b)
{
	b.gear = 10;
	
	Bike b2;
	b2.gear = 20;
}

int main()
{
	Bike b;
	fixBike(b);
}