
// 1. C++�� ���� ��� �����մϴ�.
//    => �׷���, ������� ����� �����մϴ�.

// ���̾Ƹ�� ��� : ��� ������ �׸��� ���� �̸� ����

class X
{
public:
	int x;
};
class A : public X
{
public:
	int a;
};
class B : public X
{
public:
	int b;
};
class C : public A, public B
{
public:
	int c;
};

int main()
{
	C ccc;
	//ccc.x = 100;  // error. ��� x���� �� �� ����. 
	
	// �Ʒ�ó���ϸ� ���� ������
	ccc.A::x = 100;
	ccc.B::x = 200;

}

// java, C# : 2�� �̻��� Ŭ�����κ��� ��� �ȵ�. (���� ��� ���� ����)
//            ��, �Ѱ��� Ŭ������ ���� ���� �������̽��� ����
/*
class AAA : BBB, INTERFACEA, INTERFACE
{

};

class AAA : BASECLASSA, BASECLASSB // Error �� Ŭ������ ���� �Լ��� ���� �� �ֱ� ������ �浹 ���
{

};
*/