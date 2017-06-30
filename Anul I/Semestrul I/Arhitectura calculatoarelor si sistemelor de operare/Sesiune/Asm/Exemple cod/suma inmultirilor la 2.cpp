#include <iostream>
using namespace std;
int test=0, n, rez;

int suma(int n){
	_asm{
		mov ebx, 2 //s
		mov ecx, 2 //term
		mov eax, 2 //term
		mov esi, 1
_for:
		cmp esi, n
		je _endfor
		add ecx, 2
		mul ecx
		add ebx,eax
		inc esi
		jmp _for
_endfor:
		mov eax,ebx
	}
}

int main(){
	cin>>n;
	_asm{
		push n
		call suma
		add esp, 4
		mov rez, eax
	}
	cout<<rez<<endl;
}