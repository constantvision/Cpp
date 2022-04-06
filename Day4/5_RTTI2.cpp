#include <iostream>

// Animal* p로 가리키는 객체가 실제 어느 객체인지 조사할 수 있으려면
// 반드시 가상함수가 한개 이상 있어야 함


class Animal
{
	int age;
public:
	virtual ~Animal() {} // 모든 기반 클래스는 소멸자가 가상이어야함
						 // 상속을 쓰면 무조건 가상함수가 있는 타입이라고 보면 됨
};
class Dog : public Animal
{
	int color;
};

void foo(Animal* p)  // Animal 뿐 아니라 모든 동물 객체가 전달 가능
{
	// typeid()를 사용한 타입 조사
	// 1. 가상함수가 없는 타입 : 컴파일러가 컴파일 시간에 타일 정보 결정
	//							 Animal* p 일 때 *p는 Animal로 결정
	//							 실행시간에 실제 메모리 조사 안함(못함)

	// 2. 가상함수가 있는 타입 : 실행시간에 가상함수 테이블에 보관중인
	//							 타입정보를 꺼내서 확인 ..!

	std::cout << typeid(p).name() << std::endl;   // Animal*
	std::cout << typeid(*p).name() << std::endl;


}
int main()
{
	Animal a;
	Dog d;

	foo(&a);
	foo(&d);
}



