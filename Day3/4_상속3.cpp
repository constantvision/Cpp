// 상속과 생성자.   135page ~
#include <iostream>

// 1. Derived의 객체 생성시 기반클래스(Base) 생성자도 호출된다.
// 2. 호출 순서 
//    A. 기반 클래스 생성자
//    B. 파생 클래스 생성자
// 3. 기반 클래스의 생성자는 항상 디폴트 버전(인자 없는 생성자)의 생성자 호출된다.

// 4. 그런데.. 원리만 알면 되고, 원리가 중요함.


class Base
{
	int x;
public:
	Base()      { std::cout << "Base()"  << std::endl; }
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base()     { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
	int y;
public:
	Derived()       { std::cout << "Derived()" << std::endl; } 
	Derived(int a)  { std::cout << "Derived(int)" << std::endl; }
	~Derived()      { std::cout << "~Derived()" << std::endl; }
};

int main()
{
//	Derived d;  // 이 순간 Derived() 생성자가 불린다. Dervied()의 생성자만 부를까 Base의 생성자도 부를까? oo Base의 Base()생성자도 호출된다/. 	
	Derived d(5); // 기반 클래스 생성자는 기본 (Base()불린다)
}




