// 7_����Ʈ������ - 201(150)
#include <iostream>

class Car
{
	int speed;
public:
	void Go() { std::cout << "Car Go" << std::endl; }
	~Car()    { std::cout << "~Car"   << std::endl; }
};
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}

	Car* operator->() { return obj; }
};
int main()
{
	// �Ʒ� 2���� �� �����غ�����
	Ptr p = new Car; 

	p->Go(); 
}



