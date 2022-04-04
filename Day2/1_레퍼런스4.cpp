// 1_레퍼런스4.   100 page
#include <string>
int x = 0;

int  foo() { return x; } // x의 값(0)을 반환.
int& goo() { return x; } // x의 값이 아닌 별명을 반환해 달라.

int main()
{
	int v1 = 10, v2 = 20;

	v1 = 20; // v1의 메모리 정보(주소)를 꺼내는 기계어 코드
	v2 = v1; // v1의 값을 꺼내는 기계어 코드

//	foo() = 20; // error. 0 = 20 의 의미.
	goo() = 20; // ok..   x = 20 의 의미

	// 핵심 : 함수가 참조를 반환하면 함수 호출을 등호의 왼쪽에 놓을수 있다
	//	     함수호출이 lvalue가 될수 있다는 것.
	std::string s = "abcd";
	s[0] = 'A'; // s.operator[](0) = 'A'
				// 즉, 위 "operator[]()" 함수의 반환 타입이 참조 입니다.
}