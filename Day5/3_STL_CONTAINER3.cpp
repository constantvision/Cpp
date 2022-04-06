#include <iostream>

// 선형 컨테이너 3개
#include <vector>
#include <list>
#include <deque> 

// 연관 컨테이너

// set : 집합 관련 연산(합집합, 차집합, 교집합 등)
//       C++ 에서는 "tree"로 구현되어 있음. - 균현잡힌 2진트리(주로 RBTree 사용)

#include <set>	 // 집합. STL에서는 Tree로 되어있음
                 // Tree로 구현한 set
				 // C++98때 나옴

#include <unordered_set>  // hash로 구현한 set. 
						  // hash라는 이름을 안쓴 것은 더 좋은 자료구조가 나오면 그 자료구조를 쓰기 위해 자료구조 명을 들어내지 않음
						  // C++11 부터 

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	std::set<int> s = { 50, 30, 80, 40, 70, 20, 90, 10 };


	std::unordered_set<int> us = { 50, 30, 80, 40, 70, 20, 90, 10 };
}

