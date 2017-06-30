#include<iostream>
using namespace std;

struct line
{
	int x1, y1;
	int x2, y2;
};

int paralel(line* l, int n);

int main() {
	int n;
	line lines[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
	}

	cout << paralel(lines, n) << '\n';
	return 0;
}

int paralel(line* l, int n) {
	_asm {
		; ebx = l
		mov ebx, [ebp + 8];

		; if (n < 1) true
		cmp [ebp + 12], 1;
		jle _return1;

		; esi = y2 - y1
		mov esi, [ebx + 12];
		sub esi, [ebx + 4];
		; edi = x2 - x1
		mov edi, [ebx + 8];
		sub edi, [ebx];

		mov ecx, 1;
	_startFor1:
		cmp ecx, [ebp + 12];
		jge _return1;

		; edx = &l[i]
		mov edx, ecx;
		sal edx, 4;
		add edx, ebx;

		; push yb * (x2 - x2)
		mov eax, [edx + 8];
		sub eax, [edx];
		mul esi;
		push eax;

		; edx = &l[i]
		mov edx, ecx;
		sal edx, 4;
		add edx, ebx;

		; eax = xb * (y2 - y1);
		mov eax, [edx + 12];
		sub eax, [edx + 4];
		mul edi;

		; cmp pop, eax
		pop edx;
		cmp eax, edx;
		jne _return0;

		; increment for
		inc ecx;
		jmp _startFor1;

	_return0:
		mov eax, 0;
		jmp _return;
	_return1:
		mov eax, 1;
	_return:
	}
}