#include <iostream>
#include <vector>


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
				p->draw();
		}

		else if (cmd == 0)
		{
			std::cout << "몇번쨰 도형을 복제 할까요 >>";

			int k;
			std::cin >> k;

			// k번째 만든 도형의 복제본을 만들어서 v 끝에 추가합니다.
			// 그런데, k 번째 만든 도형이 뭘까요?
			// 어떻게 해야 할까요?
			// v[k]번째 타입은 Shape* 이지만 실제 가리키는 도형을 조사해야 겠다.

			// 아래처럼 할 수 있지만,, 이렇게 하면 OCP를 만족할 수 없는
			// 나쁜 디자인이 됩니다.
			switch (v[k] 번째 도형을 조사하는 기술)
			{
			case 사각형: v.push_back(new Rect); break;
			case 원    : v.push_back(new Circle); break;
			}
		}
	}
}