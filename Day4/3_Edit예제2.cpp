#include <iostream>
#include <string>
#include <conio.h>


// 입력 도구에는 Validation(입력값의 유효성) 기능을 넣는 것이 좋다.
// Validation 정책은 교체 가능해야 한다

// 공통성과 가변성의 분리 
// => 변하지 않은 코드 내부에 있는 변해야 하는 부분을 찾는다.
// => 변해야 하는 부분을 분리한다.

// 변하는 것을 분리하는 방법 1. 변하는 것을 가상함수로 분리한다.
//								==> 변경하고 싶다면 파생 클래스를 설계하라는 것

class Edit
{
	std::string data;
public:

	// 변하는 것을 담은 가상함수
	virtual bool validate(char c)
	{
		return true; // 항상 true로 해두면 문자열, 숫자 상관없이 입력됨
	}

	std::string getData()
	{
		data.clear();
		while (1)
		{
			char c = _getch(); // 한 문자 입력	

			if (c == 13)       // enter키
				break;

			if (validate(c))
			{
				std::cout << c;     // 화면 출력 후
				data.push_back(c);  // 문자열에 추가
			}
		}
		std::cout << std::endl;

		return data;
	}
};

// validation 정책을 변경하려면 
// 파생 클래스를 만들어서 가상함수를 재정의 하라는 의도 !
// 라이브러리를 확장해서 기능을 수정함

class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
	//Edit e;      // 모든 것을 입력 받는 Edit
	NumEdit e;     // 숫자만 입력 받는 Edit
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


