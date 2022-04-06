// 6_STL_CONTAINER1 - 214p ~ 
#include <iostream>

// 컨테이너(Container) : 요소를 여러개 보관하는 타입
// C++98 : 3개의 선형자료구조
#include <vector>
#include <list>
#include <deque> // "덱" 또는 "디큐" 라고 합니다.

// C++11 : 2개의 선형자료구조 추가
#include <array>  // stack에 올리는 것이므로 크기변경도 안되고.. 그냥 쓰기 편한 배열이라고 보면 됨
#include <forward_list>  // 싱글 링크드 리스트

int main()
{
	// 연속된 메모리
	// 장점 : 요소 순회가 빠르고, 캐쉬 적중률이 높다.
	// 단점 : 중간에 삽입/삭제가 많아지만 오버헤드가 있다.
	std::vector<int> v = { 1,2,3,4,5 }; 
	std::list<int>   s = { 1,2,3,4,5 };

	std::deque<int>  d = { 1,2,3,4,5 };

	// 컨테이너 : 여러개의 요소를 보관하는 타입(vector, list, deque)
	// 
	// 핵심 1. 사용법(멤버함수)가 거의 동일하다.
	v.push_back(10);
	s.push_back(10);   // 사용법이 거의 유사
	

	// 핵심 2. vector 는 앞에 넣을수 없다.
	s.push_front(10);
	v.push_front(10); // error
					  // 성능이 좋지 않으므로 사용하지 말라는 의도!
	                  // **시험 vector의 앞에 넣으려면 push_front를 써라 (- 잘못된 말임!


	// 핵심 3. [] 연산은 vector와 deque, array가 가능
	//         list는 안됨
	v[0] = 10;
	d[0] = 10;
	s[0] = 10; // error. 

	// 선택기준
	// 전방삽입이 필요 없고, [] 연산이 필요 하다. : vector
	// 전방삽입이 필요 있고, [] 연산이 필요 하다. : deque
	// 중간에 삽입/삭제가 많고, [] 는 필요 없다.  : list

	// 멤버 함수가 동일하므로 컨테이너를 변경하면서 성능 확인 가능.
	//std::vector<int>v1 = { 1,2,3 };
	std::list<int>v1 = { 1,2,3 };
	
	v1.push_back(10);
	v1.front();

}

