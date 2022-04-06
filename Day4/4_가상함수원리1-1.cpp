#include <iostream>

//가상함수 원리   164page ~

// 컴파일러가 Animal의 모든 가상함수의 주소를 담는 배열 생성

// 함수주소크기 타입 (void* 등) 
animal_vtable[] = { RTTI정보, 
					&Animal::Cry, 
					&Animal::Run };

class Animal
{
	void* vtptr = animal_vtable;  // 컴파일러가 추가한 멤버.
	int age;
public:
	virtual void Cry() {}  // 1
	virtual void Run() {}
};


//--------------------
// Dog 가상함수 정보를 담은 배열(가상함수 테이블이라고 함)
dog_vtable[] = { RTTI정보, 
				&Dog::Cry, 
				&Animal::Run };  // 재정의 안한 Run은 Animal것을 쓰겠다

class Dog : public Animal
{
	vtable = dog_vtable; // 컴파일러가 추가한 코드
	int color;
public:
	virtual void Cry() {}  // 2
};

int main()
{
	Animal a1;
	Animal a2;
	Dog    d;
	Animal* p = &d;
	p->Cry();   // 가상함수 이므로 2번 호출
				// p가 가리키는 곳을 조사 후에 호출

				// Cry 가상함수가 Animal에서 몇번째 가상함수인지 순서가 중요함
				// 컴파일러가 컴파일 시, p->vtable[1]() 라는 기계어 코드 생성 
				// (가리키는 주소에 가보면 vtable을 넣어놨다. 거길 따라가면 배열이 있는데, cry가 몇번째에 있다)

				// 가상함수 단점 : 메모리 공간 .. 문제 ( 원래 age만 있으면 되는데 vtable 때문에 메모리 Overhead로 등장)
				// 가상함수를 안쓰면 이런 오버헤드는 없음
				// 가상함수 테이블은 메모리상 데이터 영역에있음

}