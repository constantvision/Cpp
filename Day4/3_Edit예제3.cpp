#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 방법
// 1. 변하는 것을 가상함수로 - Edit 2번 예제
// 2. 변하는 것을 다른 클래스로 - Edit 3번 예제

// 교체 가능하려면 인터페이스 만들고 각각이 이 인터페이스를 상속받아서 만들어야 함

// Validation 정책을 담은 클래스를 설계한다.
// 교체 가능해야 하므로 인터페이스를 먼저 설계 한다.

// 모든 Validation 정책은 아래 인터페이스(추상클래스)를 구현해야 한다.

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

// 주민 등록 번호 : 801	1	확인

class Edit
{
	std::string data;
	//---------------------------------
	IValidator* pval = nullptr;
public:
	void setValidator(IValidator* p) { pval = p; }
	//--------------------------------

	std::string getData()
	{
		data.clear();
		while (1)
		{
			char c = _getch(); // 한 문자 입력

			if (c == 13 && (pval == nullptr || pval->iscomplete(data))) // iscomplete 기본 구현이 true이면 value 보다 작은 숫자 입력받아도 괜찮음
				break;

			//if (isdigit(c))
			// pval이 없으면 다 입력 받겠다
			if (pval == nullptr || pval->validate(data,c)) // 유효성 여부를 외부에 위임한다.
			{
				std::cout << c;     // 화면 출력 후
				data.push_back(c);  // 문자열에 추가
			}
		}
		std::cout << std::endl;

		return data;
	}
};

// 1. Edit는 기본적으로 모든 입력을 허용합니다.
// 2. 입력값의 Validation 정책을 변경하려면
//    Validation 정책을 담은 다양한 클래스를 설계하면 됩니다.

class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int n) : value(n) {}

	bool validate(const std::string& s, char c) override
	{
		if (s.size() < value && isdigit(c))
			return true;
	
		return false;
	}

	bool iscomplete(const std::string& s) override
	{
		return s.size() == value;
	}
};

// 이제 "LimitDigitValidator"와 같이 "다양한 Validation 정책을 담은 클래스를
// 제공하면 됨
// 1. 이메일 규칙확인, 주민번호 확인, 나이제한, 전화번호 형식 등 ..

int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.setValidator(&v); // 숫자 입력 받는데 5자리 까지만 가능

	// 새로운 정책
	LimitDigitValidator v2(15);
	e.setValidator(&v2);
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


