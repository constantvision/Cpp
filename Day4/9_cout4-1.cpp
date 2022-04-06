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


int main()
{
	std::cout << std::endl;  // cout.operator<<(endl)
							 // cout.operator<<(함수포인터)
							 // cout.operator<<( ostream&(*f)(ostream&) ) . c언어의 함수 포인터 공부

	std::endl(std::cout); 

}



