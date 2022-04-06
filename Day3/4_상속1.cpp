// 5_상속1.cpp   132page ~
// 학사 관리 프로그램

#include <iostream>
#include <string>

// 용어 정리
// Person  : Base Class, Super Class, Parent Class 
// Student : Derived Class, Sub Class, Child Class

// 1. 모든 사람이 가져야하는 특징으로 "Person" 타입 설계

class Person
{
	std::string name;
	int age;
};

// 2. 기존 타입(Person)을 확장해서 새로운 타입을 설계 한다.
// 상속(inheritance) : 기존 타입을 확장해서 새로운 타입을 만드는 문법

// C++         : Class student : public Person
// C#, Swift   : Class student : Person
// Java        : Class student extends Person
// Python      : Class Student(Person)

class Student  : public Person
{	
	//std::string name;
	int    id;
};

class Professor : public Person
{
	//std::string name;
	int    major;
};

int main()
{
	Student s;
	Professor p;
}
