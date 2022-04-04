// github.com/codenuri/cpp 에서 "DAY2_사전소스.zip" 받아두세요

// codexpert.org 에서 출석해 주세요

// 컴파일 에러 나오면
// 프로젝트 메뉴 => 속성 메뉴 에서

// 1_레퍼런스.cpp    41 page

#include <iostream>

int main()
{
	int n1 = 10; // 변수의 선언 = 메모리의 할당.
	int n2 = n1;
	int* p1 = &n1; // 

	int& r1 = n1; // 기존에 존재하던 변수에
				  // alias 를 부여 하는 문법

	r1 = 30;

	std::cout << n1 << std::endl; // 30

	std::cout << &r1 << std::endl; // 1000 번지 라면
	std::cout << &n1 << std::endl; // 1000 즉, 위와 동일

	// 주의 사항
	// 1. & 연산자에 대해서
	//int* p1 = &n1;	// 주소를 구하는 연산자
					// => 이미 선언된 변수앞에 붙는 경우

	//int& r1 = n1;	// reference 변수를 만드는 연산자.
					// => 변수를 선언할때 사용되는 경우

	// 2. 
	//int& r2; // error. 레퍼런스 변수는 반드시 초기화 되어야 합니다
}
