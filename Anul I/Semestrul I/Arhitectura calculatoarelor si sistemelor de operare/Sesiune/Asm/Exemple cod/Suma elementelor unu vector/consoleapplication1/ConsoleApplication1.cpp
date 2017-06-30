#include <iostream>
using namespace std;

int suma(int a[],int b)
{
	_asm
	{
		mov ebx,[ebp+8]
		mov ecx,0
	    mov eax,0
start_for:
		cmp ecx,[ebp+12]
		jae end_for
		mov edx,dword ptr[ebx+ecx*4]
		add eax,edx
		inc ecx
	    jmp start_for
end_for:

	}

}

int main()
{
	int a[50],i,b;
	cout<<"Introduceti nr de elemente(pana la 50)";
	cin>>b;
	for (i=0;i<b;i++)
	{cin>>a[i];}
	_asm
	{
		push b
		lea ebx,a
        push ebx
		call suma
		add esp,8
		mov b,eax
	}
	cout<<b;
}