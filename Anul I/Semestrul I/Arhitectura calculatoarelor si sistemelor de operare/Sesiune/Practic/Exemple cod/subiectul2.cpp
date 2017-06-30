#include<iostream>
using namespace std;

struct rect
{
	int x, y;
	int width;
	int height;
};

int intersectie(rect* r1, rect* r2);

int main() {
	rect r1;
	rect r2;

	cin >> r1.x >> r1.y >> r1.width >> r1.height;
	cin >> r2.x >> r2.y >> r2.width >> r2.height;

	int result;

	//cout << intersectie(&r1, &r2) << '\n';
	_asm {
		lea eax, r1;
		lea ebx, r2;
		
		push ebx;
		push eax;
		call intersectie;
		add esp, 8;

		mov result, eax;
	}

	cout << result << '\n';

	return 0;
}

int intersectie(rect* r1, rect* r2) {
	_asm {
		mov esi, [ebp + 8];
		mov edi, [ebp + 12];

		;//eax = r1->w - r2->w
		mov eax, [esi + 8];
		sub eax, [edi + 8];

		;//ebx = r1->h - r2->h
		mov ebx, [esi + 12];
		sub ebx, [edi + 12];

		;// daca diferentele au semne diferite, e sigur imposibil.
		mov ecx, eax;
		mul ebx;
		cmp eax, 0;
		jl _return0;
		mov eax, ecx;

		;// facem esi exterior si edi interior.
		cmp eax, 0;
		;// ecx va retine id-ul maximului
		mov ecx, 1;
		jge _swapDone;
		
		;// swap esi & edi
		mov ecx, 2;
		push esi; push edi;
		pop esi; pop edi;
		;// negam diferentele (eax si ebx)
		mov edx, 0;
		sub edx, eax;
		mov eax, edx;
		mov edx, 0;
		sub edx, ebx;
		mov ebx, edx;
		
	_swapDone:
		;//salvam in stiva id-ul maximului
		push ecx;

		;// calculam deltaX si deltaY
		;// ecx = deltaX
		mov ecx, [esi];
		sub ecx, [edi];
		;// edx = deltaY
		mov edx, [esi + 4];
		sub edx, [edi + 4];
		
		;// atat dX cat si dY trebuie sa fie negative (x_exterior < x_interior)
		cmp ecx, 0;
		jg _cleanupReturn0;
		cmp edx, 0;
		jg _cleanupReturn0;
		
		;// daca dW + dX (negativ) >= 0, e ok
		add eax, ecx;
		cmp eax, 0;
		jl _cleanupReturn0;

		;// daca dH + dY (negativ) >= 0, e ok
		add ebx, edx;
		cmp ebx, 0;
		jl _cleanupReturn0;

		;// daca s-a ajuns aici, e ok, return id-ul maximului

		pop eax;
		jmp _return;

	_cleanupReturn0:
		;// dump the best id from the stack
		add esp, 4;
	_return0:
		mov eax, 0;
	_return:
	}
}
