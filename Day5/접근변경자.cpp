// ���ٺ�����

class Base
{
private:
	int a;
public:
	int b;
};

// ���� ������.. ��� Ŭ���� ��� ��ȣ�Ӽ��� ������ ���
// //            �������� ����.
//class Derived : public Base
class Derived : private Base
{
};

int main()
{
	Derived d;
	//d.a = 10; // error
	//d.b = 10; // ok

	Base b;
	b.b = 10; // ok .. Base �ȿ��� b�� public
}