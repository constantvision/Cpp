#include <iostream>

class Counter
{
	int count = 0;
public:
	//Counter increment()  이렇게 하면 임시객체들 생성되서 return은 결국 1
	Counter& increment()
	{
		++count;
		return *this;
	}
	int get const() { return count; }

	~Counter() { std::cout << "~Counter" << std::endl; }
};

int main()
{
	Counter c;
	//	c.increment();
	//	c.increment();
	//	c.increment();
	c.increment().increment().increment();   // 최종 임시객체로 3까지 실행되었으나, 아래줄로 내려가는 순간 임시 객체들은 파괴됨 / 임시객체1, 2, 3 까지 모두


	// c.increment(); 결과로 온것은 똑같이 생긴 임시 객체를 만들어서 1로 하고, 임시 객체 1번이 온것임. 그것에 대해 increment()를 하면 임시 객체가 증가.

	std::cout << c.get() << std::endl;
}