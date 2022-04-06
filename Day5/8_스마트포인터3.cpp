#include <iostream>

class Car
{
	int speed;
public:
	void Go() { std::cout << "Car Go" << std::endl; }
	~Car() { std::cout << "~Car" << std::endl; }
};

// �ٽ�. ����Ʈ �����ʹ� "���� ����"�� �ذ��ؾ� �մϴ�.
//       => ���� ���簡 �ƴ� "�������"�� �ذ��ؾ� �մϴ�.
//          (�������� ���۹���� �����غ�����)

template<typename T>
class Ptr
{
	T* obj;
public:
	inline Ptr(T* p = 0) : obj(p) {}
	inline ~Ptr() 
	{
		if (--(*ref) == 0)
		{
			delete obj;
			delete ref;
		}
	} 

	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }
};

int main()
{
	Ptr<int> p1 = new int;
	Ptr<int> p2 = p1;
	
}
	



