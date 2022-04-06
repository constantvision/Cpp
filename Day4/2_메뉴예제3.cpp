#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

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

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;

public:
	PopupMenu(const std::string& s) : title(s) {}

	void add_menu(MenuItem* m) { v.push_back(m); }
	void command()
	{
		while (1)
		{
			system("cls"); // 화면 지우기..
			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			// 메뉴를 선택 받고
			std::cout << "메뉴를 선택하세요 >> ";
			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;
			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue; // 처음으로 올라가기

			v[cmd - 1]->command();
		}
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);
	MenuItem m3("국수", 13);

	PopupMenu pm("오늘의 메뉴");
	pm.add_menu(&m1);
	pm.add_menu(&m2);
	pm.add_menu(&m3);

	pm.command();  

}
