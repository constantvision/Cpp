
// 메모리 이야기
// C++
// public, private 뺴고 class 와 struct는 동일하다

class Point
{
	int x;
	int y;
};
int main()
{
	Point pt; // 스택에 만든다
	Point* p = new Point; // 힙에 만든다

}

// C#, java, swift
// => 타입의 메모리 위치를 "타입의 설계자가 결정"
// struct : value type, 스택에 생성. 복사시 새로운 객체 생성
// class : reference type, 힙에 생성, 복사시 참조(포인터 복사)
class CPoint
{
	int x;
	int y;
};

struct SPoint
{
	int x;
	int y;
};

int main()
{
	// C#
	CPoint cp = new CPoint();
	SPoint sp = new SPoint();

	SPoint sp2 = sp;
	CPoint cp2 = cp;
}