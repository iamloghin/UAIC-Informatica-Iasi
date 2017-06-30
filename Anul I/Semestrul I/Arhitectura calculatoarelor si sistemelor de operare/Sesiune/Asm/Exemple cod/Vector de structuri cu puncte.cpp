#include "stdafx.h"
#include<iostream>
using namespace std;

struct punct
{
	int x;
	int y;
}v[100];

int count(punct v[], int n)
{
	_asm 
	{
		mov ebx, [ebp+8]
		mov ecx, 0
		mov esi, 0
	start_for:
		cmp esi, [ebp+12]
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
		increment:
		inc esi
			jmp start_for
		exit_for:
		mov eax, ecx
	}
}

int main()
{
	int n, i;
	cout << "introduceti nr de pucte";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "x["<<i<<"]=";
		cin >> v[i].x;
		cout << "y["<<i<<"]=";
		cin >> v[i].y;
	}
	cout << "nr de puncte aflate la o distanta mai mica decat 5 fata de origine este:" << count(v, n);
	return 0;
}

