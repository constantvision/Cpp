#include <iostream>

// 함수 제작시, 예외 가능성이 없으면
// "noexcept"를 붙이는 것이 좋습니다.

// noexcept 용도는 두가지 1) 예외가 없다는 걸 선언부에 보여주기 2) 예외가 없는지 조사
// 오버헤드가 좀 있어서 임베디드에서는 안씀. 리턴 값으로 함

//void foo() // 컴파일러는 선언만 보기 때문에 예외 가능성 있음
void foo() noexcept // 예외 없다는 것을 컴파일러에게 알려주는 것
					// ex) a + b 
{
	// throw;  // error. 미정의 동작이 나옴
}

int main()
{
	// noexcept : 함수가 예외 가능성이 있는지 조사
	//            실제로 함수를 호출하는 것은 아님
	bool b = noexcept(foo()); // 예외 가능성이 없는지 조사

	if (b)
		std::cout << "foo 예외 가능성 없음. 항상 안전" << std::endl;
	else
		std::cout << "foo 예외 가능성 있음" << std::endl;
}

// ** 시험 문제 : try, throw, catch