#include <iostream>

class Car
{
	int speed;
public:
	void Go() { std::cout << "Car Go" << std::endl; }
	~Car() { std::cout << "~Car" << std::endl; }
};

// 핵심. 스마트 포인터는 "얕은 복사"를 해결해야 합니다.
//       => 깊은 복사가 아닌 "참조계수"로 해결해야 합니다.
//          (포인터의 동작방식을 생각해보세요)

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
	



