// 2_객체복사4

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// 문자열이 필요하면 "std::string" 을 사용하면된다.
// char* 를 사용하지말고 STL 을 사용하자.!!

// int* p = new int[10]; 대신 vector<int> v(10)

// 직접 자원을 관리하지 말고, 자원을 자동으로 관리하는 타입들을 사용하자!

class People
{
	//	char* name;
	std::string name;
	int   age;
public:
	People(const std::string& s, int a) : name(s), age(a)
	{
	}
};

int main()
{
	People p1("kim", 20);
	People p2 = p1;
}


