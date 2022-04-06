#include <iostream>

// 강한 결합(tightly coupling)
// 하나의 클래스가 다른 클래스 사용시 "클래스 이름"을 직접 사용하는 것

// 교체 불가능한 경직된 디자인

// OCP를 만족하지 못하는 디자인



class Camera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera  // 새로운 카메라 등장
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class People
{
public:
	void useCamera(Camera* p) { p->take(); }  // 강한 결합 : 교체 불가능한 결합
	void useCamera(HDCamera* p) { p->take();  }  // HD Camera 등장으로 기존 코드 수정 => OCP를 만족 못하는 대표적인 코드
};

int main()
{
	People p;
	Camera cam;

	p.useCamera(&cam);	

	HDCamera hcam;
	p.useCamera(&hcam); // 
}

