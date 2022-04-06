// 언어의 특징
int main()
{
	// C++
	// primitive type과 user type type이 구분해서 사용해야함
	int n;
	bool b = n.isMultiply(3); // error. int는 primitive 타입이다. int는 멤버함수가 없ㅇ,ㅁ

	// C#의 등장 : "모든 것은 객체이다."
	//				java 까지는 primitive 타입 개념이 있음.(int 멤버함수 없음)
	//              python
	String s = 10.ToString(); // C#은 가능.

	// C, C++, java : int는 멤버 함수 없음
	// Python, C#, swift, kotlin 등 : int도 멤버 함수 있음.
}