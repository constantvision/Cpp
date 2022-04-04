// const_cast : 

int main()
{
	const int c = 10;

	int* p1 = &c;       // ?
	int* p2 = (int*)&c; // ?

}
