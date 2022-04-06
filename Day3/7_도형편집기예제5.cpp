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
			std::cout << "����� ������ ���� �ұ�� >>";

			int k;
			std::cin >> k;

			// k��° ���� ������ �������� ���� v ���� �߰��մϴ�.
			// �׷���, k ��° ���� ������ �����?
			// ��� �ؾ� �ұ��?
			// v[k]��° Ÿ���� Shape* ������ ���� ����Ű�� ������ �����ؾ� �ڴ�.

			// �Ʒ�ó�� �� �� ������,, �̷��� �ϸ� OCP�� ������ �� ����
			// ���� �������� �˴ϴ�.
			switch (v[k] ��° ������ �����ϴ� ���)
			{
			case �簢��: v.push_back(new Rect); break;
			case ��    : v.push_back(new Circle); break;
			}
		}
	}
}