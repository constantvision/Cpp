// 3_변수와타입4.cpp - 24 page 아래 부분

//typedef int DWORD;
//typedef void(*PF)();

// C++11 부터는 typedef 보다 using 이 편리합니다.
// typedef : 타입에 대한 별칭
// usnig   : 타입에 대한 별칭 + 템플릿에 대한 별칭
using DWORD = int;
using PF = void(*)();

int main()
{
	DWORD n; // int n
	PF f;    // void(*f)()
}