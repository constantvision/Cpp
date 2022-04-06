#include <iostream>
#include <string>
#include <memory>

struct Person
{
	std::string name;
	//	std::shared_ptr<Person> bestFriend;    // 참조 계수 증가
	Person* bestFriend;  // raw pointer는 참조계수와 관련 없습니다.
	                     // 문제점 : dangling pointer 현상이 발생할 수 있습니다.
	                     //          C언어에서 너무나 유명한 현상
	                     //          이 문제를 해결하는 도구가 weak_ptr 입니다.

	Person(const std::string& n) : name(n) {}
	~Person() { std::cout << name << "파괴" << std::endl; }
};

int main()
{
	std::shared_ptr<Person> p1(new Person("kim"));
	{
		std::shared_ptr<Person> p2(new Person("lee"));

		p1->bestFriend = p2.get();
		p2->bestFriend = p1.get();
	}

	// 아래 코드 생각해 보세요
	if (p1->bestFriend != nullptr)
	{
		auto n = p1->bestFriend->name;
	}
}