// 4_함수6-1
void foo(int n)
{
}

// 함수를 반환하는 함수 => 반환타입표기가 복잡해 보입니다.
// void(*f)(int) 의 모양에서 "f" 자리에 "goo()" 넣으면 됩니다.
//void(* goo())(int)
auto goo() -> void(*)(int)  // 후위형 반환 표기하면 편리합니다.
{
	return &foo;
}

int main()
{
	goo();
}