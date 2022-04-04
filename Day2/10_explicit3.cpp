#include <string>
#include <vector>

void f1(std::string s)      {}
void f2(std::vector<int> s) {}

int main()
{
	std::string s1("hello");
	std::string s2 = "hello"; 
	f1("hello");

	std::vector<int> v1(10); 
	std::vector<int> v2 = 10;
	f2(10);
}

