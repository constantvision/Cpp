#include <iostream>
#include <string>
#include <conio.h>

// Validation ��å�� ��ü �����ؾ� �Ѵ�.

// Edit ���� Ŭ������ ���̺귯�� ���� �ڵ� => ���� �ڵ忡 ���ͼ� ���� ������ ���� �ȵ�

class Edit
{
	std::string data;
public:
	std::string getData()
	{
		data.clear();
		while (1)
		{
			char c = _getch(); // �� ���� �Է�

			if (c == 13)       // enterŰ
				break;
			if (isdigit(c))
			{
				std::cout << c;     // ȭ�� ��� ��
				data.push_back(c);  // ���ڿ��� �߰�
			}
		}
		std::cout << std::endl;

		return data;
	}
};

int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


