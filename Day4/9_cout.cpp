// 6_cout - 187(136)page
#include <iostream>


namespace std
{
	class ostream
	{
		// operator<<()
	};
	ostream cout; // cout은 객체(전역변수)임
}

// cout 의 원리
int main()
{
	int    n = 10;
	double d = 3.4;

	std::cout << n;  // cout.operator<<(int)
	std::cout << d;  // cout.operator<<(double)
	
}

// "<<" 추출 연산자 이기도 하면서 shift 연산자이기도 함 (같은 것임)

