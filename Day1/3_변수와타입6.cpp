#include <iostream>
#include <cstring>

int main()
{
	char s1[] = "ABCD"; 
	char s2[10];

	s2 = s1;  ;// error. 배열의 이름은 상수 => strcpy를 써야함

	if ( s1 == s2 ) {} // strcmp를 써서 비교해야함 strcmp(s2,s1) == 0 
}
