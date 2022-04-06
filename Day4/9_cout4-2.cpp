// 6_cout - 187(136)page
#include <cstdio>
/*
namespace std
{
	class ostream
	{
	public:
		ostream& operator<<(int n) { printf("%d", n); return *this; }
		ostream& operator<<(double d) { printf("%1f", d); return *this; }
		ostream& operator<<(const char* s) { printf("%s", s); return *this; }

		ostream& operator<<(ostream& (*f)(ostream&)) //아래 32번째 라인의 (endl)을 불러옴 
		{
			f(*this);
			return *this;
		}
	};
	ostream cout;

	ostream& endl(ostream& os)
	{
		os << "\n";
		return os;
	}
}
*/

#include <iostream>

// tab은 함수일 뿐, endl과 동일하다
std::ostream& tab(std::ostream& os)
{
	os << "\t";
	return os;
}

std::ostream& menu(std::ostream& os)
{
	os << "1. 김밥\n";
	os << "2. 라면\n";

	return os;
}

int main()
{
	std::cout << std::endl;  

	// tab과 menu를 만들어 봅시다.

	// std::cout << tab
	
	std::cout << "A" << tab << "B" << std::endl; // 진짜 C++ cout코드에 내가 만든 tab 과 menu를 쓰고 있는 코드

	std::cout << menu;

	//printf("%p\n", &(std::cout << 11)); cout의 주소와 동일
	//printf("%p\n", &(std::cout));

}



