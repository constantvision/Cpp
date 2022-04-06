// 5_상속2

class Base
{
private:   int a;	  // 자신의 멤버 함수에만 접근 가능
protected: int b;	  // 자신의 멤버 함수 + 파생 클래스 멤버 함수에서 접근 가능
public:    int c;	  // 어디서도 접근 가능
};

class Derived : public Base  
{
public:
	void foo()
	{
		a = 0;    // error. 물려는 받지만, 접근은 안됨. 접근하려면 기반클래스 함수 호출
		b = 0;    // ok.. protected는 파생 클래스에서도 접근 가능
		c = 0;    // ok
	}
};

int main()
{
	Base base;
	base.a = 0;    // error. private
	base.b = 0;    // error. protected는 외부 접근 안됨
	base.c = 0;    // ok
}
