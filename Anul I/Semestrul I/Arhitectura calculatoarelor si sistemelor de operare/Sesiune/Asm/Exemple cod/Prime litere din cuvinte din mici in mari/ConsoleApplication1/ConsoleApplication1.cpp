#include <iostream>
using namespace std;

void modificare(char a[])
{
	_asm
	{
		mov ebx,[ebp+8]
		mov al,[ebx]
		cmp  al,0
		je end_while
		cmp  al,'a'
		jl incrementare
		cmp  al,'z'
		ja incrementare
		sub [ebx],32
		inc ebx
start_while:
		mov al,[ebx]
		cmp  al,0
		je end_while
		cmp  al,'a'
		jl incrementare
		cmp  al,'z'
		ja incrementare
		cmp  [ebx-1],'A'
		jae incrementare
		sub  [ebx],32
incrementare:
		inc ebx
	    jmp start_while
end_while:
	}
}

int main()
{
	char a[]="asfka[sokf";
	int c;
	_asm
	{
		lea ebx,a
		push ebx
		call modificare
		add esp,4
	}
	c=0;
	while (a[c]!=NULL)
		{cout<<a[c];
	c++;}
	cout<<endl;


}