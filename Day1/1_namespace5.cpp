// 1_namespace5.cpp
#include <cstdio>

void foo()
{
	printf("foo global\n");
}
namespace Audio
{
	using ::foo; // 이렇게 표기하는 문법이 있습니다.
}
using namespace Audio;

int main()
{
	foo();
	Audio::foo();
}
// <stdio.h> 안에 
int printf(const char* fmt, ...); // 이 선언이  있습니다

// <cstdio> 안에서. 
#include <stdio.h>
namespace std
{
	using ::printf;
}
using namespace std; // 이 코드가 있어도 결국 printf()는 한개 이므로 충돌없습니다.