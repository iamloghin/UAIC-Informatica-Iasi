// sirul lui fibonacci recursiv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
#include"stdafx.h"
#include<iostream>
using namespace std;
/*int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}*/
int fib(char n)
{
	
	_asm
	{
		movsx ebx, [ebp + 8];
		cmp ebx, 1;
		je if_true;
		cmp ebx, 2;
		jne if_false;
	if_true:
		mov eax, 1;
		jmp end_function;
	if_false:
		sub ebx, 1;
		push ebx;
		call fib;
		add esp, 4;
		push eax;
		sub ebx, 1;
		push ebx;
		call fib;
		add esp, 4;
		pop ecx;
		add eax, ecx;

	end_function:
	}
}

int main()
{
	int f=fib(5);
	cout << f;
	return 0;
}

