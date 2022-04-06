// 예제1     152 page
#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 객체 지향으로 만들어 봅시다
// 1. 모든 도형을 타입화 하면 편리함

// 2. 모든 도형의 공통의 기반 클래스가 있다면 모든 도형을 하나의 vector에 보관할 수 있다.

class Shape
{

};

class Rect : public Shape
{

public:
	void draw() { std::cout << "draw rect" << std::endl; }

};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }

};


int main()
{
	std::vector<Shape*> v;
}



