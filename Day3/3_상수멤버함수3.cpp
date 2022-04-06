#include <iostream>
#include <vector>

class Test
{
public:
	// 동일 이름의 상수 멤버 함수와 비상수 멤버함수를 동시에 만들 수 있음
	// → "overloading" 이라고 함
	//void foo()       { std::cout << "foo" << std::endl; }
	void foo() const { std::cout << "foo const" << std::endl; }
};

int main()
{
	const Test ct;  // ct는 상수 객체 이므로
	ct.foo();       // 상수 멤버 함수만 호출 가능함. " foo const:

	Test t;         // t는 상수 객체가 아님
	t.foo();        // 1. 비상수 멤버함수가 우선권이 있음 " foo "
					// 2. 1번이 없으면 "foo const" 호출
	 // 의도는 동일 이름의 함수를 상수 객체일 때와 비상수 객체일때 다르게 동작하도록 하려고..

	std::vector<int>       v1 = { 1,2,3 };
	const std::vector<int> v2 = { 1,2,3 };

	// 아래 2개는 모든 "객체.operator[](0)" 함수를 호출함 (상수용과 비상수 용을 따로 만들었기 때문에 v2[0] = 10; 이 error
	//int n1 = v1[0]; // ok
	//int n2 = v2[0]; // ok

	//v1[0] = 10; // ok
	//v2[0] = 10; // error


}

