// github.com/codenuri/cpp  에 올렸습니다
// 1_namespace1.cpp - 7page

#include <stdio.h>
// namespace 
// => 프로그램의 코드를 연관된 요소끼리 묶어서 관리하는 문법
// => 프로그램을 논리적으로 분리 할수 있고
// => 이름 충돌등도 막을수 있다.
namespace Audio
{
	void init()
	{
		printf("init Audio Module\n");
	}
}
namespace Video
{
	void init()
	{
		printf("init Video Module\n");
	}
	// Video 관련, 함수, 전역변수, 구조체등을 모두 이안에서 만듭니다.
}

int main()
{
	//init();
	Audio::init();
	Video::init();
}