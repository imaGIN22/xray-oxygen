// xrDebugger.cpp : [FX] Для микротестов всяких сторонних API аналогов функций X-Ray 1.6
#include "pch.h"
#include <iostream>

class Test
{
	int* A;
public:
	Test() 
	{ 
		A = new int[141]; 
	}

	~Test()
	{
		delete A;
	}
};

int main()
{
	Core._initialize("X-Ray Oxygen: Debugger", nullptr, true, "fsgame.ltx");

	Test A1;
	Test A2;

	Test **AA = new Test*[2];
	AA[0] = &A1;
	AA[1] = &A2;

	delete *AA;
	if (AA == nullptr)
		OutputDebugStringA("This is fine!");

	return 0;
}