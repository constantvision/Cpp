#include <iostream>

// 멈베 함수의 호출 원리
// Stack s1, s2로 만들면
// 1. 멤버 데이터만 s1, s2 따로 사용하고
// 2. 멤버 함수는 공유 됩니다.
// 3. 원리는 아래 주석들을 참고 하세요..

struct Stack
{
	int buff[10];
	int idx;

	void push(int value)  // void push(Stack* this, int value)
	{
		buff[idx++] = value;  // this->buff[(this->idx)++] = value; 로 변경
	}

  	int pop()             // void pop(Stack* this) 
	{
		return buff[--idx]l; 
	}
};

int main()
{
	Stack s1, s2;
	s1.idx = 0;
	s2.idx = 0;

	s1.push(10); // push(&s1,10)으로 컴파일 됩니다.

	//push(&s1, 10);


}