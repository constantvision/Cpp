// Stack.cpp
#include "Stack.h"

Stack::Stack(int size /* = 10 */)
{
	idx = 0;
	buff = new int[size];
}

Stack::~Stack()
{
	delete[] buff;
}

void Stack::push(int value)
{
	buff[idx++] = value;
}

int Stack::pop()
{
	return buff[--idx];
}