#include<iostream>
using namespace std;

int mirror(int val);

int main() {
	int nr;
	cin >> nr;
	int mirrored = mirror(nr);

	cout << "Original: " << nr << "\n";
	for (int i = 31; i >= 0; i--) {
		cout << ((nr & (1 << i)) == 0 ? '0' : '1');
	}
	cout << '\n';
	cout << "Mirrored: " << mirrored << "\n";
	for (int i = 31; i >= 0; i--) {
		cout <<((mirrored & (1 << i)) == 0 ? '0' : '1');
	}
	cout << '\n';

	return 0;
}

int mirror(int val) {
	_asm {
		mov eax, [ebp + 8];
		mov ebx, 2;
		mov ecx, 0;
		
	_startUnwindFor:
		cmp ecx, 32;
		je _endUnwindFor;

		mov edx, 0;
		;// Aparent nu se poate face div 2.
		div ebx;
		push edx;
		inc ecx;
		jmp _startUnwindFor;

	_endUnwindFor:

	_startWindFor:
		cmp ecx, 0;
		je _endWindFor;

		shl eax, 1;
		add eax, [esp + 4 * ecx - 4];

		dec ecx;
		jmp _startWindFor;

	_endWindFor:
		add esp, 4 * 32;
	}
}
