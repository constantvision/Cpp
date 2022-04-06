#include <iostream>

// ���� �����ڸ� ǥ�� ���� ���� ���
// Struct : public�� ����Ʈ �Դϴ�.
// Class : private�� ����Ʈ �Դϴ�.

// C++ struct�� class�� ���̴� �����ΰ���?
// => ��, "�Ѱ����� ������" �� �ֽ��ϴ�.
// => ���� ������ ������ "����Ʈ"�� �����ΰ� �Դϴ�.

// ��, �ٸ� ���(C#, java, swift ��)������
// struct vs class�� ���� ���̰� �����ϴ�. (value type, reference type ����)

// ��ü���� ö�� : �����ؾ� �մϴ�. (����ڰ� �߸� ����� �� ���� �ؾ� �մϴ�.)
//			       �׷���, strutc ���ٴ� class�� �����ϴ�.(C++����)
//				   ��, ��� ����� �ǵ������� public���� ��������
//				   struct�� �ϼ���..
 
//struct Stack
class Stack
{
//private:					 
	int buff[10];
	int idx;

public:						 
	void init() { idx = 0; }
	void push(int value) { buff[idx++] = value; }
	int pop() { return buff[--idx]; }

};

int main()
{
	Stack s1;
	s1.init();

	s1.push(10);
	s1.push(20);

	std::cout << s1.pop() << std::endl;
}