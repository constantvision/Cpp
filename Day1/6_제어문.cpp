// 6_제어문 - 31 page

int foo()
{
	return 10;
}

int main()
{
	int ret1 = foo();

	if (ret1 == 10)
	{
	}

	// C++17 부터 아래 처럼 가능합니다.
	if (int ret2 = foo(); ret2 == 10)
	{
	} // <== 여기서 ret2 파괴!

	// switch 도 가능합니다
	switch (int n = foo(); n)
	{
	case 10: break;
	case 20: break;
	}


	//	while (int count = 0; count < 10) // 이것도 될까요 ?
	//	{								 // error. while은 지원안함
	//		++count;					 // 왜 지원안하나요 ?
	//	}								 // => 이미 for 가 있습니다.

	//	int ret3;
	//	if ( (ret3 = foo()) == 10)
}

