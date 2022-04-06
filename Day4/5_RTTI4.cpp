#include <iostream>

class Animal
{
	int age;
public:
	virtual ~Animal() {}  // �� �κ� ������ �Ʒ� dynamic_cast ��� ����
};
class Dog : public Animal
{
public:
	int color;
};

void foo(Animal* p)
{
	// ��� 1. ������ ĳ����
	if (typeid(*p) == typeid(Dog))
	{
		Dog* pDog = static_cast<Dog*>(p);
		pDog->color = 10;
	}

	// ��� 2. ������ Dog�� ĳ���� �� ���
	// static_cast : ������ �ð� ĳ����, ��Ӱ��� Ÿ���� �׻� ����
	//               �׷���, p�� ����Ű�� ���� ���� Dog�� �ִ��� ����� ����
	//Dog* pDog = static_cast<Dog*>(p);  // static : ������ �ð��� ĳ����. �� ��¥ Dog�� ����Ű���� Animal�� ����Ű���� ���� ���ϰ� �ּҸ� ����

	// dynamic_cast : ����ð� ĳ����. p�� ����Ű�� ���� ���� Dog�� ��츸 �ּ� ��ȯ
	//                Dog�� �ƴϸ� nullptr ��ȯ..

	Dog* pDog = dynamic_cast<Dog*>(p);  // �׻� static_cast ���ٴ� ����. �ݵ�� �ʿ��� ���� ����. + OCP ���� ����. Clone draw ������ ����

	std::cout << pDog << std::endl;
}
int main()
{
	Animal a;
	Dog d;

	foo(&a);
	foo(&d);
}



