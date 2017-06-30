#include<iostream>
using namespace std;

int ic(int *src1, int n1, int *src2, int n2, int* dest);

int main() {
	int src1[1000];
	int src2[1000];
	int dest[1000];

	int n1;
	int n2;

	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> src1[i];
	}

	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> src2[i];
	}

	int nD = ic(src1, n1, src2, n2, dest);
	cout << nD << '\n';
	for (int i = 0; i < nD; i++) {
		cout << dest[i] << ' ';
	}
	cout << '\n';

	return 0;
}

int ic(int* src1, int n1, int* src2, int n2, int* dest) {
	_asm {
		;// src1
		mov ebx, [ebp + 8];
		;// src2
		mov ecx, [ebp + 16];
		;// dest
		mov edx, [ebp + 24];

		;// i1
		mov esi, 0;
		;// i2
		mov edi, 0;

	_startFor:
		cmp esi, [ebp + 12];
		jge _endFor;
		cmp edi, [ebp + 20];
		jge _endFor;

		;// Comparam elementele curente.
		mov eax, [ebx + 4 * esi];
		cmp eax, [ecx + 4 * edi];
		jle _addFrom1;

		;// _addFrom2:
		;// Calculam in ebx indicele din destinatie.
		push ebx;
		mov ebx, esi;
		add ebx, edi;
		mov eax, [ecx + 4 * edi];
		mov [edx + 4 * ebx], eax;
		pop ebx;
		
		inc edi;
		jmp _startFor;

	_addFrom1:
		;// Calculam in ecx indicele din destinatie.
		push ecx;
		mov ecx, esi;
		add ecx, edi;
		mov eax, [ebx + 4 * esi];
		mov [edx + 4 * ecx], eax;
		pop ecx;

		inc esi;
		jmp _startFor;

	_endFor:

		cmp esi, [ebp + 12];
		jge _preDump2;

		;// Refolosim edi ca indice din destinatie.
		add edi, esi;
	_startDump1:
		cmp esi, [ebp + 12];
		jge _returnVal;

		mov eax, [ebx + 4 * esi];
		mov [edx + 4 * edi], eax;
		inc esi;
		inc edi;
		jmp _startDump1;

	_preDump2:
		;// Refolosim esi ca indice din destinatie.
		add esi, edi;
	_startDump2:
		cmp edi, [ebp + 20];
		jge _returnVal;

		mov eax, [ecx + 4 * edi];
		mov [edx + 4 * esi], eax;
		inc esi;
		inc edi;
		jmp _startDump2;

	_returnVal:
		;// Indicele de final e fie in esi, fie in edi.
		;// Este maximul dintre cele 2.
		cmp esi, edi;
		jge _returnEsi;

		;// _returnEdi;
		mov eax, edi;
		jmp _return;

	_returnEsi:
		mov eax, esi;
		
	_return:
	}
}
