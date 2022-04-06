#include <iostream>

class Car
{
	int color;
	static int cnt;
public:
	Car() { ++cnt; }
	~Car() { --cnt; }

//	int get_count() { return cnt; }  // 객체가 있어야만 호출가능한 함수
	static_int get_count() { return cnt; } // 객체가 없어도 호출가능한 함수
};
int Car::cnt = 0; // private에 있어도.. 외부 초기화는 가능합니다

int main()
{
	// Car 객체가 없을 때도 .. 갯수를 파악할 수 있어야 한다.
	// Static 멤버 함수는 객체가 없어도 "클래스이름::static함수이름"으로 호출 가능
	std::cout << Car::get_count() << std::endl;

	Car c1;
	Car c2;

//	std::cout << c1.get_count() << std::endl; // 가능하지만, 가독성 나쁨
	std::cout << Car::get_count() << std::endl;

}

// 정리
// 1. static 멤버 데이터 : 객체가 없어도 메모리에 존재, 객체 크기에 포함 안됨
//  => 접근 지정자를 사용할 수 있는 전역변수
//  => 특정 클래스만 사용가능한 전역변수 ..

// 2. static 멤버 함수 : 객체가 없어도 호출 가능한 함수
//  => 객체가 없어도 호출가능하므로, 결국은 일반 함수와 같은 개념
//  => 특정 클래스의 private static 멤버에 접근 가능한 일반함수 !