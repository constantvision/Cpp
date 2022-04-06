#include <iostream>
#include <string>
#include <memory>

struct Person // public 한줄 줄이려고 struct 한것뿐임
{
	std::string name;
	std::shared_ptr<Person> bestFriend;

	Person(const std::string& n) : name(n) {}
	~Person() { std::cout << name << "파괴" << std::endl; }


};

int main()
{
	std::shared_ptr<Person> p1(new Person("kim"));
	std::shared_ptr<Person> p2(new Person("lee"));

	// 아래 같은 현상을 상호참조(원형참조, cycle reference)라고 합니다.
	// 메모리 누수로 delete가 안됨.
	p1->bestFriend = p2;
	p2->bestFriend = p1;

	// shared_ptr 같은 참조계수 기반 스마트 포인터 사용시
	// 위와 같은 상호 참조(원형 참조) => 자원 누수가 항상 있음
	// 자원 삭제가 되지 않는 문제
}