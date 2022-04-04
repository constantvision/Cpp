#include <iostream>

class Car
{
public:
	// 다음중 에러는 ?
	void foo()
	{
		std::cout << this << std::endl; // 1
	}
	static void goo() 
	{
		std::cout << this << std::endl; // 2
	}
};

int main()
{
}
