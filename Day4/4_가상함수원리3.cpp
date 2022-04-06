// 4_가상함수원리3
#include <iostream>

class Base
{
public:
	virtual void foo(int a = 10)
	{
		std::cout << "Base foo : " << a << std::endl;
	}
};

class Derived : public Base // 이번에는 상속관계
{
public:
	void foo(int a = 20) override
	{
		std::cout << "Derived foo : " << a << std::endl;
	}
};

int main()
{
	Derived d;
	d.foo();

	Base* p = &d;
	p->foo(); // 화면 출력 결과 예측해보기
	    	  // 가상이니까 객체것으로 호출해야함. => "Derived foo" 가 호출됨
	 	      // 하지만 10이 나옴
			  // 핵심 1. 디폴트 파라미터는 컴파일시간에 함수 호출문장에 값을 채워 주
			  // Base 클래스에 가서 foo 조사함		  
			  // p->vtable[1]( 10 ) 라고 컴파일 됨.

	// 결론 
	// 디폴트 파라미터 : 컴파일 시간에 동작하는 문법
	// 가상함수        : 실행시간에 동작하는 문법

	// 컴파일 시간에 동작하는 문법과 실행시간에 동작하는 문법을 섞어사용하지 마세요

	// 즉, 가상함수는 되도록 디폴트값 사용하지 마세요
	//     사용했다면 가상함수 재정의시 절대로 디폴트값을 변경하지 마세요

}
