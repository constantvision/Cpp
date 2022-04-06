#include <iostream>
// 핵심 : 기반 클래스의 소멸자는 반드시 가상함수 이어야 한다.
class Base
{
public:
	virtual ~Base(){}
};

class Derived : public Base
{
public:
	Derived() { std::cout << "자원 할당" << std::endl; }
	~Derived() { std::cout << "자원 반납" << std::endl; }
};
int main()
{
//	Derive d;
	Base* p = new Derived;  // 1. sizeof(Derived)의 메모리 할당
						    // 2. Derived 생성자 호출
	delete p;     // 1. 소멸자 호출
				  // p가 Base* 이므로 Base 소멸자만 호출
				  // => 해결책, p 타입이 아닌 객체조사 후 호출되어야 합니다.
	              // => 소멸자를 가상함수로 !!

				  // 2. p가 가리키는 메모리 파괴
}