// 3_추상클래스 - 168(216)page

// ** 추상 클래스의 의도
// 의도 : 파생 클래스들에게 특정 함수를 반드시 만들라고 지시하는것임

// 추상 클래스 : 순수 가상함수가 한 개 이상 있는 클래스
// **특징 : 객체를 생성할 수 없다. 포인터는 가능하다

class Shape
{
public:
	virtual void Draw()  = 0;  // ** 순수 가상 함수 (pure virtual function)
							   // 특징 : 구현이 없다. (구현이 없다를 = 0 으로 하는 것)
};

// Shape로 부터 물려받았기 떄문에, Rect도 추상이다
// Rect를 쓰고 싶으면 Draw의 구현을 꼭 만들어야한다
class Rect : public Shape
{
public:
	// Draw()의 구현부를 제공하지 않으면 "Rect 도 추상"
	// void Draw() {} 와 같이 구현부를 제공하면 추상 아님(객체 생성 가능)
};

int main()
{
	Shape s; // 객체를 만들려고 하면 error. 추상 클래스는 객체를 만들 수 없다.
	Shape* p; // 포인터는 ok.  이 경우 파생 클래스 객체를 가리키겠다는 것.
	Rect  r; // ?
}


