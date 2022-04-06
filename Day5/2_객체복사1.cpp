
// 1_객체복사.cpp   102 page ~
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// 복사 생성자가 왜 중요 한가요??
// => 컴파일러가 만들어주는 것을 사용하면 문제가 되나요?
// => Point 클래스는 아무 문제 없습니다. 그냥 컴파일러 제공 버전 사용하세요.

// 그런데, 일부 클래스에서 "컴파일러 제공 복사 생성자"가 문제가 됨

// 클래스 내부에 포인터 멤버가 있으면 
// 컴파일러가 만드는 복사 생성자는 "얕은복사(shallow copy)" 문제를 일으킵니다.
// 사용자가 복사 생성자를 직접 제공해서 문제를 해결해야 한다.

class People
{
	char* name;     
	int   age;    
public:
	People(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~People() { delete[] name; }
};
   
int main()
{
	People p1("kim", 20);  // 한 줄만 쓰면 문제가 없음.
	People p2 = p1;        // 이렇게 적으면 p2가 생성되는데, shallow copy 
}



