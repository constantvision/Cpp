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
		throw 1;  // 예외를 던진다. 그러면 바로 catch로 감

	return 0;
}

// ** 시험 ** 다음중 예외를 던질때 쓰는 키워드는? "throw"
// ** 시험 ** 다음중 예외를 잡을때 쓰는 키워드는? "catch"

int main()
{
	try
	{
		connectServer();
		// ... 성공시 코드.....
	}
	catch (int n)  // 오버헤드 때문에 성능은 문제가 있음
				   // catch 뒤에는 아래 그대로 수행
	{
		std::cout << "예외발생. catch하면 프로그램 계속 실행 가능" << std::endl;
	}
	
	std::cout << "프로그램 계속 실행" << std::endl;

}

// exception은 goto 같은 것임. goto / set jump / throw 정도만 바로 건너뜀
// throw, catch는 소멸자가 불리지만, goto는 소멸자가 안불려서 문제가 될 수 있음