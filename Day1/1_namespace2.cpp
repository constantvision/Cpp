#include <stdio.h>

// namespace 안에 요소에 접근하는 3가지 방법 - 8 page 

namespace Audio
{
	void init() { printf("init Audio Module\n"); }
}
namespace Video
{
	void init() { printf("init Video Module\n"); }
}

// global namespace : 어떠한 이름 공간에도 포함되어 있지 않은 공간
void init() { printf("init global\n"); }

//using Video::init;

int main()
{
	// 1. 완전한 이름을 사용 - qualified name lookup
	// Video::init();

	// 2. using declaration(선언) 사용
//	using Video::init; // Video 의 init 함수는 Video 이름없이 사용할수 있게 해달라
	init();		// Video::init
	::init();	// :: 는 global 을 의미 합니다.

	// 3. using directive(지시어) 사용
	using namespace Video; // Video 이름 공간의 모든 것을 Video 
						// 이름 없이 접근하겠다.
						// 함수 안 또는 밖에 만들수 있습니다.
						// 그런데,, 되도록이면 사용하지 마세요.
						// 완전한 이름이 좋습니다.
}