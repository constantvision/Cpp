// 3_변수와타입5.cpp
// 26 page 아래 부분

struct Point
{
	int x = 0;
	int y = 0;
};
int main()
{
	Point pt = { 1,2 };

	int x = pt.x;
	int y = pt.y;

	// C++17 부터 구조체(배열)의 모든 요소를 한줄로 꺼낼수 있습니다.
	auto [a1, a2] = pt;	// int a1 = pt.x
						// int a2 = pt.y

	int[a3, a4] = pt; // error. auto 만 가능합니다.

	auto [a5, a6, a7] = pt; // 갯수가 다르면 안됩니다. 

	// 구조체뿐 아니라 배열도 됩니다.
	int arr[3] = { 1,2,3 };

	auto [b1, b2, b3] = arr; // 역시 auto로 하고, 갯수가 동일해야 합니다.

	// "structured binding"
}

// 현재 대부분의 C++ 컴파일러들은 C++14를 기준으로 컴파일 합니다
// C++17, 20 기술을 사용하려면 옵션을 지정해야 합니다. - 5 page
// g++ 소스이름.cpp -std=c++17
// cl  소스이름.cpp /std:c++17   ( VC가 사용하는 컴파일러)