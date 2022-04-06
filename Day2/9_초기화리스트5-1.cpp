// 9_초기화리스트5 - 1
#include <iostream>

int g = 10;

class Test
{
	// C++11의 field 초기화 사용할 때
	int v1 = 0;   // 이렇게 리터럴 초기화는 좋습니다. 많이 사용하세요
	int v2 = ++g; // 절대 이런 코드는 사용하지 마세요. 혼란스럽습니다.

	// QA. 멤버가 배열일 때 좋은 방법이 있나요?
	// C++11 이후면 바로 초기화 됩니다.
	int arr[5] = { 1,2,3,4,5 };

public:
	//
	Test() : arr{ 1, 2, 3 } {}  // Test() : v1(0), v2(++g) {}
	Test(int n) : v2(n) {}      // Test(int n) : v1(0), v2(n) {}
};

int main()
{
	Test t1;
	Test t2(5);
	std::cout << g << std::endl; // 11
}