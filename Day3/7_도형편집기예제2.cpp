#include <iostream>
#include <vector>

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

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			// Rect r;  // 이렇게 하면 {} 벗어날 때 즉시 파괴됨
			//new Rect;  // 이렇게 해야 명시적으로 제거할 때 까지 계속 사용가능 => 하지만 주소를 알 수없다

			//Rect* p = new Rect;  // p는 지역 변수라 블록 벗어나면 파괴되서 더이상 해당 부분 못가리킴
			//v.push_back(p);      // p가 파괴되기 전에 vector에 넣어둠
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}

		else if (cmd == 9)
		{
			// 지금까지 만든 모든 모형을 그려줍니다.
			for (auto p : v) // 결국 shape의 pointer(Shape*) . shape 안에 draw가 없어 error. 
				p->draw();
		}
	}

}

// 왜 이코드는 에러일까? 해결책은?
// 1. Shape 안에 draw를 만들자
// 2. Shape* 타입인 p를 Rect* 또는 Circle*로 캐스팅하자