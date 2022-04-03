// 1_레퍼런스3. 45 page
struct BigData
{
	int buff[1024];
};

void foo(? n)
{
}
int main()
{
	int x = 100;

	// 어떤 함수에서 인자의 값을 절대 수정하면 안된다면
	foo(x);
}
