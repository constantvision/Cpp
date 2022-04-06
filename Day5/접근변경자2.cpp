// ���ٺ�����2
#include <list>

// STL�� stack�� ������..
// list�� ��ӹ޾Ӽ� ����� ���ô�.

/*
// �� ���� list �ȿ� �����Լ��� �ִٸ�, �����Լ��� ������ �� �� �ִ� ��ȸ�� ����
template<typename T>
//class Stack : public std::list<T>  // �� ��� �Ʒ��� push_front ���� �ƴ�
class Stack : private std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
};
*/

// ������ ��� Ŭ���� �Լ��� �������� �ʴ´ٸ�..
// �� ����� �ϳ���?
// ������ �ϸ� �Ǵµ�..

template<typename T>
class Stack 
{
	std::list<T> c;
public:
	void push(const T& a) { std::list<T>::push_back(a); }
};

// �� �������� ���� �翬�� "����"�� �����ϴ�. �׷���

// private ��� : ��� Ŭ������ �����Լ��� ������ �� �� �ִ� ��ȸ�� �ִ�.
// ����         : ��� Ŭ������ �����Լ��� ������ �� �� ����.

int main()
{
	Stack<int> s;
	s.push(10);
	s.push(20);

	s.push_front(30); // ����ڰ� �ǵ�ġ �ʰ�
	                  // ��� Ŭ������ �Լ��� ����ߴ�.
					  // error. private ����̹Ƿ�
					  // ��� Ŭ������ ��� ����� private ��ȣ�Ӽ� !
}