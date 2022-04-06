#include <iostream>
#include <vector>
#include <list>

// 알고리즘
// 일반적인 용어 : 문제를 해결하는 방법
// STL           : find 같은 일반함수 템플릿

#include <algorithm> // find 같은 알고리즘..

int main()
{
	std::list<int>   s = { 1,2,3,4,5 };
	std::vector<int> v = { 1,2,3,4,5 };

	// 컨테이너에서 3을 찾고 싶다.
	// 방법 1. 객체지향 디자인.
	// s.find(3);  // 사용하기 쉽습니다.
	// v.find(3);  // 그런데, 모든 컨테이너에 find를 만들어야 합니다.

	// STL의 대부분의 주요 함수는 멤버 함수가 아닌 일반 함수로 되어 있습니다.
	auto ret1 = std::find(s.begin(), s.end(), 3);
	auto ret2 = std::find(v.begin(), v.end(), 3);

	// 반환 값은 "3"을 가리키는 반복자(포인터처럼 생각) 입니다.
	// 검색 실패는 last(s.end())가 나옵니다.

	if (ret1 == s.end())
	{
		std::cout << "검색 실패" << std::endl;
	}
	else
	{
		std::cout << "검색 성공 : " << *ret1 << std::endl;
	}

}