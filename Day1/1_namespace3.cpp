// 1_namespace3.cpp - 9 page
#include <algorithm> // 이 안에 C++ 표준 min 함수가 있습니다.
using namespace std;

// 모든 C++ 표준은 "std" 라는 이름공간 안에 있습니다

int count = 0;

int main()
{
	int ret = min(2, 4);
	//	int ret = std::min(2, 4);

	int n = count; // 왜 이코드가 에러 나올까요 ?? 
				   // 에러메세지 확인해 보세요.
				   // C++ 표준에 "std::count()" 라는 함수가 있습니다.
				   // using namespace std 때문에, 전역변수 count와 
				   // 이름 충돌 발생
}