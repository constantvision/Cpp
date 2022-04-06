// 6_cout - 187(136)page
#include <cstdio>

namespace std
{
	class ostream
	{
	public:
		ostream& operator<<(int n) { printf("%d", n); return *this; }
		ostream& operator<<(double d) { printf("%1f", d); return *this; }
		ostream& operator<<(const char* s) { printf("%s", s); return *this; }
	};
	ostream cout;

	// endl은 놀랍게도!! 함수 입니다
	ostream& endl(ostream& os)
	{
		os << "\n";
		return os;
	}

}


int main()
{
	// endl을 만들어 봅시다. - endl은 함수 입니다
	//std::cout << std::endl;  

	std::endl(std::cout); // 이 코드가 위와 동일한 기능


}



