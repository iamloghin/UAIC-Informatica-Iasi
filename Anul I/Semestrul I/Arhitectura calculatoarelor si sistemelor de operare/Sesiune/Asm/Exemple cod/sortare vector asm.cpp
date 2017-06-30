#include<iostream>
using namespace std;

void sortare(int v[], int n)
{
	_asm{
		mov ebx, [ebp + 8]
			mov esi, 1
		start_for1: cmp esi, [ebp + 12]
					jg exit_for1
					mov edi, esi
					inc edi
				start_for2 : cmp edi, [ebp+12]
							 jge exit_for2
							 mov ecx, [ebx + esi * 4]
							 mov edx, [ebx+edi*4]
							 cmp ecx, edx
							 jle increment
							 mov [ebx+esi*4], edx
							 mov[ebx+edi*4], ecx
						 increment : inc edi
									 jmp start_for2
								 exit_for2 : inc esi
											 jmp start_for1
										 exit_for1 :

	}
}
int main()
{
	int v[10] = { 0, 9, 3, 1, 7 }, n = 5, i;
	_asm
	{
		push n
			lea ebx, v
			push ebx
			call sortare
			add esp, 8
	}
	for (i = 0; i < 5; i++)
		cout << v[i] << ' ';
	cout << endl;
	return 0;

}

