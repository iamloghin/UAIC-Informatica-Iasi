#include "stdafx.h"
struct complex
{
	int r;
	int i;
};
void suma(complex* r, complex a, complex b)
{
	_asm
	{
		mov ebx, [ebp+8]
		mov eax, [ebp+12]
		add eax, [ebp+20]
		mov edx, [ebp+16]
		add edx, [ebp+24]
		mov[ebx],eax
		mov[ebx+4],edx
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	complex a, b, c;
	a.i = 3;
	a.r = 5;
	b.i = 6;
	b.r = 10;
	suma(&c, a, b);
	printf("%d + %di\n", c.r, c.i);
	return 0;
}
