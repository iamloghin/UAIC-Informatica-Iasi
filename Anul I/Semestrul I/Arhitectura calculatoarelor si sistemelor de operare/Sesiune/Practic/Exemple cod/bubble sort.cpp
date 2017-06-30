#include<iostream>
using namespace std;

int main() {
	int a[] = { 9, 2, 5, 1, 1, 9, 10 };
	int n = 7;
	int i;

	_asm {
		mov edx, n;
		dec edx;

		lea ebx, a;
		mov esi, 0;

	_startFor1:
		cmp esi, edx;
		jge _endFor1;

		mov edi, esi;
		inc edi;

	_startFor2:
		cmp edi, n;
		jge _endFor2;

		mov eax, [ebx + 4 * esi];
		cmp eax, [ebx + 4 * edi];
		jge _endIf;

		mov ecx, [ebx + 4 * edi];
		mov [ebx + 4 * edi], eax;
		mov [ebx + 4 * esi], ecx;

	_endIf:
		inc edi;
		jmp _startFor2;

	_endFor2:
		inc esi;
		jmp _startFor1;
	_endFor1:
	}

	for (i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}

	return 0;
}