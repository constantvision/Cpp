#include <iostream>

class Animal
{
	int age;
public:
	virtual ~Animal() {}  // 이 부분 막으면 아래 dynamic_cast 사용 못함
};
class Dog : public Animal
{
public:
	int color;
};

void foo(Animal* p)
{
	// 방법 1. 조사후 캐스팅
	if (typeid(*p) == typeid(Dog))
	{
		Dog* pDog = static_cast<Dog*>(p);
		pDog->color = 10;
	}

	// 방법 2. 무조건 Dog로 캐스팅 후 사용
	// static_cast : 컴파일 시간 캐스팅, 상속관계 타입은 항상 성공
	//               그런데, p가 가리키는 곳에 정말 Dog가 있는지 조사는 못함
	//Dog* pDog = static_cast<Dog*>(p);  // static : 컴파일 시간에 캐스팅. 즉 진짜 Dog를 가리키는지 Animal을 가리키는지 조사 못하고 주소만 나옴

	// dynamic_cast : 실행시간 캐스팅. p가 가리키는 곳이 실제 Dog인 경우만 주소 반환
	//                Dog가 아니면 nullptr 반환..

	Dog* pDog = dynamic_cast<Dog*>(p);  // 항상 static_cast 보다는 느림. 반드시 필요할 때만 쓰라. + OCP 만족 못함. Clone draw 등으로 가자

	std::cout << pDog << std::endl;
}
int main()
{
	Animal a;
	Dog d;

	foo(&a);
	foo(&d);
}



