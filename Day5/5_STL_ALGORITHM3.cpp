#include <iostream>
#include <vector>
#include <list>


#include <algorithm> // find 같은 알고리즘..

// 조건자(predicator) : 반환타입이 bool인 함수
bool fn(int n) { return n % 3 == 0; }

int main()
{
	std::list<int>   s = { 1,6,2,3,4,5 };

//	auto ret2 = std::find_if(s.begin(), s.end(), fn);
    
	// C++11 람다표현식
	// 익명의 함수를 만드는 문법
	// [] : lambda introducer. 람다표현식이 시작됨을 알리는 기호
	auto ret2 = std::find_if(s.begin(), s.end(), 
		                          [](int n) { return n % 3 == 0; });
	// 람다를 쓰면 위의 경우 find_if 안에서 inline 치환됨.. => 속도가 훨씬 빠르다!!

	std::cout << *ret2 << std::endl; // 6
}

// 코드 사이즈, 속도 : C를 이길 방법은 "어셈블리(기계어)" 밖에 없음
//
// C++ : C와 거의 대등하게 만들고 있고 + 모듈화(객체지향) 지원