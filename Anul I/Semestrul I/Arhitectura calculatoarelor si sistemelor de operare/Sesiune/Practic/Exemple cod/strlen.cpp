#include<iostream>
using namespace std;

int main() {
	char s[256];
	cin.getline(s, 255);
	int len;

	_asm {
		lea ebx, s;
		mov ecx, 0;

	_startWhile:
		cmp byte ptr[ebx], 0;
		je _endWhile;

		inc ebx;
		inc ecx;
		jmp _startWhile;

	_endWhile:
		mov len, ecx;
	}

	cout << len << '\n';

	return 0;
}