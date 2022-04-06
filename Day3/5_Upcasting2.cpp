// 6_Upcasting1.cpp      140 page ~
#include <vector>

class Animal
{
public:	int age;
};
class Dog : public Animal
{
public:	int color;
};
class Cat : public Animal
{
public:	int speed;
};



int main()
{
	// Upcasting 활용/장점
	std::vector<Dog*> v1;  // Dog만 보관하겠다는 의도
	std::vector<Cat*> v2;  // Cat만 보관하겠다는 의도
	std::vector<Animal*> v3;  // 모든 동물을 보관하겠다는 의도
							  // 동종(동일 기반 클래스로부터 파생된 타입)을 보관하는 컨테이너

	
	// ** 둘의 차이점 명쾌하게 알아두기
	Dog dog;
	Animal* p = &dog; // 기존에 생성된 dog를 가리키겠다는 것
	Animal a = dog;   // 에러는 아닌데..  새로운 Animal 객체를 만든다. 이 때 dog에 있는 내용으로 복사한다는 내용 (color 무시하고 age만 가져온다) 
					  // object slicing (객체가 짤려서 복사됨). 새로운 Animal을 만든 것임

	// 아래 2개의 차이점을 많이 어려워 함
	// 그래서 아래 2줄의 차이점 그림으로 파악
	std::vector<Animal> v4;   // 여러개를 보관할껀데, 포인터가 아니고 진짜 Animal임. Animal만 보관 가능
	
	v4.push_back(dog);  // dog를 보관하는게 아니라, 얘를 복사해서 새로 만든 Animal을 보관함

	std::vector<Animal*> v5;  // 여러개 보관할건데 다 pointer로 보관. Animal을 따라가보면 A,B,C,D가 있을 수 있음. (이미 만들어져있는 수없이 많은 동물들을 주소로 보관)
	                          // 이렇게 해야 모든 동물들을 보관할 수 있다

	v5.push_back(&dog);  // dog의 주소를 보관
 

}


// 탐색기 안에 있는 폴더나 파일들을 타입으로 설계 => Folder라는 클래스 설계, File 클래스 설계
// Folder에는 여러개 보관해야하니 Vector 필요 

// 핵심
// A와 B를 묶어서 관리하고 싶다.
// => A,B의 공통의 기반 클래스를 만들기

// 상속은
// 1. "기존 타입을 확장해서 새로운 것을 만들기도 하지만"
// 2. 여러 타입을 묶기위해서도 사용함 <== 이 관점도 아주 널리 사용되므로 꼭 기억하기 **