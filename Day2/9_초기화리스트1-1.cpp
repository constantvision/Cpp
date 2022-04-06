// 9_초기화리스트1-1
#include <string>

// string 클래스의 실제 이름은 "basic_string"

class Person1
{
	std::string name;
	int age;
public:
	Person1(const std::string& s, int a)
	{
		name = s;
		age = a;
	}
};

class Person2
{
	std::string name;
	int age;
public:
	Person2(const std::string& s, int a) : name(s), age(a)
	{
		// 제어문들이 필요한 경우만 여기서 코드를 작성하세요.
		// 단순한 멤버 초기화는 위처럼 초기화 리스트 사용하세요.
	}
};

int main()
{
	Person1 p1("kim", 10);
	Person2 p2("kim", 10);

}