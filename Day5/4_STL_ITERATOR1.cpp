// 7_STL_ITERATOR1
#include <iostream>
#include <list>
#include <vector>

int main()
{
	int x[5] = { 1,2,3,4,5 };

	// 배열은 연속된 메모리 이므로 1번째 요소의 주소만 알면 모든 요소를 순회할 수 있다.
	int* p1 = x;
	++p1; // 다음 요소로 이동

	std::list<int> s = { 1,2,3,4,5 };

	// STL의 모든 컨테이너에는 포인터를 흉내낸 반복자(iterator)라는 
	// 도구가 있습니다.
	// iterator를 사용하면 포인터처럼 ++을 사용해서 모든요소를 열거할 수 있습니다.

	auto p = s.begin(); // list의 처음을 가리키는 반복자

	// p를 포인터처럼 생각하고 사용하면 됩니다.
	++p; // p.operator++() 함수 호출

	std::cout << *p << std::endl;
}