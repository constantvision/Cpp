#include <iostream>
#include <string>

class file_not_found {};

void foo()
{
	throw file_not_found();
}

void goo()
{
	try
	{
		foo();
	}
	catch (...)
	{
		throw; // ���� �߻��� ���ܸ� �ٽ� �߻� => �Ʒ� catch�� �Ѿ����
	}
}

int main()
{
	try
	{
		goo();
	}
	catch (...)
	{

	}

}

