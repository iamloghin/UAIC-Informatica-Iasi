// ACSO5-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
/*
struct test
{
	char x;
	int y;
	short z;
	int t;
}a;

void set_struct(test*a)
{
	_asm
	{
		mov eax,[ebp+8]
		mov byte ptr[eax],1
			mov dword ptr[eax+4],2
			mov word ptr[eax+8],3
			mov dword ptr[eax+12],4
	}



}

int main()
{
	set_struct(&a);
	cout<<a.x<<a.y<<a.z<<a.t;
	return 0;
}
*/

/*vector de puncte numarati acele puncte care sunt la distanta mai mica de 5 fata de origine*/

struct punct
{
	int x;
	int y;
}v[50];

/*int count(punct x[],int n)
{
	int k,m;
	m=n*4;
	_asm
	{
		mov ecx,0
		mov edi,0
		mov edx,[ebp+8]
start_for:
		cmp ecx,m
			jge exit_for
		mov esi,dword ptr[edx+ecx]
		mov ebx,dword ptr[edx+ecx+4]
		mov eax,esi
			mul esi
			mov esi,eax
		mov eax,ebx
			mul ebx
		add eax,esi
		cmp eax,25
		jge exit_if
		inc edi
exit_if:
		add ecx,4	
			jmp start_for
exit_for:

		mov k,edi
	}
	return k;
}

int main()
{
	int i,n,k;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>v[i].x>>v[i].y;
	
	k=count(v,n);

	cout<<k;
	return 0;


}
*/

int count(punct v[],int n)
{
	_asm
	{
		mov ebx,[ebp+8]
		mov ecx,0
			mov esi,0
start_for:
		cmp esi,[ebp+12]
		jge exit_for
		
		mov eax,dword ptr[ebx+esi*8+0]
		mul eax
		mov edi,eax
		mov eax,dword ptr[ebx+esi*8+4]
		mul eax
		add edi,eax
		cmp edi,25
		ja increment
		inc ecx
increment:
		inc esi
		jmp start_for
exit_for:
		mov eax,ecx
	}
}

int main()
{
	int i,n,k;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>v[i].x>>v[i].y;
	
	k=count(v,n);

	cout<<k;
	return 0;


}