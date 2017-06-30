// suma numerelor prime dintr-un vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
#include<iostream>
using namespace std;
/*int prim(int n)
{
	for(int i = 2; i <= n / 2;i++)
	if (n%i == 0)
		return 0;
	return 1;
}
int suma(int v[], int n)
{
	int s = 0;
	for (int i = 0; i < n;i++)
	if (prim(v[i]))
		s = s + v[i];
	return s;
}
int main()
{
	int v[] = { 0, 2, 3, 6, 7, 4 }, s;
	s = suma(v, 6);
	cout << s;
	return 0;
}*/
int prim(int n)
{
	_asm{
		mov ebx, [ebp+8]
			sar ebx, 1
			mov esi, 2
		start_for_prim: cmp esi, ebx
							jg exit_for_prim
							mov edx, 0
							mov eax, [ebp + 8]
							div esi
							cmp edx, 0
							jne increment
							mov eax, 0
							jmp exit_f
						increment: inc esi
								   jmp start_for_prim
							   exit_for_prim: mov eax, 1
													  exit_f:
	}
}
int suma(int v[], int n)
{
	_asm{
		mov ebx, [ebp+8]
			mov ecx, 0
			mov edi, 0
		start_for: cmp edi, [ebp+12]
					   jge exit_for
					   mov edx, [ebx+edi*4]
					   push ebx
					   push ecx
					   push edx
					   call prim
					   
					   pop edx
					   pop ecx
					   pop ebx
					   cmp eax, 1
					   jne increment
					   add ecx, edx
					   jmp increment
				   increment: inc edi
								  jmp start_for
								  exit_for: mov eax, ecx
	}
}
int main()
{
	int v[] = { 0, 2, 3, 6, 7, 4 }, s;
	_asm{
		
		lea ebx, v
			push 6
			push ebx
			call suma
			add esp, 8
			mov s, eax
	}
	cout << s;
	return 0;

}
