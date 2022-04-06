// 6_가상함수1-1.cpp
#include <iostream>

class Animal
{
public:
			void Cry1() { std::cout << "Animal Cry1" << std::endl; }
	virtual void Cry2() { std::cout << "Aniaml Cry2" << std::endl; }
};

class Dog : public Animal
{
public:
			void Cry1() { std::cout << "Animal Cry1" << std::endl; }
	virtual void Cry2() { std::cout << "Aniaml Cry2" << std::endl; }
};

int main()
{
	Dog   d;
	Animal* p = &d;

	p->Cry1();
	p->Cry2();

}