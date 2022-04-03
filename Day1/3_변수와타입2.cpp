// 3_변수와타입2.cpp - 22 page
#include <iostream>

// 일관된 초기화(uniform initialization) 기술

struct Point
{
	int x = 0;
	int y = 0;
};

int main()
{
	int n1 = 0;
	int x1[2] = { 1,1 };
	Point pt1 = { 1,1 };

	// 모든 종류의 변수를 하나의 방식(uniform) 으로 초기화 할수 있게하자
	// "중괄호 초기화(brace init)" 이라고도 부릅니다.
	// C++11 에서 도입된 문법
	int n2 = { 0 };
	int x2[2] = { 1,1 };
	Point pt2 = { 1,1 };

	int n3{ 0 };
	int x3[2]{ 1,1 };
	Point pt3{ 1,1 };


	// 직접(direct) 초기화 : = 이 없는 초기화
	// 복사(copy)   초기화 : = 이 있는 초기화
	//		=> 위 2가지 방식에는 약간의 차이가 있습니다. - 2일차 또는 3일차

	//23 page 위쪽 - prevent narrow
	int n4 = 3.4;	// ok.. 단, 데이타 손실.. 좋지 않은 코드
					// C/C++ 언어를 제외한 대부분의 언어는 에러

	int n5 = { 3.4 };	// error
	int n6{ 3.4 };		// error

	char c{ 500 };	// error. 500은 1바이트에 담을수 없습니다.
}

