#include <iostream>

//가상함수 원리   164page ~

class Animal
{
	int age;
public:
	virtual void Cry() {}  // 1
	virtual void Run() {}
};
//--------------------
class Dog : public Animal
{
	int color;
public:
	virtual void Cry() {}  // 2
};

int main()
{
	Animal a;
	Dog    d;
	
	std::cout << sizeof(a) << std::endl;
	std::cout << sizeof(d) << std::endl;


	Animal* p = &d;
	p->Cry();   // 가상함수 이므로 2번 호출
				// p가 가리키는 곳을 조사 후에 호출
}


