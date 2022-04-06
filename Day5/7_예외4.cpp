// 5_예외1 - 231
#include <iostream>


// 오류(예외) 전용 타입을 설계하는 것이 좋습니다.
class bad_url_exception
{
	int code;
	std::string description;
public:
	bad_url_exception(int n) : code(n) {}

	// 다양한 멤버로 많은 정보를 알려 주세요.
};

// 또한 아래처럼 empty class로만 설계해도 나쁘지 않습니다.
// 이름 자체가 설명입니다.

class file_not_found {};

int connectServer()
{
	if (1)        // 실패라고 가정
	{
	//		Point pt(1, 2);  // 이름 있는 객체
	//		Point(1, 2);     // 이름없는 객체, 임시객체를 만드는 표기법
							 // 예외를 던질때 많이 사용

		throw bad_url_exception(404);
					         // 임시객체로 던져진 예외는 참조로 받아도 됩니다.
							 // catch가 끝날때 까지 파괴되지 않습니다.
	}
	return 0;
}

int main()
{
	try
	{
		connectServer();
		// ... 성공시 코드.....
	}
	catch (bad_url_exception& e)  
	{
		std::cout << "예외발생. catch하면 프로그램 계속 실행 가능" << std::endl;
	}

	std::cout << "프로그램 계속 실행" << std::endl;

}
