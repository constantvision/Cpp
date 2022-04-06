#include <iostream>

#include <vector>
#include <list>
#include <deque> 

#include <set>	
#include <unordered_set> 

#include <map>			
#include <unordered_map>

#include <string>

int main()
{
	// set �Ѱ��� ��(Ű)�� ������ ����
	std::set<std::string> s = { "mon", "tue", "wed" };

	// map : key-value�� ���� ����
	std::map<std::string, std::string> m = { {"mon", "������"},
											 {"tue", "ȭ����"} };

	// 1. []�� ����
	m["mon"] = "������";

	// 2. �ݺ��ڷ� ����

	// 3. ��Ұ� �ִ��� Ȯ�� =? ����Լ��� �������ϴ�.
	//    C++20���� �߰��Ǿ����ϴ�.
	if (m.contains("mon")) // set���� �ֽ��ϴ�.
	{
	}

	set::set<int> s = { 1,2,1,2 }; // �ߺ��ȵ�
	std::multiplies<int> ms = { 1,2,1,2 }; // �ߺ� ���

	std::map<std::string, std::string> m2 = { {"mon", "������"},
											 {"tue", "ȭ����"} };

	// ����!! [] �����ڴ� Ű���� ���� ���
	// ���Ӱ� Ű���� ����� value�� ����Ʈ �����ڷ� �ʱ�ȭ �˴ϴ�.
	auto v = m2["wed"]; // �� ���� "wed" �� Ű������ value���� ����
						// value Ÿ���� ����Ʈ ������.

	// �׷���, ���� �ִ��� �˻��Ϸ��� ����� []�� �ϸ� �ȵ˴ϴ�.
	auto p = m2.find("wed"); // �� �ؾ� �մϴ�.

	if (p != m2.end())  // �̷��� �����ؾ� �մϴ�.
	{
	}

	// �׷���, contains()�� ������ ������ �������?
//	if (m2.contains("wed")) {}
}

// map : tree ���        => ���ĵǾ� ����. �˻� ���� (���ʿ��� ���� �Ǿ������� ���ĵ�)
// unordered_map : hash   => ���ľȵǾ� ����. �˻� �� ����.