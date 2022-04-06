#include <iostream>
#include <list>
#include <vector>

int main()
{
	//std::list<int> s = { 1,2,3,4,5 };
	std::vector<int> s = { 1,2,3,4,5 };

	// 1. 정확한 타입
	//std::list<int>::iterator p1 = s.begin();
	auto p1 = s1.begin();

	// 정확한 타입을 사용하지 마세요
	// (1) 복잡해 보인다.
	// (2) 컨테이너 변경시 코드 수정 필요.  코드 다 바꿔야함

	// 2. past the end
	auto p2 = s.begin(); // 처음 요소
	auto p3 = s.end();   // 마지막 요소가 아닌 마지막 다음 요소

	*p2 = 10; // ok
	*p3 = 10; // runtime error. 절대 .end()로 얻은 반복자는
			  // *하면 안됩니다

	// ==, !=로 비교만 해야 합니다.
	while (p2 != s.end())
	{
		std::cout << *p2 << std::endl;
		++p2;
	}

	// 3. 멤버 begin vs non member begin
	//std::list<int> c = { 1,2,3 };
	//std::vector<int> c = { 1,2,3 };
	int c[5] = { 1,2,3,4,5 };

	auto p5 = c.begin();     // error. raw array는 begin 없음
	auto p5 = std::begin(c); // ok. c가 STL 컨테이너라도 되고
	                         //     raw array라도 ok

	// QA : ++ 연산자
	++p; // p.operator++() 호출
	p++; // p.operator++(int) 호출. 전위형과 구별하기위해
	     //                         사용되지 않지만 int가 있어야 한다. 
		//                          (쓰는게 아니라 모양만 만드는 것임. 아무것도 전달 안되며 전위형과 구별목적)
}

namespace std
{
	template<typename T>
	class list
	{
	public:
		class iterator
		{

		};
	};
}