#include <iostream>

//�����Լ� ����   164page ~

// �����Ϸ��� Animal�� ��� �����Լ��� �ּҸ� ��� �迭 ����

// �Լ��ּ�ũ�� Ÿ�� (void* ��) 
animal_vtable[] = { RTTI����, 
					&Animal::Cry, 
					&Animal::Run };

class Animal
{
	void* vtptr = animal_vtable;  // �����Ϸ��� �߰��� ���.
	int age;
public:
	virtual void Cry() {}  // 1
	virtual void Run() {}
};


//--------------------
// Dog �����Լ� ������ ���� �迭(�����Լ� ���̺��̶�� ��)
dog_vtable[] = { RTTI����, 
				&Dog::Cry, 
				&Animal::Run };  // ������ ���� Run�� Animal���� ���ڴ�

class Dog : public Animal
{
	vtable = dog_vtable; // �����Ϸ��� �߰��� �ڵ�
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
	p->Cry();   // �����Լ� �̹Ƿ� 2�� ȣ��
				// p�� ����Ű�� ���� ���� �Ŀ� ȣ��

				// Cry �����Լ��� Animal���� ���° �����Լ����� ������ �߿���
				// �����Ϸ��� ������ ��, p->vtable[1]() ��� ���� �ڵ� ���� 
				// (����Ű�� �ּҿ� ������ vtable�� �־����. �ű� ���󰡸� �迭�� �ִµ�, cry�� ���°�� �ִ�)

				// �����Լ� ���� : �޸� ���� .. ���� ( ���� age�� ������ �Ǵµ� vtable ������ �޸� Overhead�� ����)
				// �����Լ��� �Ⱦ��� �̷� �������� ����
				// �����Լ� ���̺��� �޸𸮻� ������ ����������

}