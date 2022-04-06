#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


// 아래처럼 C 언어로 메뉴를 설계하면
// 1. 메뉴 갯수가 늘어나면 여러곳이 변경됨
// 2. 기존 메뉴에 "하위 메뉴" 같은 것이 추가되면 코드가 복잡해짐

int main()
{
	printf("1. 김밥\n");
	printf("2. 라면\n");
	printf("3. 우동\n");
	printf("메뉴를 선택 하세요 >> ");

	int cmd;
	scanf("%d", &cmd);

	switch (cmd)
	{
	case 1: break;
	case 2: break;
	case 3: break;
	}	
}
