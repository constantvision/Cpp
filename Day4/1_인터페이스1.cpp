#include <iostream>

// ���� ����(tightly coupling)
// �ϳ��� Ŭ������ �ٸ� Ŭ���� ���� "Ŭ���� �̸�"�� ���� ����ϴ� ��

// ��ü �Ұ����� ������ ������

// OCP�� �������� ���ϴ� ������



class Camera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera  // ���ο� ī�޶� ����
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class People
{
public:
	void useCamera(Camera* p) { p->take(); }  // ���� ���� : ��ü �Ұ����� ����
	void useCamera(HDCamera* p) { p->take();  }  // HD Camera �������� ���� �ڵ� ���� => OCP�� ���� ���ϴ� ��ǥ���� �ڵ�
};

int main()
{
	People p;
	Camera cam;

	p.useCamera(&cam);	

	HDCamera hcam;
	p.useCamera(&hcam); // 
}

