// 1_namespace4.cpp - 10 page
//#include <stdio.h> // printf 가 전역공간에만 있습니다.
#include <cstdio>    // printf 가 전역에도 있고 std 안에도 있습니다.

// 1. C++ 은 기존의 "C헤더"를 모두 완벽히 지원 합니다
// 2. 또한, 기본의 C헤더의 C++버전도 새롭게 제공합니다.

//	C 헤더			C++ 헤더
// <xxx.h>		=>  <cxxx>
// <stdio.h>	=>  <cstdio>
// <string.h>	=>  <cstring>
// <stdlib.h>	=>  <cstdlib>

int main()
{
	// printf 는 C 표준 함수이기도 하고
	// C++ 표준 이기도 합니다. - C++은 C언어의 모든 내용을 포함

	printf("hello\n");     // ok

	std::printf("hello\n");// ??
}