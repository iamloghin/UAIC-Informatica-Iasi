#include<iostream>
using namespace std;

struct charFreq
{
	char ch;
	int freq;
};

void countChars(char* str, charFreq* freqs);

int main() {
	char str[1000] = "So, how's it going?";
	charFreq freqs[128] = {};
	
	_asm {
		lea eax, str;
		lea ebx, freqs;

		push ebx;
		push eax;
		call countChars;
		add esp, 8;
	}

	for (int i = 0; i < 128 && freqs[i].ch != '\0'; i++) {
		cout << '\'' << freqs[i].ch << "', " << freqs[i].freq << " times." << '\n';
	}

	return 0;
}

void countChars(char* str, charFreq* freqs) {
	_asm {
		mov ebx, [ebp + 8];
		mov edx, [ebp + 12];

	_startForCh:
		cmp byte ptr [ebx], 0;
		je _endForCh;

		mov al, [ebx];

		mov ecx, edx;
	_startForFreq:
		cmp byte ptr [ecx], al;
		je _freqFound;
		;// Presupunem ca vectorul de frecvente e intializat cu toate caracterele pe '\0'
		cmp byte ptr [ecx], 0;
		je _freqNotFound;

		add ecx, 8;
		jmp _startForFreq;

	_freqNotFound:
		mov byte ptr [ecx], al;
		mov [ecx + 4], 0;
	_freqFound:
		inc [ecx + 4];

		inc ebx;
		jmp _startForCh;
		
	_endForCh:
	}
}
