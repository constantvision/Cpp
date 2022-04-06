#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

// C 언어가 프로그램을 바로보는 관점
// => 프로그램이란 main 함수부터 차례대로 실행되는 실행흐름이다.

// => 실행흐름을 변경하려면 제어문을 사용하면 된다

// => 프로그램을 기능별로 분리하려면 함수를 만들면 된다.

// 객체지향 언어가 프로그램을 바라보는 관점

// => 프로그램은 "객체를 생성" 하고 "객체간 관계를 설정" 하고
//    객체간 메세지를 주고 받는(멤버함수를 호출한다는 의미)






// 모든 메뉴의 기반 클래스
class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}
	virtual ~BaseMenu() {}
	std::string get_title() const { return title; }

	// 모든 파생 클래스의 공통의 특징은 반드시 기반 클래스에 있어야한다.
	// 모든 메뉴는 선택될수 있다.
	virtual void command() = 0;
};




class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		std::cout << get_title() << "메뉴 선택됨" << std::endl;
		_getch();
	}
};
class PopupMenu : public BaseMenu
{
	std::string title;
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}

	void add_menu(BaseMenu* m) { v.push_back(m); }

	void command()
	{
		while (1)
		{
			system("cls");
			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료" << std::endl;
			std::cout << "메뉴를 선택하세요 >> ";
			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();
		}
	}
};

int main()
{
	// 이제 프로그램에서 메뉴가 필요하면 아래처럼 사용하세요
	PopupMenu* root = new PopupMenu("root");
	PopupMenu* p1 = new PopupMenu("해상도 변경");
	PopupMenu* p2 = new PopupMenu("색상 변경");

	root->add_menu(p1);
	root->add_menu(p2);
//	p1->add_menu(p2);  // 색상변경을 해상도 변경 안으로 넣을 경우.

	p1->add_menu(new MenuItem("HD", 11));
	p1->add_menu(new MenuItem("FHD", 12));
	p1->add_menu(new MenuItem("UHD", 13));

	p2->add_menu(new MenuItem("RED", 21));
	p2->add_menu(new MenuItem("GREEN", 22));
	p2->add_menu(new MenuItem("BLUE", 23));

	// 이제 모든 메뉴는 결국 root 메뉴에 붙어 있습니다.
	// root를 선택하면 시작됩니다.
	root->command();
}
// 메뉴 하나하나를 객체로 본다