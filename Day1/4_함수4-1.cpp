#include <iostream>

template<typename T>
T square(T a)
{
	return a * a;
}

int main()
{
	//	printf("%p\n", &square); // 될까요 ?
								// error. 틀(템플릿)은 컴파일시 컴파일러가 사용합니다.
								// 메모리에 존재하는 것이 아닙니다.

	printf("%p\n", &square<int>);// 이렇게 하면 컴파일러가 square(int)버전
									// 생성합니다.
}