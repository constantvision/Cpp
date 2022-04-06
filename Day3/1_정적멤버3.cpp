// 2번 복사
#include <iostream>


// static 멤버 데이타
// 1. 클래스 외부에 선언되어야 한다.(초기화도 여기서)
// 2. Car 객체를 한개도 생성하지 않아도 메모리에 존재한다.
//    (클래스 외부 선언이 있기 때문에)
// 3. Car 객체 생성시에는 객체의 메모리에 포함되지는 않는다.

// ==> 결국 접근지정자를 사용할수 있는 "전역변수"
//     Car 멤버 함수만 접근 가능한 전역변수!


class Car
{
	int color;
public:

	//	int cnt = 0; // 일반 멤버 데이타 - 객체당 한개

	static int cnt; // static 멤버 데이타 - 모든 객체가 공유
					// 클래스 외부 선언 필요(초기화도 여기서)

	Car() { ++cnt; }
	~Car() { --cnt; }
};
int Car::cnt = 0;

int main()
{
	Car c1;
	Car c2;

	// static 멤버 데이타에 접근 하는 2가지 방법
	// 1. 객체이름.cnt  => 이렇게 하면 cnt 가 static 인지 아닌지
					  // 구별할수 없습니다. 가독성 나쁨  
	// 2. 클래스이름::cnt  ==> 이코드가 좋습니다.

	std::cout << c1.cnt << std::endl;
	std::cout << Car::cnt << std::endl; // 좋은 코드!

	// 다른 객체지향 언어는 "static 멤버"에 접근시
	// 객체이름은 안되고 클래스 이름만 가능합니다.
	// 대부분 "클래스이름.static멤버"
}