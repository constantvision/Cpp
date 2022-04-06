// 5_예외1 - 231
#include <iostream>

// 객체지향 언어들 : 실패시 "예외"라는 것을 던진다.

// 1. 반환값과 오류의 전달이 분리된다.
// 2. 호출자는 반드시 오류를 처리해야 한다.
//    => 처리하지 않으면 "abort()"가 수행되고 종료된다.
// 오류 처리에 강제성을 부여한것

int connectServer()
{
	if (1)        // 실패라고 가정
		throw 1;  // 예외를 던진다.

	return 0;
}

// * 시험중 다음중 예외를 던질때 쓰는 키워드는? "throw"

int main()
{
	connectServer();

	std::cout << "프로그램 계속 실행" << std::endl;
}