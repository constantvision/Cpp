#include <iostream>
#include <string>
#include <memory>

struct Person
{
	std::string name;
	//	std::shared_ptr<Person> bestFriend;    // 참조 계수 증가
	//Person* bestFriend;  

	std::weak_ptr<Person> bestFriend; // 참조 계수 증가안함
									  // 객체 파괴 여부 조사 가능

	Person(const std::string& n) : name(n) {}
	~Person() { std::cout << name << "파괴" << std::endl; }
};

int main()
{
	std::shared_ptr<Person> p1(new Person("kim"));
	{
		std::shared_ptr<Person> p2(new Person("lee"));

		p1->bestFriend = p2;
		p2->bestFriend = p1;
	}


	if (p1->bestFriend.expired())
	{
		std::cout << "대상 객체 파괴됨" << std::endl;
	}
	else
	{
		// 파괴 되지 않은 상태
		//auto n = p1->bestFriend->name; // error.. weak는 "->" 연산자 안됨.

		// weak는
		// 1. 참조계수를 증가하지 않으므로 weak로 객체 접근시
		//    사용중에 객체가 파괴될 수 있습니다.

		// 2. 그래서 weak로는 객체 접근 안됩니다.

		// 3. 접근하고 싶으면 참조 계수 올리고 접근해야 합니다.

		// 4. 참조계수를 증가하는 방법은 shared_ptr을 만들어야 합니다.

		// 결론, waek를 사용해서 shared_ptr을 만든 후에 
		// shared_ptr의 유효성을 조사 후
		// 객체 접근

		std::shared_ptr<Person> sp = p1->bestFriend.lock();

		if (sp)
		{
			// 이제 sp로 객체 접근
			std::cout << sp->name << std::endl;
		}

	}
}