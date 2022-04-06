#include <iostream>

// 카메라를 먼저 만들지 말고
// 카메라 제작자가 지켜야하는 규칙을 먼저 설계한다.

// 규칙 : "모든 카메라는 아래 클래스로부터 파생되어야 한다."
//			 => 모든 카메라는 take 함수를 만들어야한다는 의미

class ICamera
{
public:
	virtual void take() = 0; 

};

// 규칙이 있으므로 실제 카메라가 없어도 카메라를 사용하는 코드를 먼저 작성해도 됨
// 규칙대로만 사용하면 됨


class People
{
public:
	void useCamera(ICamera* p) { p->take(); }  // 가상 함수도 포인터 타입으로는 사용 가능함 

};

// 이제 모든 카메라는 "규칙"을 지켜야 합니다.
// "ICamera"로 부터 파생되어야 합니다

class Camera : public ICamera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera  : public ICamera // 새로운 카메라 등장
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