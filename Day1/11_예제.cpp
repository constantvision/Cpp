#include <iostream>

// Swap를 만들어 봅시다.
// 1. C 버전
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int x = 3, y = 2;
	Swap(&x, &y);

	std::cout << x << std::endl;
	std::cout << y << std::endl;
}



