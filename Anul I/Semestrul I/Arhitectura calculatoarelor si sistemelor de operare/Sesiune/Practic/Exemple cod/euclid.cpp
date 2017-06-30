#include<iostream>
using namespace std;

int main() {
	int a, b;
	int r;
	int result;

	cin >> a >> b;

	_asm {
		mov ebx, b;
		mov ecx, a;
		
		mov edx, 0;
		mov eax, ecx;
		div ebx;

	_startWhile:
		;compararea r = 0
		cmp edx, 0;
		je _endWhile;

		mov ecx, ebx;
		mov ebx, edx;
		
		mov edx, 0;
		mov eax, ecx;
		div ebx;

		jmp _startWhile;

	_endWhile:
		mov result, ebx;
	}

	cout << result << '\n';

	return 0;
}