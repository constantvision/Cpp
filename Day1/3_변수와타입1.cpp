// 3_변수와타입1.cpp - 18 ~ 19 
#include <iostream>

// 변수 와 타입관련해서 C언어와 다른 내용들 정리

struct Point
{
	int x = 0; // C++11 부터 구조체 멤버 초기화 가능합니다.
	int y = 0;
};

int main()
{
	struct Point p1; // C스타일 
	Point p2;		 // C++ 스타일

	int n1 = 0b10;		// C++11 부터 2진수 지원 합니다. C언어도 C11 부터 가능
	int n2 = 1'000'000;	// C++11 부터 자릿수 표기법 가능합니다.
						// 정확한 의미는 
						// "정수 리터럴 사이의 ' 는 무시해 달라"입니다.

	// 새로운 타입들
	long long n3; // 64bit 정수 타입. C++11 부터 지원
	bool b = true; // 또는 false,    C++98(C++초기) 부터 지원

}