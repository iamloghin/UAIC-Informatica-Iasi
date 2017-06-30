#include <iostream>
using namespace std;

int suma_div(int a,int b)
{
	_asm
	{
	mov ebx,0
	mov eax,[ebp+8]
	cmp eax,3
	jle end_for
	mov ecx,2
start_for:
	mov eax,[ebp+8]
	mov edx,0
	div ecx
	cmp edx,0
	jne incrementare
	add ebx,ecx
incrementare:
	inc ecx
	cmp ecx,[ebp+12]
	jg end_for
	jmp start_for
end_for:
	mov eax,ebx
	}
}

int main()
{
	int a,b;
	cin>>a;
	b=a/2;
	_asm
	{
		push b
		push a
		call suma_div
		add esp,8
		mov a,eax
	}
	cout<<a;

}
