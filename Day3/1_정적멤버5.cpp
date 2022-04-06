// 파일 분할
class Car
{
	int color;
	static int cnt;

public:
	Car();
	~Car(); 

	static int get_count();

};

// Car.cpp
#include "Car.h"
int Car::cnt = 0;

Car::Car() { ++cnt; }
Car::~Car() { --cnt; }

// Static 멤버 함수를 외부에 구현시 "static"은 표기 안함
int Car::get_count()
{
	return cnt;
}


