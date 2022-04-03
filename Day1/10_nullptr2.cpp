#include <iostream>

void foo(void* p) { std::cout << "void*" << std::endl;}
void foo(int n)   { std::cout << "int" << std::endl; }
void goo(char* p) { std::cout << "goo" << std::endl; }

int main()
{
	foo(0);
	foo(0);
}
