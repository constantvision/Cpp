#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

// 팝업 메뉴 설계 => vector 같은게 있으면 되지 않을까?
class MenuItem
{
	std::string title;
	int id;

public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string get_title() const { return title; }

	void command()
	{
		std::cout << get_title() << "메뉴 선택됨" << std::endl;
		_getch();
	}
};

// MenuItem을 여러개 보관하는 PopupMenu 클래스 설계
class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;

public:
	PopupMenu(const std::string& s) : title(s) {}

	void add_menu(MenuItem* m) { v.push_back(m); }

	// 팝업메뉴를 선택했을 때 해야하는 동작 (메뉴도 하나하나 만들어야 한다 => 객체 지향)
	void command()
	{
		// 하위 메뉴를 보여주고
		int sz = v.size();

		for (int i = 0; i < sz; i++)
		{
			std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
		}

		// 메뉴를 선택 받고
		std::cout << "메뉴를 선택하세요 >> ";
		int cmd;
		std::cin >> cmd;

		//선택된 메뉴를 실행(command() 호출)
		v[cmd - 1]->command();
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);
	
	PopupMenu pm("오늘의 메뉴");

	pm.add_menu(&m1);
	pm.add_menu(&m2);

	pm.command();  // 팝업메뉴 선택..
				   // 해야할 일을 잘 생각해보기

}
