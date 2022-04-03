#include <iostream>

//void fn(short n)  { std::cout << "short" << std::endl; }    // 0
//void fn(int n)    { std::cout << "int" << std::endl; }    // 1
//void fn(double n) { std::cout << "double" << std::endl; } // 2
//void fn(float n)  { std::cout << "float" << std::endl; }  // 3
void fn(...) { std::cout << "..." << std::endl; }    // 4

int main()
{
	fn(3.4f); // 3번 사용 - exactly matching
				// 2번 사용 - promotion. 데이타 손실이 없는 변환
				// 
				// 1번 사용 - standard conversion 
				//				(표준 타입은 암시적 형변환 될수 있다)
				//				데이타 손실 가능성 있다.
				// 4번 사용 - 가변인자 함수..
	// 동일 이름의 함수가 여러개 있을때..
	// 함수 찾는 방법 - "overloading resolution" 이라고 합니다.
	//				  모든 경우를 고려하면 아주 복잡합니다.

	// 1. 암시적으로 발생하는 캐스팅을 막을수 없나요 ?? 
	//    => 사용자 정의타입(클래스로 만드는)은 가능. primitive 타입은 안됨
	//	  => 왜 int n = 3.4; 를 되게 하는가 ?? 언어 자체를 잘못 설계했다.
	//	     다른 언어는 암시적 변환 안됨.

	// 컴파일에러가 난다는 것은 어느 함수를 호출할지가 컴파일 시간에 결정된다는것
	// 인자요 ? ==>네... 단, 3일차 가상함수는 실행시간에 결정됩니다.
	//		   ==>아주 중요합니다.(static binding, dynamic binding)
}