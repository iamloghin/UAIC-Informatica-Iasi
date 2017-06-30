#include<iostream>
using namespace std;

struct Complex
{
	int r;
	int i;
};

void suma(Complex* r, Complex a, Complex b);

int main() {
	Complex rez;
	Complex a = { 2, 3 };
	Complex b = { 1, 1 };

	suma(&rez, a, b);

	cout << rez.r << ' ' << rez.i << '\n';

	return 0;
}

void suma(Complex* r, Complex a, Complex b) {
	_asm {
		mov ebx, [ebp + 8];

		mov ecx, [ebp + 12];
		mov edx, [ebp + 16];

		add ecx, [ebp + 20];
		add edx, [ebp + 24];

		mov [ebx], ecx;
		mov [ebx + 4], edx;
	}
}
