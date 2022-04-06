#include <iostream>

// Animal* p�� ����Ű�� ��ü�� ���� ��� ��ü���� ������ �� ��������
// �ݵ�� �����Լ��� �Ѱ� �̻� �־�� ��


class Animal
{
	int age;
public:
	virtual ~Animal() {} // ��� ��� Ŭ������ �Ҹ��ڰ� �����̾����
						 // ����� ���� ������ �����Լ��� �ִ� Ÿ���̶�� ���� ��
};
class Dog : public Animal
{
	int color;
};

void foo(Animal* p)  // Animal �� �ƴ϶� ��� ���� ��ü�� ���� ����
{
	// typeid()�� ����� Ÿ�� ����
	// 1. �����Լ��� ���� Ÿ�� : �����Ϸ��� ������ �ð��� Ÿ�� ���� ����
	//							 Animal* p �� �� *p�� Animal�� ����
	//							 ����ð��� ���� �޸� ���� ����(����)

	// 2. �����Լ��� �ִ� Ÿ�� : ����ð��� �����Լ� ���̺� ��������
	//							 Ÿ�������� ������ Ȯ�� ..!

	std::cout << typeid(p).name() << std::endl;   // Animal*
	std::cout << typeid(*p).name() << std::endl;


}
int main()
{
	Animal a;
	Dog d;

	foo(&a);
	foo(&d);
}



