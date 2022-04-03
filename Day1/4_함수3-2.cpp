#include <iostream>

// 매크로 함수 vs 인라인 함수
#define SQUARE(n) ((n)*(n))

inline int square(int n)
{
	return n * n;
}

int main()
{
	int n = 3;

	int ret1 = SQUARE(n); // ((n)*(n)) 으로 소스 코드 레벨 치환
	int ret2 = square(n); // 기계어 코드로 치환

	// 결국 위 2줄의 기계어 코드는 거의 동일합니다.
	// 그런데, 매크로 함수는 안정성이 떨어집니다.
	// n = 3
	int ret3 = SQUARE(++n); // ((++n)*(++n))
	n = 3;
	int ret4 = square(++n);

	std::cout << ret3 << std::endl; // ?
	std::cout << ret4 << std::endl; //  예상대로 16 입니다.
}