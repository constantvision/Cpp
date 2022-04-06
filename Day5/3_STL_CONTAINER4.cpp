#include <iostream>

#include <vector>
#include <list>
#include <deque> 

#include <set>	
#include <unordered_set> 

#include <map>			
#include <unordered_map>

#include <string>

int main()
{
	// set 한개의 값(키)를 여러개 보관
	std::set<std::string> s = { "mon", "tue", "wed" };

	// map : key-value의 쌍을 보관
	std::map<std::string, std::string> m = { {"mon", "월요일"},
											 {"tue", "화요일"} };

	// 1. []로 접근
	m["mon"] = "월요일";

	// 2. 반복자로 접근

	// 3. 요소가 있는지 확인 =? 멤버함수가 없었습니다.
	//    C++20에서 추가되었습니다.
	if (m.contains("mon")) // set에도 있습니다.
	{
	}

	set::set<int> s = { 1,2,1,2 }; // 중복안됨
	std::multiplies<int> ms = { 1,2,1,2 }; // 중복 허용

	std::map<std::string, std::string> m2 = { {"mon", "월요일"},
											 {"tue", "화요일"} };

	// 주의!! [] 연산자는 키값이 없는 경우
	// 새롭게 키값을 만들고 value를 디폴트 생성자로 초기화 됩니다.
	auto v = m2["wed"]; // 이 순간 "wed" 를 키값으로 value까지 생성
						// value 타입의 디폴트 생성자.

	// 그래서, 값이 있는지 검색하려면 절대로 []로 하면 안됩니다.
	auto p = m2.find("wed"); // 로 해야 합니다.

	if (p != m2.end())  // 이렇게 조사해야 합니다.
	{
	}

	// 그런데, contains()가 있으면 편하지 않을까요?
//	if (m2.contains("wed")) {}
}

// map : tree 기반        => 정렬되어 있음. 검색 빠름 (왼쪽에서 부터 되어있으니 정렬됨)
// unordered_map : hash   => 정렬안되어 있음. 검색 더 빠름.