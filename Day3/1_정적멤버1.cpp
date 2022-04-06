// github.com/codenuri/cpp 에서
// "DAY3_사전소스.zip" 받아 두세요
// codexpert.org 에서 출석해 주세요





#include <iostream>

// 생성된 객체의 갯수를 파악하고 싶다.

// 방법 1. 멤버 데이타 사용
// => 모든 멤버 데이타는 "객체당 한개"이다.
// => 객체의 갯수 파악 실패


class Car
{
	int color;
public:
	int cnt = 0;

	Car() { ++cnt; }
	~Car() { --cnt; }
};
int main()
{
	Car c1;
	Car c2;

	std::cout << c1.cnt << std::endl;
}