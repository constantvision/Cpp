// 7_스마트포인터 - 201(150)
#include <iostream>

// 1. 스마트 포인터는 "일반적으로 템플릿" 으로 만들게 됩니다.

template<typename T>
/*
class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}

	~Ptr() { delete obj; }  // 자동 delete 기능

	T* operator->() { return obj; }
	T& operator*() { return *obj; }

};
*/

// 오버헤드 없게 inline 함수 사용 시
// 성능 저하 없음
class Ptr
{
	T* obj;
public:
	inline Ptr(T* p = 0) : obj(p) {}

	inline ~Ptr() { delete obj; }  // 자동 delete 기능

	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

};

int main()
{
	Ptr<int> p1 = new int;
	*p1 = 10;
	std::cout << *p1 << std::endl;
}



