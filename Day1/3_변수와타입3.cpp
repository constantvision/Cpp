#include <iostream>

// auto, decltype - 23 page


//int main()
//{
//	int x[3] = { 1,2,3 };
//	auto	p1 = x;
//	decltype(x) p2 = x; // error
//
//}


int main()
{
	
	int x[3] = { 1,2,3 };

	//	int n = x[0];

		// auto : 우변의 표현식으로 좌변의 타입을 결정해 달라.
		//		  컴파일 시간에 컴파일러가 결정, 실행시간에 오버헤드는 없습니다.
	auto n = x[0]; // 컴파일 되면 "int n = x[0]"

	// 사실 auto 는 꽤 어렵습니다.
	const int c = 10;

	auto a1 = c; // (1) const int a1 = c; 
				 // (2) int a1 = c;   ==> 이렇게 추론됩니다.
	// 즉, auto 는 우변의 표현식과 완전히 동일한 타입이 아니라.
	// 규칙이 있습니다.

	// auto     : 우변 표현식으로 타입결정
	// decltype : () 안의 표현식으로 타입 결정
	decltype(n) d1; // int d1

	// auto : 우변의 const, volatile, register, reference(?) 를 
	//			  모두 제거하고 타입결정
	// decltype() : 제거하지 않고 타입 결정

	const volatile int cv = 10;
	auto aa = cv;    // int aa = cv;
	decltype(cv) dd; // const volatile int dd; 인데.. 
					 // const 변수 초기화 안했으므로 error
}