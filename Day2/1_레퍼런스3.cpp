// 1_레퍼런스3. 45 page
struct BigData
{
	int buff[1024];
};

void foo(int n) // call by value : 함수호출에 사용한 인자를 수정하지 않을것
{				//					이라는 약속!
}

//void goo(BigData bd) // call by value 는 값을 변경하지 않을 것이라는 약속이지만
					 // 복사본 생성에 의한 오버헤드가 큽니다.
void goo(const BigData& bd) // const reference 가 아주 좋습니다.
{
	//	bd.buff[0] = 10; // error. const 이므로 수정할수 없다.
}

int main()
{
	BigData bd;
	goo(bd);

	int x = 100;
	// 어떤 함수에서 인자의 값을 절대 수정하면 안된다면
	foo(x);
}

// 인자값을 수정하지 않으려고 합니다. 다음중 좋은것은 ?
void f(int n) {}		// 1 => 좋은 코드
void f(const int& n) {} // 2 => 나쁜 코드


// 핵심 정리.. C++에서 함수 인자를 받는 방법

// 1. 인자의 값을 수정할것이라면
//    "포인터도 나쁘지 않고, 참조도 좋습니다. 요즘은 참조가 더 많이사용"
//    void f(int* p) {}
//    void f(int& r) {}

// 2. 인자의 값을 수정하지 않을것 이라면..

// A. primitive type(int, double 등) : call by value.  void f1(int n) {}
// B. user defined type(구조체, 클래스등): call by const reference
//									void f1(const BigData& bd) {}
//				C언어도 이렇게	 ==>	void f1(const BigData* bd) {}

// 구글에서 "C++ core guideline" 검색해 보세요