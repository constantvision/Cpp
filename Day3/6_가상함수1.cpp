// 7_가상함수1  144 page ~
#include <iostream>

class Animal
{
public:
	void Cry1() { std::cout << "Animal Cry1" << std::endl; } // 1
};

class Dog : public Animal
{
public:
	// 함수 오버라이드(override) : 기반 클래스 멤버함수를 파생클래스가 다시 만드는 것 != overloading
	// overloading은 인자가 다른 것임
	void Cry1() { std::cout << "Dog Cry" << std::endl; }  // 2
};

int main()
{
	Animal a; a.Cry1(); // 1 호출
	Dog    d; d.Cry1(); // 2 호출

	Animal* p = &d;		// 객체는 dog인데, 포인터는 Animal인 상황

	if (사용자입력 == 1) p = &a;  // 입력에 따라 p가 가리키는 객체가 변경됨
	
	// 사용자 입력 : 실행시간

	// 컴파일러는 아래 코드에서 p가 어느 객체를 가리키는지 알 수 있을까?

	p->Cry1();  // 논리적으로는 2번을 호출하는게 맞음
	            // 그런데,
				// C++, C# : 1번 호출
				// java, swift, python, Objective-C : 2번 호출
}


// p->Cry1() 했을 때,, 어떤 함수와 연결할 것인가? "함수 바인딩(Binding)" 이라고 함

// 1. static binding  : 컴파일러가 컴파일 시간에 어떤 함수를 호출할지를 결정
//                      static은 보통 컴파일 시간을 나타냄
//						컴파일 시간에는 p가 가리키는 곳에 어떤 객체가 있는지 알 수 없다
//						p와 포인터 타입만 알 수 있다.
//						포인터 타입(Animal*)에 따라 함수 결정
//						Animal Cry1
// 빠르다. 논리적이지 않다
// C++은 속도가 생명. C++, C#의 기본 정책

//                      dynamic은 실행 시간을 나타냄
// 2. dynamic binding : 컴파일 시간에 p가 가리키는 곳을 조사하는 기계어 코드 생성
//                      실행할 때 조사하는 기계어 코드를 실행해 보고
//                      객체에 따라 함수 호출
// 객체가 Dog 라면 Dog Cry1() 호출
// 느리다
// java, Objective-C, swift, kotlin, ..
// C++, C#의 가상함수(virtual)