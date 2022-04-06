#include <iostream>
#include <vector>

// 6. 디자인 패턴
//    객체지향 세계에서 사용되는 전형적인 코딩 스타일에
//    "이름"을 부여 한 것 - 23개의 패턴이 유명한 패턴

// 구글에서 "GoF Desing Pattern" 검색
// "Gangs of Four" : 저자들을 4명의 강도로 비유한 말..

// 7. prototype 패턴 : 견본을 만들고, 견본을 복사해서 객체를 생성하는 기술
//                     Clone() 가상함수를 만드는 코딩에 붙여진 이름


class Shape
{
	int color;
public:
	void setColor(int c) { color = c; }
	int getColor() const { return color; }

	virtual void draw() { std::cout << "draw shape" << std::endl; }

	// 자신의 복사본을 만드는 가상함수는 항상 유용하게 사용됩니다.
	virtual Shape* Clone()
	{
		Shape* p = new Shape;
		p->color = color; // 나와 동일하게 만들기 위해
						  // 모든 멤버를 복사해 줍니다.
		return p;
	}
};

class Rect : public Shape
{
public:
	virtual void draw() { std::cout << "draw rect" << std::endl; }

	virtual Shape* Clone()
	{
		Rect* p = new Rect;
		p->setColor(getColor());
		// 그외에 x,y,w,h도 복사해 줍니다.
		return p;
	}
};
// Rect* r = new Rect();
// Shape* p = r->Clone();

class Circle : public Shape
{
public:
	virtual void darw() { std::cout << "draw circle" << std::endl; }

	virtual Shape* Clone()
	{
		Circle* p = new Circle;
		p->setColor(getColor());
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 도전 과제 1. 객체의 생성과정을 OCP를 만족하게 할 수 없을까?
		// ===> "Abstract Factory" 패턴을 적용하면 됩니다.

		// 2. Undo/Redo를 넣으려면 어떻게 코드를 작성해야 할까?
		// ===> "Command" 패턴을 공부해 보세요 ..

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}

		else if (cmd == 2)
			v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}

		else if (cmd == 0)
		{
			std::cout << "몇번쨰 도형을 복제 할까요 >>";

			int k;
			std::cin >> k;

			v.push_back(v[k]->Clone()); // 다형성..
										// 어떤 도형인지 알 필요 없습니다.
										// OCP를 만족하는 확장성이 뛰어난 유연한 디자인입니다.

		}
	}
}