// 7_스마트포인터 - 201(150)
#include <iostream>

class Car
{
	int speed;
public:
	void Go() { std::cout << "Car Go" << std::endl; }
	~Car()    { std::cout << "~Car"   << std::endl; }
};

// 스마트 포인터(smart pointer) 개념
// 개념 : 임의 타입의 "객체" 가 "다른 타입의 포인" 역할을 하는 것
// 원리 : ->, * 연산자를 재정의해서 포인터처럼 보이게 하는 것
// 장점 : raw pointer가 아니라 객체 라는 점.
//        생성/복사/대입/소멸의 모든 과정에서 추가 작업을 수행할 수 있다.
//        대표적인 예, 소멸자에서 "delete" 기능을 넣으면 자동 삭제 기능을 가지는
//        스마트 포인터를 만들 수 있다.


class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}

	~Ptr() { delete obj; }  // 자동 delete 기능

	Car* operator->() { return obj; }
	Car operator*() { return *obj; }

};
int main()
{
	// 아래 2줄을 잘 생각해보세요
	// "p"는 "Ptr" 타입의 "객체" 입니다.
	// 그런데, "Car" 타입의 "포인터" 처럼 사용됩니다.

	Ptr p = new Car;  // 여기의 p는 포인터가 아님. 객체인데 어떻게 주소로 초기화가 될까? 
					  // Ptr p( new Car)와 동일함
				      // 객체는 이 block을 벗어날 경우 자동으로 소멸될 것임 

	//Car* p = new Car;

	p->Go(); // (p.operator->())Go() 인데
			 // (p.operator->())->Go() 의 모양으로 컴파일러가 해석 (C++ 언어가 해석되도록 문법을 바꿈)

	// p가 진짜로 포인터 처럼 보이게 하려면 아래 코드도 되어야 합니다.
	(*p).Go(); // (p.operator*()).Go()  // *p는 임시 객체 

	//delete p;
}   // <== p가 raw pointer라면 포인터 변수만 파괴
    //     p가 객체(Ptr) 라면 Ptr 소멸자 호출
    //     소멸자에서 자신이 사용하던 자원을 스스로 delete하면
    //     사용자가 delete 할 필요 없다.





