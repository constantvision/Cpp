// 2_표준입출력1.cpp - 12 page
#include <cstdio>	// C 표준 입출력의 C++헤더
#include <iostream> // C++ 표준 입출력

int main()
{
	int n = 10;

	// printf : 함수 입니다.
	// cout   : 객체라는 도구 입니다. - 5일차에 직접 cout을 만들어 보겠습니다.
	printf("%d\n", n);

	std::cout << "n = " << n << std::endl;	// std::endl 는 개행
											// "\n" 도 사용가능
	double d = 3.4;
	std::cout << d << std::endl; // 실수로 출력
	std::cout << (int)d << std::endl; // 


//	scanf("%d", &n); // C언어 표준 입력, 요즘은 scanf_s()
	std::cin >> n;   // "&n" 이 아니라 "n" 입니다.

	n << 10; // n이 int 타입이라는 것은 C++컴파일러가 알고 있습니다.
			 // => 쉬프트 연산자로 해석해 줍니다.

	std::cout << 10; // cout의 정체를 컴파일러가 알고 있습니다.
					// << 연산자로 헷갈리지는 않습니다.
					// cout.operator<<()
}