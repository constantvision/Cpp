#include <iostream>

// 이미 C++ 표준에 템플릿 기반으로 만들어지 stack 이 있습니다.
#include <stack>

// STL ( Standard Template Library )
// C++ 표준이 제공하는 "템플릿 기반의 라이브러리"

int main()
{
	std::stack<int> s;

	s.push(10);
	s.push(20);

	// 주의 ! 꺼내는 함수와 제거함수가 분리되어 있습니다.
	std::cout << s.top() << std::endl; // 꺼내기만, 제거안됨 20 
	std::cout << s.top() << std::endl; // 꺼내기만, 제거안됨 20

	s.pop(); // 제거만, 반환은 안됨.
	std::cout << s.top() << std::endl; // 10
}
