#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v1(10);               // 10개짜리 동적 배열
	std::vector<int> v2 = { 1,2,3,4 };     // 4개짜리 동적 배열
										   // vector(std::initializer_list) 입니다

	// 아래 2줄의 차이점은 ?
	std::vector<int> v3(10, 3);            // vector(int, int) 생성자
										   // 10개를 3으로 초기화
	std::vector<int> v4{ 10,3 };           // vector(initializer_list)
										   // 2개를 10, 3으로 초기화

	std::cout << v3.size() << std::endl; // 10
	std::cout << v4.size() << std::endl; // 2

}