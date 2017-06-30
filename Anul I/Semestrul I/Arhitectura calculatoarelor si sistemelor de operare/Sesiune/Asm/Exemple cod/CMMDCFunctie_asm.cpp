// CMMDCFunctie_asm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int CelMaiMare(int a, int b)
{
	_asm
	{
		mov eax, [ebp+8]
		mov ebx, [ebp+12]
		mov edx, 0
		div ebx
	start_while:
		cmp edx, 0
		je end_while
		mov eax, ebx
		mov ebx, edx
		mov edx, 0
		div ebx
		jmp start_while
	end_while:
		mov eax, ebx
	}
}

int main()
{
	int a, b, cmmdc;
	cin >> a >> b;
	_asm
	{
		push b
		push a
		call CelMaiMare
		add esp, 8
		mov cmmdc, eax
	}
	cout << cmmdc;
	return 0;
}

