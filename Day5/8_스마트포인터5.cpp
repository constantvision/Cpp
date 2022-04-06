#include <iostream>
#include <string>
#include <memory>

struct Person // public ���� ���̷��� struct �Ѱͻ���
{
	std::string name;
	std::shared_ptr<Person> bestFriend;

	Person(const std::string& n) : name(n) {}
	~Person() { std::cout << name << "�ı�" << std::endl; }


};

int main()
{
	std::shared_ptr<Person> p1(new Person("kim"));
	std::shared_ptr<Person> p2(new Person("lee"));

	// �Ʒ� ���� ������ ��ȣ����(��������, cycle reference)��� �մϴ�.
	// �޸� ������ delete�� �ȵ�.
	p1->bestFriend = p2;
	p2->bestFriend = p1;

	// shared_ptr ���� ������� ��� ����Ʈ ������ ����
	// ���� ���� ��ȣ ����(���� ����) => �ڿ� ������ �׻� ����
	// �ڿ� ������ ���� �ʴ� ����
}