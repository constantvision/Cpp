// 1_레퍼런스4.   100 page

int x = 0;
int foo()  { return x; } 

int main()
{
	int v1 = 10, v2 = 20;
	v1 = 20;
	v2 = v1;

//	foo() = 20; // ?
}
