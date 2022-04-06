#include <iostream>

class Point
{
	int x, y;
public:
	Point()             { x = 0; y = 0; std::cout << "Point()" << std::endl; }
	Point(int a, int b) { x = a; y = b; std::cout << "Point(int, int)" << std::endl; }
};

int main()
{
	Point pt1;			
	Point pt2(0, 0);	
	Point pt3{ 0, 0 };	
						
	Point pt4 = { 0, 0 }; 
	Point arr[5]; 

	Point arr2[5] = { Point(0,0), {1,1} };

	Point* p;

	p = (Point*)malloc(sizeof(Point));  
	free(p);

	p = new Point;  
	delete p;

	p = new Point(1, 1); 
	delete p;
}


