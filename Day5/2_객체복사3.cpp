// string 사용
// 1_객체복사2.cpp   102 page ~
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


// 클래스 내부에 포인터 멤버가 있으면 
// 컴파일러가 만드는 복사 생성자는 "얕은복사(shallow copy)" 문제를 일으킵니다.
// (해결책) : 사용자가 복사 생성자를 직접 제공해서 문제를 해결해야 한다.

class People
{
	char* name;
	int*  ref;   // 참조계수 관리를 위한 멤버
//	static int ref;  // 어차피 공유할꺼면 static이 낫지 않냐? 
	int   age;
public:
	People(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);

		ref = new int;
		*ref = 1;

	}

	// 아래 복사 생성자가 참조 계수로 구현한 복사 생성자입니다.
	People(const People& p) : name(p.name), ref(p.ref), age(p.age)
	{
		++(*ref);
	}

	// 참조계수 사용시 자원 제거는 
	// 참조계수가 0일떄만 해야 합니다. 
	~People() 
	{
		if (--(*ref) == 0)
		{
			delete[] name;
			delete ref;
		}
	}
};

int main()
{
	People p1("kim", 20);  // 한 줄만 쓰면 문제가 없음.
	People p2 = p1;        // 이렇게 적으면 p2가 생성되는데, shallow copy 
	People p3 = p1;
	People p4 = p1;

	//static 쓸 경우
	// p1,p2,p3는 같은 자원 공유
	People p1("kim", 20);  
	People p2 = p1;        
	People p3 = p1;

	// p4,p5는 p1,p2,p3와 다른 자원 공유..
	People p4("lee", 20);
	People p5 = p4;

	// 그런데, 참조 계수를 static 멤버로 하면
	// p1,p2,p3,p4,p5가 모두 같은 ref로 공유하게 됨
	// 그래서, 참조 계수를 static으로 하면 안되고, 동적할당 할 수 밖에 없음.

}



