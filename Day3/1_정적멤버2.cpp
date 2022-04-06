// 1번 복사
#include <iostream>

// 방법 2. 전역변수 사용
//  => 전역변수는 객체의 갯수에 상관없이 한개 이다.
//  => 객체의 갯수 파악 성공

// 그런데...!! 전역변수는 
// 1. 어디서나 접근할수 있다. 안전하지 않다. 
//   => 접근지정자로 보호할수 없을까 ?

// 2. Car 뿐 아니라 Truck 등의 다른 클래스에도 갯수를 파악하려면
//  => cnt 가 아닌 cnt_truck 등의 다른 이름의 전역변수 필요


int cnt = 0;

class Car
{
	int color;
public:
	Car() { ++cnt; }
	~Car() { --cnt; }
};
int main()
{
	Car c1;
	Car c2;

	cnt = 10; // 사용자가 실수로 cnt 를 수정했다.

	std::cout << cnt << std::endl;
}