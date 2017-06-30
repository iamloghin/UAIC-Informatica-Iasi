#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool result;

	_asm {
		; if (n <= 1) return false;
		mov ecx, n;
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

		; while(d * d <= n) 
	_While_start:
		mov eax, ebx;
		mul ebx;
		cmp eax, ecx;
		ja _ReturnPrime;
		
		; This works only the first time, with d = 3; it fails at or over n = 11;
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
		mov result, 1;
		jmp _End;
	_ReturnNonprime:
		mov result, 0;
	_End:
	};

	cout << result << '\n';

	return 0;
}