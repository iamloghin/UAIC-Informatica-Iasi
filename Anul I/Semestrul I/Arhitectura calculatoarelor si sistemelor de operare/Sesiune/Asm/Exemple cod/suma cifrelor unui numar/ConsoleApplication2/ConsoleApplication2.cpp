#include <iostream>
using namespace std;

int suma( int a,int c)
{
  _asm
  {
	  mov ecx,[ebp+12]
	  mov ebx,0
	  mov eax,[ebp+8]
start_for:
	  cmp eax,0
	  je end_for
	  mov edx,0
	  div ecx
	  add ebx,edx
	  jmp start_for
end_for:
	  mov eax,ebx
  }
}
int main()
{
	int a,c=10;
	cin>>a;
	_asm
	{
	    push c
		push a
		call suma
		add esp,8
		mov a,eax
	}
	cout<<a<<endl;
}