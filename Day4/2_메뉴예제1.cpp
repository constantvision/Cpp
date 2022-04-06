#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

// 객체 지향 : 필요한 타입을 먼저 설계하자.
// "메뉴항목"을 나타내는 타입을 설계

class MenuItem
{
	std::string title;
	int id;

public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string get_title() const { return title;  }

	void command()
	{
		std::cout << get_title() << "메뉴 선택됨" << std::endl;
		_getch();
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);
	m1.command();  // 김밥 선택

}
