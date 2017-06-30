// vector de puncte.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
// nr pct care sunt la distanta mai mica de 5 puncte de origine
#include<iostream>
using namespace std;
struct punct
{
	int x;
	int y; 
};
int count(punct v[], int n)
{
	int nr;
	_asm{
		mov ebx, [ebp+8]
			mov ecx, 0
			mov esi, 0
		start_for: cmp esi, [ebp + 12]
				   jge exit_for
				   mov eax, dword ptr[ebx+esi*8]
				   mul eax
				   mov edi, eax
				   mov eax, dword ptr[ebx+esi*8+4]
				   mul eax
				   add edi, eax
				   cmp edi, 25
				   ja increment
				   inc ecx
			   increment: inc esi
							  jmp start_for
							  exit_for: mov eax, ecx 
	}
}
/*int main()
{
	punct v[10];
	for (int i = 0; i<9; i++)
		v[i].x = v[i].y = i;
	int nr;
	nr=count(v, 10);
	cout << nr;
	return 0;

}*/
int main()
{
	punct v[10];
	int nr;
	for (int i = 0; i<9; i++)
		v[i].x = v[i].y = i;
	_asm{
		push 10
			lea ebx, v
			push ebx
			call count
			add esp, 8
			mov nr, eax 
	}
	cout << nr;
	return 0;
}
