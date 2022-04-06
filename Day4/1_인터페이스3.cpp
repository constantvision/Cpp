#include <iostream>

// 인터페이스 : 지켜야 하는 규칙을 담은 코드
//              C#, java 등 : "interface" 라는 키워드 있음 ( 별도의 키워드 화)
//              C++         : "interface"라는 키워드 없고, 추상클래스 사용

// 관례적으로
// 인터페이스 : 지켜야 하는 규칙(순수가상함수)만 있는 경우
// 추상클래스 : 지켜야 하는 규칙(순수가상함수) + 다른 멤버들
//              어제 배운 "도형편집기예제의 Shape (draw() = 0과 int color)"
//-----------------------------------

// 약한 결합(loosely coupling)
// 하나의 클래스가 다른 클래스 사용시 "클래스이름"이 아닌 "규칙을 담은 인터페이스"를 통해서 사용하는것

// ** 교체 가능한 유연한 디자인의 핵심


// 규칙 : "모든 카메라는 아래 클래스로부터 파생되어야 한다." ( 파생은 무언가를 물려주는 느낌이 강함) 
//			 => 모든 카메라는 take 함수를 만들어야한다는 의미
// (언어 선택이 좋지 않아)
//        "모든 카메라는 ICamera 인터페이스를 구현해야 한다."   - 일반적인 객체지향
//                       ICamera 프로토콜을 준수해야 한다."     - Swift


// C++에서 인터페이스 만들때 "class" 보다 "struct" 를 선호하는 경향이있습니다.
/*
class ICamera
{
public:
	virtual void take() = 0;
};
*/

#define interface struct  // 이렇게 하는 경우도 있습니다.

//struct ICamera
interface ICamera
{
	virtual void take() = 0;

	virtual ~ICamera() {}  // 인터페이스(추상클래스)도 결국 기반 클래스이므로
						   // 반드시 소멸자를 가상으로 만드세요.
							// 가상이라는 것을 알려주기 위한 것임
};

// ICamera* p = new Camera;
// delete p;

class People
{
public:
	void useCamera(ICamera* p) { p->take(); }  // 가상 함수도 포인터 타입으로는 사용 가능함 

};


class Camera : public ICamera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera : public ICamera // 새로운 카메라 등장
{
public:
	void take() { std::cout << "take HD picture" << std::endl; }
};

class UHDCamera : public ICamera  // ,public Phone 등으로 다중 상속도 가능함
{
public:
	void take() { std::cout << "take UHD picture" << std::endl; }
};

int main()
{
	People p;
	Camera cam;
	p.useCamera(&cam);

	HDCamera hcam;
	p.useCamera(&hcam);

	UHDCamera uhcam;
	p.useCamera(&uhcam);// 
}