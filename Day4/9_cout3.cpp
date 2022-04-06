// 6_cout - 187(136)page
#include <cstdio>

namespace std
{
	class ostream
	{
	public:
		ostream& operator<<(int n) { printf("%d", n); return *this; }
		//	ostream* operator<<(int n) { printf("%d", n); return *this; }
			//(std::cout << n)->operator<<(", ") °¡´É 
		ostream& operator<<(double d) { printf("%1f", d); return *this; }
		ostream& operator<<(const char* s) { printf("%s", s); return *this; }
	};
	ostream cout;
}

int main()
{
	int    n = 10;
	double d = 3.4;

	std::cout << n << ", " << d << "\n";  // cout.operator<<(int)
	// (cout.operator<<(n).operator<<(", ").operator<<(d)

}



