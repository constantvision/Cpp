#include <iostream>
#include <string>
#include <conio.h>

// Validation 정책은 교체 가능해야 한다.

// Edit 같은 클래스는 라이브러리 내부 코드 => 내부 코드에 들어와서 직접 수정은 말이 안됨

class Edit
{
	std::string data;
public:
	std::string getData()
	{
		data.clear();
		while (1)
		{
			char c = _getch(); // 한 문자 입력

			if (c == 13)       // enter키
				break;
			if (isdigit(c))
			{
				std::cout << c;     // 화면 출력 후
				data.push_back(c);  // 문자열에 추가
			}
		}
		std::cout << std::endl;

		return data;
	}
};

int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


