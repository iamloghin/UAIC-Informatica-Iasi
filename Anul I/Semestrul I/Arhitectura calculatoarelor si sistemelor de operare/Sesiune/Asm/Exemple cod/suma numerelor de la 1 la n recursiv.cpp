#include<iostream>
using namespace std;

int suma(int n)
{
	_asm{
		mov ebx, [ebp + 8]
		cmp ebx, 1
		jne else
		mov eax, 1
		jmp end_function
	else:
		sub ebx, 1
		push ebx
		call suma
		add esp, 4
		add eax, [ebp + 8]
	end_function:
	}
}
int main()
{
	int n,s;
	cin >> n;
	_asm{
		push n
			call suma
			add esp, 4
			mov s, eax 
	}
	cout << s;
	return 0;
}

