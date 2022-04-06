// 6_cout - 187(136)page
#include <cstdio>

// 주의 : 실제 cout은 operator<<() 안에서 자신만의 출력 버퍼를 사용해서 출력합니다.
namespace std
{
	class ostream
	{
	public:
		void operator<<(int n)          { printf("%d", n);  }
		void operator<<(double d)       { printf("%1f", d); }
		void operator<<(const char* s)  { printf("%s", s); }
		
		// 위 3개뿐 아니라 모든 표준 타입에 대해서 operator<<() 함수 
	};
	ostream cout; 
}

// cout 의 원리
int main()
{
	int    n = 10;
	double d = 3.4;

	std::cout << n;  // cout.operator<<(int)
	std::cout << d;  // cout.operator<<(double)

}



