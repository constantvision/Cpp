// 2_메모리할당 - 52 page
#include <iostream>

int main()
{
	// C 스타일
	int* p = (int*)malloc(sizeof(int) * 20);
	free(p);

	// C++ 스타일
}

