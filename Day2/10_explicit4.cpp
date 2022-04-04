// 10_explicit4.cpp
#include <iostream>

// intializer_list : C++11로 부터 나온 도구, 생성자 인자로 널리 사용됨
//                                           인자를 몇개라도 받을 수 있습니다.

class Vector
{
public:
	explicit Vector(int sz) { std::cout << "Vector(int)" << std::endl; } // 1
	Vector(std::initializer_list<int> e) { std::cout << "Vector(initializer_list)" << std::endl; } // 2
};

int main()
{
	Vector v1(10); //1
	Vector v2{10}; // 2번 호출, 없으면 1번 사용

//	Vector v3(10, 20);   // error
	Vector v4{ 10, 20 }; // ok.. 2번 호출

//  Vector v5 = 10;      // error explicit
	Vector v6 = { 10 };  // ok    explicit 아님 ..
}