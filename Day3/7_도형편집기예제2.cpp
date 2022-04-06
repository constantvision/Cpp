#include <iostream>
#include <vector>

class Shape
{

};

class Rect : public Shape
{

public:
	void draw() { std::cout << "draw rect" << std::endl; }

};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }

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
			// Rect r;  // �̷��� �ϸ� {} ��� �� ��� �ı���
			//new Rect;  // �̷��� �ؾ� ��������� ������ �� ���� ��� ��밡�� => ������ �ּҸ� �� ������

			//Rect* p = new Rect;  // p�� ���� ������ ��� ����� �ı��Ǽ� ���̻� �ش� �κ� ������Ŵ
			//v.push_back(p);      // p�� �ı��Ǳ� ���� vector�� �־��
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}

		else if (cmd == 9)
		{
			// ���ݱ��� ���� ��� ������ �׷��ݴϴ�.
			for (auto p : v) // �ᱹ shape�� pointer(Shape*) . shape �ȿ� draw�� ���� error. 
				p->draw();
		}
	}

}

// �� ���ڵ�� �����ϱ�? �ذ�å��?
// 1. Shape �ȿ� draw�� ������
// 2. Shape* Ÿ���� p�� Rect* �Ǵ� Circle*�� ĳ��������