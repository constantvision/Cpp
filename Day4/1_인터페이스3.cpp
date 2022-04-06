#include <iostream>

// �������̽� : ���Ѿ� �ϴ� ��Ģ�� ���� �ڵ�
//              C#, java �� : "interface" ��� Ű���� ���� ( ������ Ű���� ȭ)
//              C++         : "interface"��� Ű���� ����, �߻�Ŭ���� ���

// ����������
// �������̽� : ���Ѿ� �ϴ� ��Ģ(���������Լ�)�� �ִ� ���
// �߻�Ŭ���� : ���Ѿ� �ϴ� ��Ģ(���������Լ�) + �ٸ� �����
//              ���� ��� "���������⿹���� Shape (draw() = 0�� int color)"
//-----------------------------------

// ���� ����(loosely coupling)
// �ϳ��� Ŭ������ �ٸ� Ŭ���� ���� "Ŭ�����̸�"�� �ƴ� "��Ģ�� ���� �������̽�"�� ���ؼ� ����ϴ°�

// ** ��ü ������ ������ �������� �ٽ�


// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ�����κ��� �Ļ��Ǿ�� �Ѵ�." ( �Ļ��� ���𰡸� �����ִ� ������ ����) 
//			 => ��� ī�޶�� take �Լ��� �������Ѵٴ� �ǹ�
// (��� ������ ���� �ʾ�)
//        "��� ī�޶�� ICamera �������̽��� �����ؾ� �Ѵ�."   - �Ϲ����� ��ü����
//                       ICamera ���������� �ؼ��ؾ� �Ѵ�."     - Swift


// C++���� �������̽� ���鶧 "class" ���� "struct" �� ��ȣ�ϴ� �������ֽ��ϴ�.
/*
class ICamera
{
public:
	virtual void take() = 0;
};
*/

#define interface struct  // �̷��� �ϴ� ��쵵 �ֽ��ϴ�.

//struct ICamera
interface ICamera
{
	virtual void take() = 0;

	virtual ~ICamera() {}  // �������̽�(�߻�Ŭ����)�� �ᱹ ��� Ŭ�����̹Ƿ�
						   // �ݵ�� �Ҹ��ڸ� �������� ���弼��.
							// �����̶�� ���� �˷��ֱ� ���� ����
};

// ICamera* p = new Camera;
// delete p;

class People
{
public:
	void useCamera(ICamera* p) { p->take(); }  // ���� �Լ��� ������ Ÿ�����δ� ��� ������ 

};


class Camera : public ICamera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera : public ICamera // ���ο� ī�޶� ����
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