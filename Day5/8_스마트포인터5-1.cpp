#include <iostream>
#include <string>
#include <memory>

struct Person 
{
	std::string name;
//	std::shared_ptr<Person> bestFriend;    // 참조 계수 증가

	Person* bestFriend;  // raw pointer는 참조계수와 관련 없습니다.

	Person(const std::string& n) : name(n) {}
	~Person() { std::cout << name << "파괴" << std::endl; }
};

int main()
{
	std::shared_ptr<Person> p1(new Person("kim"));
	std::shared_ptr<Person> p2(new Person("lee"));

	// bestFriend는 스마트포인터가 아니므로 p2.get()하면
	// p2가 가리키는 raw pointer 얻을 수 있습니다.
	p1->bestFriend = p2.get();
	p2->bestFriend = p1.get();

	// 현재 코드는 자원누수(메모리 삭제 안됨)
	// 의 문제는 해결했습니다.

	// 그런데,,, 5-2 소스의 문제가 있습니다.

}