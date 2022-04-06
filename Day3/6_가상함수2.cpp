// 7_가상함수2.cpp  147 page ~

class Shape
{
public:
	virtual void Draw() {};
	virtual void Clone() const {};
	virtual void Move() {};
};

class Rect : public Shape
{
public:
	// virtual은 빼도 되지만 
	// 1. 가상함수 재정의시 virtual은 빼도 되는데, 붙이는 것이 좋음.(?)
	// 위의 Clone과 아래 Clone은 다른데도, 컴파일러가 다른 함수로 생각해서 Error를 안냄..
	// 2. C++98 시절에 가상함수 재정의시 오타가 있어도 에러가 나지 않았음
	// 3. 그래서 C++11에서 override 키워드를 만들었음
	// 과거와의 호환성을 위해 무조건 붙이는건 아님.

	// 결론, 가상함수 재정의시 꼭 override 붙이기 (문법상 없어도 되지만, 안전하게 하기 위해)
	virtual void draw()  override {};
//          void draw()  override {};    // override가 있어 virtual을 빼도 크게 상관은 없음 요새
	virtual void Clone() override {};
	virtual void Move(int n) override {};
};

class Subrect : public Rect
{
public:

};

int main()
{

}
