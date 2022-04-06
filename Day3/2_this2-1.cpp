// 2_this2-1
#include <iostream>

struct Point // class로 해도 됩니다.
{
	int x;
	int y;
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 핵심 1. f1, f2의 차이점을 정확히 알아 두세요
/*
void f1(Point p1) {}   // call by value     : 복사본 객체 생성
void f2(Point& p2) {}  // call by reference : 복사본 객체 생성 안함

int main()
{
	Point pt;
	f1(pt);
	f2(pt);

}
*/

// 위 코드를 잘 생각하면서, 아래 코드를 보세요
Point pt = { 1,2 };

Point f3() // return by value
{
	return pt; // 진짜 pt를 반환할까요?
			   // 이 순간 pt를 복사한 리턴용 임시객체
			   // 가 생성되고 임시객체가 반환됩니다.
}

int main()
{
	f3().x = 10;  // error. 임시 객체는 등호의 왼쪽에 올 수 없습니다.
				  // 리턴용 임시객체는 함수 호출문장이 끝나면 파괴 됩니다.
	std::cout << "-----" << std::endl;
}

