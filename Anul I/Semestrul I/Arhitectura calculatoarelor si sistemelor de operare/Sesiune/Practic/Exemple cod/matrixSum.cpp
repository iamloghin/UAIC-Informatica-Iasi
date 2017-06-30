#include<iostream>
using namespace std;

int suma(int a[3][3], int n, int m);
int prim(int n);

int a[3][3] = { {0, 0, 0}, {0, 1, 2}, {0, 0, 0} };

int main() {
	int result = suma(a, 3, 3);
	cout << result << '\n';

	int suma = 0;
	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 3; c++) {
			if (prim(a[l][c])) {
				suma += a[l][c];
			}
		}
	}
	cout << "should be " << suma << '\n';

	return 0;
}

int suma(int a[3][3], int n, int m) {
	_asm {
		mov ecx, 0;
		mov ebx, [ebp + 8];

		mov esi, 0;
	_startFor1:
		cmp esi, [ebp + 12];
		jge _endFor1;

		mov edi, 0;
	_startFor2:
		cmp edi, [ebp + 16];
		jge _endFor2;

		mov eax, [ebp + 12];
		mul esi;
		add eax, edi;
		mov edx, [ebx + eax * 4];

		push ebx;
		push ecx;
		push edx;

		push edx;
		call prim;
		add esp, 4;

		pop edx;
		pop ecx;
		pop ebx;

		cmp eax, 0;
		je _endPrime;
		add ecx, edx;

	_endPrime:
		inc edi;
		jmp _startFor2;
	_endFor2:
		inc esi;
		jmp _startFor1;
	_endFor1:
		mov eax, ecx;
	}
}


int prim(int n) {
	_asm {
		; if (n <= 1) return false;
		mov ecx, [ebp + 8];
		cmp ecx, 1;
		jle _ReturnNonprime;

		; if (n == 2) return true;
		cmp ecx, 2;
		je _ReturnPrime;

		; if (n % 2 == 0) return false;
		mov edx, 0;
		mov eax, ecx;
		mov ebx, 2;
		div ebx;
		cmp edx, 0;
		je _ReturnNonprime;

		; d = 3;
		mov ebx, 3;

		; while (d * d <= n)
			_While_start:
		mov eax, ebx;
		mul ebx;
		cmp eax, ecx;
		ja _ReturnPrime;

		; if (n % d == 0) return false;
		mov edx, 0;
		mov eax, ecx;
		div ebx;
		cmp edx, 0;
		je _ReturnNonprime;

		; d += 2
			add ebx, 2;
		jmp _While_start;

	_ReturnPrime:
		mov eax, 1;
		jmp _End;
	_ReturnNonprime:
		mov eax, 0;
	_End:
	};
}