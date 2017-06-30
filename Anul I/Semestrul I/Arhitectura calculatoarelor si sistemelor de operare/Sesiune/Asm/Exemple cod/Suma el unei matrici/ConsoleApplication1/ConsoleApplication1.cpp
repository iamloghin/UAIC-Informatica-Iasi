#include <iostream>
using namespace std;

int suma(int m[][10],int a,int b)
{
	_asm
	{
		mov ebx,[ebp+8]
		mov edi,0
		mov ecx,0
start_for1:
		cmp ecx,([ebp+12]-1)
		je end_for1
		mov esi,0
start_for2:
		cmp esi,([ebp+16]-1)
		ja end_for2
		mov eax,([ebp+16]-1)
		mul ecx
		add eax,esi
		add edi,dword ptr[ebx+eax*4]
		inc esi
	    jmp start_for2
end_for2:
		inc ecx
		jmp start_for1
end_for1:
		mov eax,edi
	}
}

int main()
{
	int m[2][2],i,j,a=2,b=2;

	for (i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			cin>>m[i][j];
		}
	}
	_asm
	{
		push b
		push a
		lea ebx,m
        push ebx
		call suma
		add esp,12
		mov i,eax
	}
	cout<<i;
}