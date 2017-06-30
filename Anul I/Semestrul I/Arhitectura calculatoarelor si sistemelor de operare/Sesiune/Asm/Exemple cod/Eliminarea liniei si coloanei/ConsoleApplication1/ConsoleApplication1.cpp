#include <iostream>
using namespace std;

int suma(int m[][5],int n[][6],int a,int x,int y)
{
	_asm
	{
		mov edi,[ebp+8]
		mov esi,[ebp+16]
		mov bl,0
		mov bh,0
start_for1:
		cmp bl,[ebp+16]
		jae end_for1
		cmp bl,[ebp+20]
		je increment_linie_mare
        mov cl,0
		mov ch,0
start_for2:
		cmp cl,[ebp+16]
		jae end_for2
		cmp cl,[ebp+24]
		je increment_coloana_mare
		mov al,[ebp+16]
		mul bl
        add al,cl
		mov edx,[esi+eax*4]
		mov al,([ebp+16]-1)
		push edx
		mul bh
        add al,ch
		pop edx
		mov [edi+eax*4],edx
		cmp cl,[ebp+16]
		je end_for2
increment_coloana_mare:
		inc cl
		cmp cl,[ebp+24]
		je start_for2
		inc ch
		jmp start_for2
end_for2:
		cmp bl,[ebp+16]
		jae end_for1
increment_linie_mare:
		inc bl
		cmp bl,[ebp+20]
		je start_for1
		inc bh
		jmp start_for2
end_for1:

	}
}

int main()
{
	int m[2][2],i,j,a=2,n[3][3],x,y;

	for (i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>n[i][j];
		}
	}
	cin>>x;
	cin>>y;
	_asm
	{
		push y
		push x
		push a
		lea ecx,n
		push ecx
		lea ebx,m
        push ebx
		call suma
		add esp,20
	}
		for (i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			cout<<m[i][j];
		}
	}
}