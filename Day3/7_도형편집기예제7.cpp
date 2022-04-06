#include <iostream>
#include <vector>


class Shape
{
	int color;
public:
	virtual ~Shape() {}  // 기반 클래스 소멸자는 항상 가상함수로!!

	void setColor(int c) { color = c; }
	int getColor() const { return color; }

	// 가상 함수      : 파생클래스가 재정의 안하면 구현 물려 줄께
	// 순수 가상 함수 : 파생클래스가 꼭 만들어야 한다.

	virtual void draw() = 0; // { std::cout << "draw shape" << std::endl; }

	virtual Shape* Clone() = 0;
};

class Rect : public Shape
{
public:
	virtual void draw() override
	{
		std::cout << "draw rect" << std::endl;
	}

	// 가상함수 재정의시 반환 타입을 변경할 수 있나요?
	// => 됩니다. 단, 상속관계의 타입으로만
//	virtual Shape* Clone() override // A
	virtual Rect* Clone() override  // B
	{
		Rect* p = new Rect;
		p->setColor(getColor());
		return p;
	}
};
// 위 Clone()이 Shape*를 반환했다면
// Rect* p1 = new Rect()     // Shape* 반환시     Rect* 반환시
// Shape* p2 = p1->Clone();  // ok                    ok
// Rect*  p3 = p1->Clone();  // error                 ok
//			   static_cast<Rect*>(p1->Clone())로 가능

// vector<Shape*> 이므로 &rect, &circle은 자동으로!

// Shape* p1 = &rect;   // ok
// Shape* p2 = &circle; // ok

class Circle : public Shape
{
public:
	virtual void draw() override
	{
		std::cout << "draw circle" << std::endl;
	}

	virtual Circle* Clone() override
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

			v.push_back(v[k]->Clone()); 

		}
	}
}