#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int m=4, n=3,s;
	int a[3][4] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 };
	_asm
	{
		mov ecx,0
		mov edi,0
		mov esi,0
		lea ebx,a
		_startFor1:
			cmp esi,n 
			jge _endFor1 //mai mare sau egal
			mov edi,0
			_startFor2:
			cmp edi,m
			jge _endFor2
			mov eax,m
			mul esi
			add eax,edi
			add ecx, [ebx+eax*4]
			inc edi
			jmp _startFor2
				_endFor2:
		inc esi
			jmp _startFor1
		_endFor1:
		mov s,ecx
	}
	cout << s << std::endl;
	return 0;
}