#include<cstdio>
int suma(int a[3][4], int n, int m);



int main() {
	const int n = 3;
	const int m = 4;
	int a[3][4] = { {0, 1, 2, 3}, {-3, -2, -1, 0}, {1, -1, 2, 1} };

	int s;
	_asm{
		push m;
		push n;
		lea ebx, a;
		push ebx;
		call suma;
		add esp, 12;
		mov s, eax;
	}

	printf("%d\n", s);

	return 0;
}

int suma(int a[3][4], int n, int m) {

	_asm {
		mov ebx, [ebp + 8];
		mov ecx, 0;
		mov esi, 0;

	_startFor1:
		cmp esi, [ebp + 12];
		jge _endFor1;

		mov edi, 0;
	_startFor2:
		cmp edi, [ebp + 16];
		jge _endFor2;

		mov eax, m;
		mul esi;
		add eax, edi;
		add ecx, [ebx + eax * 4];

		inc edi;
		jmp _startFor2;
	_endFor2:
		inc esi;
		jmp _startFor1;
	_endFor1:

		mov eax, ecx;
	}
}