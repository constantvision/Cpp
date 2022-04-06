// ����1     152 page
#include <iostream>
#include <vector>

// *** �ٽ� 3. ��� ����(�Ļ� Ŭ����) �� ������ Ư¡�� Shape(��� Ŭ����)���� �־���Ѵ�. �׷���, Shape*�� �ش� Ư¡�� ����� �� �ִ�.

//     �ٽ� 4. ��� �Լ���, �Ļ� Ŭ������ ������ �ϰ� �Ǵ� ��� �Լ��� �ݵ�� �����Լ��� �ؾ��Ѵ�.

class Shape
{
	int color;
public:
	// �Ʒ� 2���� �Ļ�Ŭ������ �������� ���� ��� virtual�� �Ȱ��� ��
	void setColor(int c) { color = c; }
	int getColor() const { return color; }

	virtual void draw() { std::cout << "draw shape" << std::endl; }  // �ؿ��� ������ �ϰڱ���
};

class Rect : public Shape
{
public:
	virtual void draw() { std::cout << "draw rect" << std::endl; }
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
			v.push_back(new Rect);
		}
		else if (cmd == 2)
			v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v) // Shape* p �ε�
				p->draw();	 // Shape �ȿ��� draw �� ���� ������ ����
		}
	}
}
