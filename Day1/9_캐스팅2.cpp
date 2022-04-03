#include <iostream>

// static_cast : 논리적으로 맞고 위험하지 않은 경우만 허용
//          void*=> 다른 타입*,
//			상속관계의 캐스팅 등.
//          반드시 연관성이 있어야 한다


int main()
{
	double d = 3.4;
	int    n = d;


//	int* p1 = malloc(100);     // C언어 : ok. C++ : 에러

//	const int c = 10;
//	int* p3 = (int*)&c; 
}

