#include <iostream>
#include <string>
#include <conio.h>


// �Է� �������� Validation(�Է°��� ��ȿ��) ����� �ִ� ���� ����.
// Validation ��å�� ��ü �����ؾ� �Ѵ�

// ���뼺�� �������� �и� 
// => ������ ���� �ڵ� ���ο� �ִ� ���ؾ� �ϴ� �κ��� ã�´�.
// => ���ؾ� �ϴ� �κ��� �и��Ѵ�.

// ���ϴ� ���� �и��ϴ� ��� 1. ���ϴ� ���� �����Լ��� �и��Ѵ�.
//								==> �����ϰ� �ʹٸ� �Ļ� Ŭ������ �����϶�� ��

class Edit
{
	std::string data;
public:

	// ���ϴ� ���� ���� �����Լ�
	virtual bool validate(char c)
	{
		return true; // �׻� true�� �صθ� ���ڿ�, ���� ������� �Էµ�
	}

	std::string getData()
	{
		data.clear();
		while (1)
		{
			char c = _getch(); // �� ���� �Է�	

			if (c == 13)       // enterŰ
				break;

			if (validate(c))
			{
				std::cout << c;     // ȭ�� ��� ��
				data.push_back(c);  // ���ڿ��� �߰�
			}
		}
		std::cout << std::endl;

		return data;
	}
};

// validation ��å�� �����Ϸ��� 
// �Ļ� Ŭ������ ���� �����Լ��� ������ �϶�� �ǵ� !
// ���̺귯���� Ȯ���ؼ� ����� ������

class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
	//Edit e;      // ��� ���� �Է� �޴� Edit
	NumEdit e;     // ���ڸ� �Է� �޴� Edit
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


