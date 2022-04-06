// 8_스마트포인터4
#include <iostream>

// 스마트포인터 역사
// 1990년대에 "처음 개념이 등장하고"
// 2000년초 "boost" 라는 라이브러리에서 "shared_ptr" 이라는 스마트 포인터 제공
// 2011년(C++11)에서 "shared_ptr"을 C++ 표준으로 채택

#include <memory>  // C++ 표준의 스마트포인터(share_ptr)을 위한 헤더.

class Car
{
	int speed;
public:
	void Go() { std::cout << "Car Go" << std::endl; }
	~Car() { std::cout << "~Car" << std::endl; }
};

int main()
{
	//std::shared_ptr<Car> sp1 = new Car; // error. 생성자가 explicit
	std::shared_ptr<Car> sp1(new Car); // ok

	std::shared_ptr<Car> sp2 = sp1; // ok. 복사 생성자, 참조 계수 증가

	// 핵심 1. 스마트포인터의 크기
	std::cout << sizeof(Car*) << std::endl;
	std::cout << sizeof(sp1) << std::endl; // 포인터보다 2배가량 크다

	// 핵심 2. 스마트포인터는 포인터 역할도 하지만 정체는 "객체"입니다.
	// "->" 뿐 아니라 "."도 가능합니다

	// -> : 대상체(Car)의 멤버 함수 접근
	sp1->Go();   // sp1.operator->()

	// . : 자신(shared_ptr)의 멤버 접근
	int n = sp1.use_count();
	std::cout << n << std::endl;

}

// 파이썬의 모든 변수는 결국 "스마트포인터처럼 동작합니다."
n1 = 10
n2 = n1

// Swift는 모든 객체 관리를 "ARC" 라는 이름으로 관리합니다.
// Automatic Reference Counting
// => 결국 스마트포인터 개념일 뿐입니다.