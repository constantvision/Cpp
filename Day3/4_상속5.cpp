// 상속5.cpp
#include <iostream>
#include <string>

class Person
{
	std::string name;
	int age;
public:
	// 요즘 객체지향의 트렌드는 "반드시 초기화 된 객체"를 사용하도록 하자
	Person(const std::string& n, int a) : name(n), age(a) {}
};

// 생각보다 "디폴트 생성자가 없는" 클래스가 많습니다.
class Student : public Person
{
	int id;
public:
//	Student(int n) : id(n) {}  // Student(int n) : Person(), id(n) {}

	// 핵심 : Person에 디폴트 생성자가 없으므로
	//        Student 생성자를 아래처럼 만들어야 합니다.
	Student(const std::string& name, int age, int id)
		: Person(name, age), id(id)
	{
	}
};

int main()
{
	Person p("kim", 30);

	Student s("kim", 30, 99);
}