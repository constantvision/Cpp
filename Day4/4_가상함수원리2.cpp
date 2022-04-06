#include <iostream>

// 아래 코드는 좋은 코드 아닙니다. 절대 실전에서는 사용하지 마세요
// 학습을 위해서 만든 코드입니다.

class A
{
	int a;
public:
	//void foo() { std::cout << "foo" << std::endl; }         // Case 1번
	//virtual void foo() { std::cout << "foo" << std::endl; } // Case 2번
	//virtual void foo() { std::cout << "foo" << std::endl; }   // Case 3번
	void foo() { std::cout << "foo" << std::endl; }         // Case 4번
};

class B   // 주의 상속관계 아닙니다.
{
	int b;
public:
	//void goo() { std::cout << "goo" << std::endl; }          // Case 1번
	//virtual void goo() { std::cout << "goo" << std::endl; }  // Case 2번
	//void goo() { std::cout << "goo" << std::endl; }          // Case 3번
	virtual void goo() { std::cout << "goo" << std::endl; }    // Case 4번
};

int main()
{
	A aaa;
	// B* p = &aaa;  // error. A와 B는 아무런 연관성이 없기 때문. static_casting은 서로 다른 종류는 못하므로 못씀
	B* p = reinterpret_cast<B*>(&aaa); // ok.. 
	p->goo();  // foo? goo? 
			   // 컴파일러가 하는일
			   // 1. goo가 가상인지 아닌지 조사 
			   // 2. 가상이 아니면 : static binding, 포인터 타입으로 호출
			   //         가상이면 : dynamic binding. 가상함수 테이블 참조해서 호출
			   //         가상이면 : p->vtable[1]() (RTTI 바로 다음. 거기가서 꺼내고 호출)
	
			
}
// Case 1) foo 비가상, goo 비가상 : goo 호출
// Case 2) foo 가상  , goo 가상   : foo 호출
// Case 3) foo 가상  , goo 비가상 : goo 호출
// Case 4) foo 비가상, goo 가상   : error (실행할 떄 error)
