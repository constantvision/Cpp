// 상속과 생성자.   135page ~
#include <iostream>

// 아래 코드에서 에러를 모두 찾아 보세요
class Base
{
public:
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	//Derived(){}                           // Derived()      : Base()  {}
	//Derived(int a) {	}                  // Derived(int a) : Base()  {}

	// 1. 기반 클래스에 디폴트 생성자가 없거나
	// 2. 기반 클래스의 다른 생성자를 호출하고 싶다면
	// 아래처럼 명시적으로 호출해야함

	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}

};

int main()
{
}




