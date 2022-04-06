// 접근변경자2
#include <list>

// STL에 stack이 있지만..
// list를 상속받앙서 만들어 봅시다.

/*
// 이 경우는 list 안에 가상함수가 있다면, 가상함수를 재정의 할 수 있는 기회가 있음
template<typename T>
//class Stack : public std::list<T>  // 이 경우 아래의 push_front 에러 아님
class Stack : private std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
};
*/

// 어차피 기반 클래스 함수를 노출하지 않는다면..
// 왜 상속을 하나요?
// 포함을 하면 되는데..

template<typename T>
class Stack 
{
	std::list<T> c;
public:
	void push(const T& a) { std::list<T>::push_back(a); }
};

// 위 디자인의 경우는 당연히 "포함"이 좋습니다. 그런데

// private 상속 : 기반 클래스의 가상함수를 재정의 할 수 있는 기회가 있다.
// 포함         : 기반 클래스의 가상함수를 재정의 할 수 없다.

int main()
{
	Stack<int> s;
	s.push(10);
	s.push(20);

	s.push_front(30); // 사용자가 의도치 않게
	                  // 기반 클래스의 함수를 사용했다.
					  // error. private 상속이므로
					  // 기반 클래스의 모든 멤버는 private 보호속성 !
}