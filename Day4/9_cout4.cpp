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

	// endl�� ����Ե�!! �Լ� �Դϴ�
	ostream& endl(ostream& os)
	{
		os << "\n";
		return os;
	}

}


int main()
{
	// endl�� ����� ���ô�. - endl�� �Լ� �Դϴ�
	//std::cout << std::endl;  

	std::endl(std::cout); // �� �ڵ尡 ���� ������ ���


}



