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


class file_not_found {};

int connectServer()
{
	if (1)        // 실패라고 가정
	{
		throw bad_url_exception(404);
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
	catch (file_not_found& e)
	{
		std::cout << "예외발생. catch하면 프로그램 계속 실행 가능" << std::endl;
	}
	
	catch(...) // catch 여러개 만들 수 있음
		       // 위에서 잡히지 않은 모든 예외를 여기서 처리

	std::cout << "프로그램 계속 실행" << std::endl;

}

