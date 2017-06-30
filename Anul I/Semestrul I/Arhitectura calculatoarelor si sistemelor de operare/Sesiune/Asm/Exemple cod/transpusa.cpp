// asm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


bool transpusa(int a[][3],int n, int m){
	_asm{
	mov ebx,[ebp+8]
	mov esi,0
sfor1:cmp esi,[ebp+12]
	jae return1
	mov edi,0
sfor2:cmp edi,[ebp+16]
	jae efor2
	mov eax,[ebp+16]
	mul esi
	shl eax,2
	add eax,ebx
	mov ecx,[eax+edi*4] // aici avem a[i][j]
		mov eax,[ebp+16]
	mul edi
	shl edx,2
	add eax,ebx
	mov edx[eap+esi*4] /// aici avem a[j][i]
	cmp ecx,edx
	jne return0

	inc edi
	jmp sfor2
efor2:inc esi
	jmp sfor1

return1: mov eax,1

	return0:mov eax,0
	jmp efor1

efor1:



	}
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[3][3]={}
	_asm{
		push ebp
		call

	
	}
	return 0;
}

