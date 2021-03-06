// xrDebugger.cpp : [FX] Для микротестов всяких сторонних API аналогов функций X-Ray 1.6
//					[FX] For testing external APIs

#include "pch.h"
#include <iostream>
#include <DirectXMath.h>
#include "../xrEngine/DirectXMathExternal.h"

int main()
{
	Core._initialize("X-Ray Oxygen: Debugger", nullptr, true, "fsgame.ltx");

	Fmatrix TestMatrix;
	TestMatrix.identity();

	// Тадам!
	TestMatrix._13 = 12.f;

	std::cout << TestMatrix._23 << " " << TestMatrix.k.z;

	// #DARK: Always _destroy() xrCore!
	Core._destroy();
}
