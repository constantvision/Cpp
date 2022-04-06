#include <iostream>

// ī�޶� ���� ������ ����
// ī�޶� �����ڰ� ���Ѿ��ϴ� ��Ģ�� ���� �����Ѵ�.

// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ�����κ��� �Ļ��Ǿ�� �Ѵ�."
//			 => ��� ī�޶�� take �Լ��� �������Ѵٴ� �ǹ�

class ICamera
{
public:
	virtual void take() = 0; 

};

// ��Ģ�� �����Ƿ� ���� ī�޶� ��� ī�޶� ����ϴ� �ڵ带 ���� �ۼ��ص� ��
// ��Ģ��θ� ����ϸ� ��


class People
{
public:
	void useCamera(ICamera* p) { p->take(); }  // ���� �Լ��� ������ Ÿ�����δ� ��� ������ 

};

// ���� ��� ī�޶�� "��Ģ"�� ���Ѿ� �մϴ�.
// "ICamera"�� ���� �Ļ��Ǿ�� �մϴ�

class Camera : public ICamera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera  : public ICamera // ���ο� ī�޶� ����
{
public:
	void take() { std::cout << "take HD picture" << std::endl; }
};

class UHDCamera : public ICamera  // ,public Phone ������ ���� ��ӵ� ������
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