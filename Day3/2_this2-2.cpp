// 2_this2-2
#include <iostream>

struct Point 
{
	int x;
	int y;
	~Point() { std::cout << "~Point()" << std::endl; }
};

Point pt = { 1,2 };

Point f3()
{
	return pt;
}

Point& f4()    // return by reference : 리턴용 임시객체를 만들지 말고
{			   // pt 자체를 반환해 달라는 의미(alias 반환) 
	 
	return pt;
}

int main()
{
//	f3().x = 10; // error. 임시 객체
//	f3();
//	f4();
	f4().x = 10; // ok.. pt.x = 10 참조 반환이므로 임시객체 아님

	std::cout << "-----" << std::endl;
}