#include <iostream>

int main()
{
	int n = 10;

	// 특정 변수의 타입을 알고 싶으면 "typeid" 라는 연산자를 사용하면 됨
	// typeid()의 반환 타입은 type_info 객체인데..
	// 반드시 const &로 받아야 함
	const std::type_info& t = typeid(n); // type_info는 typeid의 반환값을 받을 수 있음

	std::cout << t.name() << std::endl;

	double* p = reinterpret_cast<double*>(&n);

	std::cout << typeid(p).name() << std::endl;   // double*
	std::cout << typeid(*p).name() << std::endl;  // double
								// 즉, 실제로 따라가서 조사하는 것이 아니고
	                            // double* 이므로 * 하면 double 이겠지 !!
							    // 라고 컴파일 시간에 판단

	// 타입이름을 출력하는 것이 아니라 조사하려면
	const std::type_info& t1 = typeid(n);   // typeid(변수)
	const std::type_info& t2 = typeid(int); // typeid(타입)

	if (t1 == t2) {}

	// 실전에서는 그냥 아래 처럼 하세요
	if (typeid(n) == typeid(int)) // !!
	{
		 
	}

}