#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ��� - Edit 2�� ����
// 2. ���ϴ� ���� �ٸ� Ŭ������ - Edit 3�� ����

// ��ü �����Ϸ��� �������̽� ����� ������ �� �������̽��� ��ӹ޾Ƽ� ������ ��

// Validation ��å�� ���� Ŭ������ �����Ѵ�.
// ��ü �����ؾ� �ϹǷ� �������̽��� ���� ���� �Ѵ�.

// ��� Validation ��å�� �Ʒ� �������̽�(�߻�Ŭ����)�� �����ؾ� �Ѵ�.

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

// �ֹ� ��� ��ȣ : 801	1	Ȯ��

class Edit
{
	std::string data;
	//---------------------------------
	IValidator* pval = nullptr;
public:
	void setValidator(IValidator* p) { pval = p; }
	//--------------------------------

	std::string getData()
	{
		data.clear();
		while (1)
		{
			char c = _getch(); // �� ���� �Է�

			if (c == 13 && (pval == nullptr || pval->iscomplete(data))) // iscomplete �⺻ ������ true�̸� value ���� ���� ���� �Է¹޾Ƶ� ������
				break;

			//if (isdigit(c))
			// pval�� ������ �� �Է� �ްڴ�
			if (pval == nullptr || pval->validate(data,c)) // ��ȿ�� ���θ� �ܺο� �����Ѵ�.
			{
				std::cout << c;     // ȭ�� ��� ��
				data.push_back(c);  // ���ڿ��� �߰�
			}
		}
		std::cout << std::endl;

		return data;
	}
};

// 1. Edit�� �⺻������ ��� �Է��� ����մϴ�.
// 2. �Է°��� Validation ��å�� �����Ϸ���
//    Validation ��å�� ���� �پ��� Ŭ������ �����ϸ� �˴ϴ�.

class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int n) : value(n) {}

	bool validate(const std::string& s, char c) override
	{
		if (s.size() < value && isdigit(c))
			return true;
	
		return false;
	}

	bool iscomplete(const std::string& s) override
	{
		return s.size() == value;
	}
};

// ���� "LimitDigitValidator"�� ���� "�پ��� Validation ��å�� ���� Ŭ������
// �����ϸ� ��
// 1. �̸��� ��ĢȮ��, �ֹι�ȣ Ȯ��, ��������, ��ȭ��ȣ ���� �� ..

int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.setValidator(&v); // ���� �Է� �޴µ� 5�ڸ� ������ ����

	// ���ο� ��å
	LimitDigitValidator v2(15);
	e.setValidator(&v2);
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


