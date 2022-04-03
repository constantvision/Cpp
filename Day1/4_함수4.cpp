// 4_함수4
// C++ 함수의 특징 4. 함수 템플릿
int square(int a)
{
	return a * a;
}
double square(double a)
{
	return a * a;
}


int main()
{
	square(3);
	square(3.4);
}