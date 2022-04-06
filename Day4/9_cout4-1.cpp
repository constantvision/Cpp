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

		ostream& operator<<(ostream& (*f)(ostream&)) //�Ʒ� 32��° ������ (endl)�� �ҷ��� 
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
							 // cout.operator<<(�Լ�������)
							 // cout.operator<<( ostream&(*f)(ostream&) ) . c����� �Լ� ������ ����

	std::endl(std::cout); 

}



