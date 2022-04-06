
// 1. C++은 다중 상속 지원합니다.
//    => 그런데, 사용하지 말라고 권장합니다.

// 다이아몬드 상속 : 상속 계층의 그림을 보고 이름 지음

class X
{
public:
	int x;
};
class A : public X
{
public:
	int a;
};
class B : public X
{
public:
	int b;
};
class C : public A, public B
{
public:
	int c;
};

int main()
{
	C ccc;
	//ccc.x = 100;  // error. 어느 x인지 알 수 없다. 
	
	// 아래처럼하면 접근 가능함
	ccc.A::x = 100;
	ccc.B::x = 200;

}

// java, C# : 2개 이상의 클래스로부터 상속 안됨. (다중 상속 지원 안함)
//            단, 한개의 클래스와 여러 개의 인터페이스는 가능
/*
class AAA : BBB, INTERFACEA, INTERFACE
{

};

class AAA : BASECLASSA, BASECLASSB // Error 각 클래스에 같은 함수가 있을 수 있기 때문에 충돌 우려
{

};
*/