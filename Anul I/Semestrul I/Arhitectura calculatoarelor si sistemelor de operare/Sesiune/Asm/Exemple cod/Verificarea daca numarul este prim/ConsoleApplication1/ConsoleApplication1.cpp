#include <iostream>
using namespace std;
int divizor(int d,int c)
{
	_asm
	{
		mov eax,[ebp+8]
		cmp eax,3
		jle nr_este_prim
		mov ecx,2
start_for:
		cmp ecx,[ebp+12]
		jg nr_este_prim
		mov eax,[ebp+8]
		mov edx,0
		div ecx
		cmp edx,0
		je nr_nu_este_prim
		cmp ecx,[ebp+12]
		jae nr_este_prim
		inc ecx
		jmp start_for
nr_este_prim:
		mov eax,0
		jmp end_function
nr_nu_este_prim:
		mov eax,1
end_function:		
	}
}


int main ()
{
	int d,c;
	cin>>d;
	c=d/2;
	_asm
	{
		push c
		push d
		call divizor
		add esp,8
		mov d,eax
	}
	if (d==1)
		cout<<"nr nu  este prim"<<endl;
	else
	cout<<"nr este prim"<<endl;
}