#include <iostream>

class Car
{
	int color;
	static int cnt;
public:
	Car() { ++cnt; }
	~Car() { --cnt; }

//	int get_count() { return cnt; }  // ��ü�� �־�߸� ȣ�Ⱑ���� �Լ�
	static_int get_count() { return cnt; } // ��ü�� ��� ȣ�Ⱑ���� �Լ�
};
int Car::cnt = 0; // private�� �־.. �ܺ� �ʱ�ȭ�� �����մϴ�

int main()
{
	// Car ��ü�� ���� ���� .. ������ �ľ��� �� �־�� �Ѵ�.
	// Static ��� �Լ��� ��ü�� ��� "Ŭ�����̸�::static�Լ��̸�"���� ȣ�� ����
	std::cout << Car::get_count() << std::endl;

	Car c1;
	Car c2;

//	std::cout << c1.get_count() << std::endl; // ����������, ������ ����
	std::cout << Car::get_count() << std::endl;

}

// ����
// 1. static ��� ������ : ��ü�� ��� �޸𸮿� ����, ��ü ũ�⿡ ���� �ȵ�
//  => ���� �����ڸ� ����� �� �ִ� ��������
//  => Ư�� Ŭ������ ��밡���� �������� ..

// 2. static ��� �Լ� : ��ü�� ��� ȣ�� ������ �Լ�
//  => ��ü�� ��� ȣ�Ⱑ���ϹǷ�, �ᱹ�� �Ϲ� �Լ��� ���� ����
//  => Ư�� Ŭ������ private static ����� ���� ������ �Ϲ��Լ� !