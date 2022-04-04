class Car
{
	int color;
	static int cnt;
public:
	// 다음중 에러를 모두 골라 보세요
	void foo()	
	{
		color = 0;	// 1.
		cnt = 0;	// 2.
		goo();		// 3
	}
	static void goo()	
	{
		color = 0;	// 4. error
		cnt = 0;	// 5. ok
		foo();		// 6. error
	}
};
int Car::cnt;

int main()
{
}
