// 1_객체복사2.cpp   102 page ~
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


// 클래스 내부에 포인터 멤버가 있으면 
// 컴파일러가 만드는 복사 생성자는 "얕은복사(shallow copy)" 문제를 일으킵니다.
// (해결책) : 사용자가 복사 생성자를 직접 제공해서 문제를 해결해야 한다.

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
	
	// 클래스 내부에 포인터 멤버가 있다면
	// 사용자가 직접 복사생성자를 만들어서
	// 얕은복사(shallow copy) 문제를 해결해야 합니다.
	// 아래처럼 "메모리 자체를 복사" 하는 기술을
	// " 깊은 복사(Deep copy)" 라고 합니다.

	People(const People& p) : age(p.age)
	{
		//age = p.age;

		name = new char[strlen(p.name) + 1];
		
		strcpy(name, p.naem);
	}

};
   
int main()
{
	People p1("kim", 20);  // 한 줄만 쓰면 문제가 없음.
	People p2 = p1;        // 이렇게 적으면 p2가 생성되는데, shallow copy 
}



