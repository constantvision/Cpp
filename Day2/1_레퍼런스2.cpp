// 1_레퍼런스2
#include <iostream>
// 43 page

void inc1(int n) { ++n; }
void inc2(int* p) { ++(*p); }
void inc3(int& r) { ++r; }

int main()
{
	int a = 1, b = 1, c = 1;

	inc1(a); // call by value, a 증가 실패
	inc2(&b); // call by pointer, b 증가 성공
	inc3(c);  // call by reference, c증가 성공

	std::cout << a << std::endl; // 1
	std::cout << b << std::endl; // 2
	std::cout << c << std::endl; // 2

	int* p = &b;
	int& r = c;
}
// 결국 레퍼런스는 포인터와 유사한 특징이 있습니다.
// 기존 메모리를 가리킬수 있다는..
// call by pointer 와 call by reference 는 매우 유사합니다.

// 그런데, reference 가 좀더 편리하고 안전합니다.

int* p1 = nullptr; // null 포인터 또는
int* p2;           // 초기화 되지 않은 포인터는 존재하지만

int& r1; // error. 초기화되지 않은 참조(레퍼런스)는 존재 할수 없다.

void f1(int* p)
{
	if (p != 0) // 안전성을 위해 유효성 조사!!
	{
		*p = 10;
	}
}

void f2(int& r)
{
	// 위 포인터 처럼 null pointer 조사할 필요 없다.
	r = 10;
}

// call by reference 용어
// C언어   : 포인터를 전달하는 것을 의미
// C++언어 : reference 문법이 따로 존재 하므로
//			call by pointer 와 call by reference 로 구별해서 사용하세요