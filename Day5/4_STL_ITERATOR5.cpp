#include <iostream>
#include <list>
#include <vector>

int main()
{
	std::vector<int> c = { 1,2,3,4,5 };

	// 컨테이너의 모든 요소를 열거 하는 방법 
	// 1. [] 연산자 사용 - 단, list는 안됨.
	for (int i = 0; i < c.size(); i++)
	{
		std::cout << c[i] << std::endl;
	}

	// 2. 반복자 사용 - 모든 컨테이너에 사용 가능
	auto p1 = c.begin();

	while (p1 != c.end())
	{
		std::cout << *p1 << std::endl;
		++p1;
	}

	// 3. C++11의 새로운 for 문 사용 - range - for
	for (auto& e : c)
	{
		e = 0;
	}

	std::vector<Rect> v;
	v.push_back(Rect(0, 0, 10, 10));

//	for (auto e : v)  // auto는 Rect 입니다, 복사본 생성의 오버헤드
//	for (auto& e : v) // 복사본 오버헤드 없음. 그런데, e로 수정 가능
	for (const auto& e : v) // 복사본 오버헤드 없음. e로 수정안됨
	{

	}
}