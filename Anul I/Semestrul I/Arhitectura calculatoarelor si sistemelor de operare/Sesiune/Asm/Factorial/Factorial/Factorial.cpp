// Factorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n,i,s;
	cin>>n;
	_asm {
	mov eax,1
	mov ecx,1
start_for:
	cmp ecx,n
	jg exit_for
	mul ecx
	inc ecx
	jmp start_for
exit_for:
    mov s,eax
	}
	cout<<"Suma este "<<s;
return 0;
}

