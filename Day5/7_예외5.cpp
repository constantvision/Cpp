// 5_����1 - 231
#include <iostream>


// ����(����) ���� Ÿ���� �����ϴ� ���� �����ϴ�.
class bad_url_exception
{
	int code;
	std::string description;
public:
	bad_url_exception(int n) : code(n) {}

	// �پ��� ����� ���� ������ �˷� �ּ���.
};


class file_not_found {};

int connectServer()
{
	if (1)        // ���ж�� ����
	{
		throw bad_url_exception(404);
	}
	return 0;
}

int main()
{
	try
	{
		connectServer();
		// ... ������ �ڵ�.....
	}
	catch (bad_url_exception& e)
	{
		std::cout << "���ܹ߻�. catch�ϸ� ���α׷� ��� ���� ����" << std::endl;
	}
	catch (file_not_found& e)
	{
		std::cout << "���ܹ߻�. catch�ϸ� ���α׷� ��� ���� ����" << std::endl;
	}
	
	catch(...) // catch ������ ���� �� ����
		       // ������ ������ ���� ��� ���ܸ� ���⼭ ó��

	std::cout << "���α׷� ��� ����" << std::endl;

}

