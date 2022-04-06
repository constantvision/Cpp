// 6_Upcasting1.cpp      140 page ~
#include <vector>

class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog     dog;

	Dog* p1 = &dog; // ok
	int* p2 = &dog; // error
	Animal* p3 = &dog; // ok.. 

	// 핵심 1. 기반 클래스 포인터(참조)로 파생 클래스 객체를 가리킬수 있다.
	//		  모든 객체지향 언어가 지원하는 객체지향 문법의 핵심
	//		 => Upcasting 이라고 합니다.

	// 핵심 2. 기반 클래스 포인터로는 기반 클래스 멤버만 접근 가능하다.
	//		 실제 객체가 Dog 라도 Dog고유멤버(color)는 접근 안됨

	p3->age = 10;  // ok
//	p3->color = 20;// error.

	// 핵심 3. 기반 클래스 포인터가 가리키는 것이 파생클래스(Dog)가 확실하고
	//        Dog 고유의 멤버에 접근하려면
	//	      Dog* 타입으로 다시 캐스팅해야 한다.

	// Downcasting : Animal* => Dog* 로 다시 변경하는것
	//               static_cast 사용가능.
	Dog* pDog = static_cast<Dog*>(p3); // 단, 반드시 p3가 가리키는 곳이
									// Dog 일때만.. 
									// Dog 가 아니라면 ???
									// 나중에 등장!!
	pDog->color = 20;

	// 단, 아래 코드는 사용하지 마세요.
//	Animal a; // 객체는 Animal 인데.
//	Dog* p4 = static_cast<Dog*>(&a); // 포인터는 파생클래스 타입
//	p4->color = 10; // 컴파일 에러 아님..
					// 실행시 잘못된 메모리 접근 발생



