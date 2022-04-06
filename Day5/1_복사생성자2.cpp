// 1_���������  92 page  **�߿��� ���� ���蹮�� ����
#include <iostream>

class Point
{
	int x, y;
public:
	Point() : x(0), y(0) {} // 1
	Point(int a, int b) : x(a), y(b) {} // 2

	Point(const Point& pt) : x(pt.x), y(pt.y)
	{
		std::cout << "���������" << std::endl;
	}
};

void f1(Point pt) {}  // Point pt = p1 ( �Լ� ���ڰ� �Ѿ�� ����� �̰��̴�!)
//void f1(Point& pt) {}  // Point& pt = p1   (�Լ� ���ڰ� �ȺҸ��� !! ) *** ����

Point f2()   // return �� �� Ÿ��. pt�� ������ temporary�� ���� ���� �� (�� �� ���� �����ڸ� �������)
{
	Point pt;
	return pt;
}

int main()
{
	// ���� !!
	// ���� �����ڰ� ȣ��Ǵ� 3���� ���

	// 1. ��ü ������ �ڽŰ� ���� Ÿ���� ��ü�� �ʱ�ȭ �ɶ�
	Point p1(1, 2);
	Point p2 = p1;   // Point p2(p1) �� ����.  <== �� ���� ���� ������ ȣ��

	// 2. �Լ� ȣ��� ���ڸ� call by value�� ������
	f1(p1);

	// 3. �Լ��� ��ü�� "�� Ÿ��"���� ��ȯ �� ��
	//    �ӽ� ��ü�� ��ȯ�Ǵµ�, �ӽ� ��ü�� ���� �� ���� ������ ȣ��
	f2();
}
