// ACSO 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
/*
void transform(char* s)
{
	bool sepfound=true;
	int j,i=0;
	while(s[i]!=0)
	{
		if(s[i]==' '||s[i]==',')
		{
			sepfound=true;
			i++;
			continue;
		}
		if(sepfound)
			if(s[i]>='a'&&s[i]<='z')
			{
				sepfound=false;
				s[i]-=32;
			}
	i++;
	}

}

int main()
{
	char s[256];
	cin.get(s,256);
	cin.get();
	transform(s);
	cout<<s;
	return 0;
}
*/

/*
void Transform(char *s)
{
	_asm{
			mov ebx,[ebp+8]
			mov ecx,0
			mov ah,1
start_while:
			mov al,byte ptr[ebx+ecx]
			cmp al,0
				je exit_while
			cmp al,' '
			je separator
			cmp al,','
			je separator
				jmp not_separator
separator:
			mov ah,1
not_separator:
			cmp ah,1
				jne increment
			cmp al,'a'
			jl increment
			cmp al,'z'
			jg increment
			mov ah,0
			sub al,32
			mov byte ptr[ebx+ecx],al
increment:
			inc ecx
				jmp start_while
exit_while:




		}

}

int main()
{
	char s[256];
	cin.get(s,256);
	cin.get();
	Transform(s);
	cout<<s;
	return 0;
}
*/

int reuniune(int*a,int n,int*b,int m,int *r)
{
	_asm
	{
		mov esi,0
			mov ebx,[ebp+8]
			mov ecx,[ebp+24]
start_for:
			cmp esi,[ebp+12]
			jge exit_for
			mov eax,[ebx+esi*4]
			mov [ecx+esi*4],eax
			inc esi
			jmp start_for
exit_for:
			mov eax,[ebp+12]
			mov esi,0
			mov ebx,[ebp+16]
			mov ecx,[ebp+8]
start_for1:
			cmp esi,[ebp+20]
			jae  exit_for1
				mov edx,1
				mov edi,0
start_for2:
			cmp edi,[epb+12]
			jge exit_for2
				push eax
				mov eax,[ebx+esi*4]
				cmp eax,[ecx+esi*4]
				jne sfarsit_if
					mov edx,0
sfarsit_if:
				pop eax
					pop eax
				inc edi
				jmp start_for2
exit_for2:
				cmp edx,1
					jne inc_f1
					push ecx
					push edi
				mov ecx,[ebp+24]
				mov edi,[ebx+esi*4]
				mov [ecx+eax*4],edi
					pop edi
					pop ecx
inc_for1:
				inc esi
					jmp start_for1
exit_for1:
	}
}

int main()
{

}

/*matrice sa returnam indexul coloanei cu produs maxim*/