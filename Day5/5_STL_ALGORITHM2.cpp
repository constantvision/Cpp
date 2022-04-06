#include <iostream>
#include <vector>
#include <list>



#include <algorithm> // find 같은 알고리즘..

// 조건자(predicator) : 반환타입이 bool인 함수
bool fn(int n) { return n % 3 == 0; }

int main()
{
	std::list<int>   s = { 1,6,2,3,4,5 };

	// 주어진 구간에서 3을 찾고 싶다!
	auto ret1 = std::find(s.begin(), s.end(), 3);

	// 주어진 구간에서 첫번째 나오는 "3의 배수" 를 찾고 싶다..??
	// std::find( first, last, 값)
	// std::find_if(first, last, 조건(함수))

	//auto ret2 = std::find_if(s.begin(), s.end(), 함수);
	auto ret2 = std::find_if(s.begin(), s.end(), fn);

	std::cout << *ret2 << std::endl; // 6
}