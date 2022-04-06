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
		throw; // 현재 발생된 예외를 다시 발생 => 아래 catch로 넘어가도록
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

