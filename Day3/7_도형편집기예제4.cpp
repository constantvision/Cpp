#include <iostream>
#include <vector>

// 5. OCP
//   기능 확장에 열려 있고 (Open, 클래스 등이 나중에 추가되어도)
//   코드 수정에는 닫혀 있어야 (Close, 기존 코드는 수정되지 않게)
//   해야 한다는 원칙(Principle)

// Open Close Principle( 개방 폐쇄의 법칙)

// 객체지향 설계의 5대 원칙 : SOLID(SRP, OCP, LSP, ISP, DIP)

// 다형성은 OCP를 만족하는 좋은 코딩 스타일이다.

class Shape
{
	int color;
public:
	void setColor(int c) { color = c; }
	int getColor() const { return color; }

	virtual void draw() { std::cout << "draw shape" << std::endl; }
};

class Rect : public Shape
{
public:
	virtual void draw() { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	virtual void darw() { std::cout << "draw circle" << std::endl; }
};

class Triangle : public Shape
{
public:
	virtual void draw() { std::cout << "draw triangle" << std:endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
			v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();  // 동일한 표현식이
							// 상황(실제 객체가 무엇인가)에 따라 다르게 동작(다른 함수 호출)
							// => "다형성(Polymorphism)" 이라고 합니다.

			// 객체지향 프로그램의 3가지 특징 : 캡슐화, 상속, 다형성
		}
	}
}