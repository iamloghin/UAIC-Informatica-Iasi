// ASM and Chill.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
const char *c = "%d";

/*
### Registri
	eax adunare (aici se intampla operatiile)
	ebx baza index
	ecx contor
	edx extensie pentru eax

|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
                                {     8biti     |     8biti     }
										ah			    al
								{     		 16biti		    	}
												ax
{							 32biti								}
							   eax

### Pointers
	EIP instruction pointer
	ESP stack pointer
	ESI string counter, string index source
	EDI string index destiantion
	EBP base ponter

### EFLAGS
	|_|_|_|_|_|_|_|_|...|__|
	 0 1 2 3 4 5 6 7     32

	0 carry pentru overflow
	1 rezervat
	2 numarul bitilor de 1 %2
	3 rezervat
	4 daca adunarea in BCD da overflow
	6 zero flag

### Comenzi
	push eax -adauga in stack
	pop eax -scoate de pe stack
	mov target, source -muta
	add target, value -adauga
	inc target -target++
	sub target, value -scade
	dec target -target--
	mul value - inmulteste EAX cu value
	cmp v1, v2 -compara v1 cu v2 (mandatoriu inainte de orice jump if...)
	jmp target -sare la comanda target
	je target, value - jump if eax equal to value
	jle target, value - jump if eax lower than value
	jge target, value - jump if eax higher than value

### Operatii logice

	and
	or
	not
	xor
	nor
	nand
	shl reg, val -muta bitii la stanga de val ori
	shr reg, val -muta bitii la dreapta de val ori
	rol reg, val -muta bitii la stanga de val ori, se reia de la capat
	ror reg, val -muta bitii la dreapta de val ori, se reia de la capat
*/

void Suma(int a, int b)
{
	_asm
	{
		mov eax, a
		mov ebx, b
		add eax, ebx
		mov a, eax
	}
	cout << a;
}
void XLaPuterea2(int a)
{
	_asm
	{
		mov eax, a
		mul eax
		mov a, eax
	}
	cout << a;
}
void DoiLaPutereaX(int a)
{
	_asm
	{
		mov eax, 2
		mov ecx, 1

		multiply:
			mov ebx, a
			cmp ecx, ebx
			jge finish
			mov ebx, 2
			mul ebx
			inc ecx
			jmp multiply
		finish:
			mov a, eax
			xor eax, eax
	}
	cout << a;
}
void InmultirePeBazaAdunarii(int a,int b)
{
	_asm
	{
		mov eax, a
		mov ebx, b
		mov ecx, 0
		cond :
			cmp ecx, ebx  //compara contorul cu b
			jge finish // daca comparatia returneaza adevarat, sare la finish
			add eax, a
			inc ecx
			jmp cond
		finish :
			mov a, eax
			xor eax, eax

	}
	cout << a;
}
void AfisareaUnuiElmDinUnVector(int *p, int i)
{
	int a;
	_asm
	{
		mov edx, 4 //int e pe 4 biti, deci trebuie sa stim ca e 4*indexul
		mov ebx, p;
		mov eax, i;
		mul edx //se inmulteste indexul cu 4
		add ebx, eax
		mov eax, [ebx]
		push eax //se adauga pe stiva variabilele pentru functia printf
		push c //printf(c,eax)
		call printf //printf("%d",a)
		pop ebx //se scot de pe stiva dupa executare
		pop ebx //nu conteaza parametrul la pop
	}
}
void InmultireaUnuiVectorCuOConstanta(int *p, int l, int val)
{
	int i = 0;
	_asm
	{
		multiply:
			mov ecx, i
			cmp ecx, l
			jge finish
			mov eax, p
			mul val
			push eax
			push c
			call printf
			pop eax
			pop eax
			inc i
			add p, 4
			jmp multiply

		finish:
			mov l, eax
			xor eax, eax
			
	}
}
int ic(int *src1, int n1, int *src2, int n2, int *dst)
{
	int i=0;
	_asm
	{
		whileloop:
			cmp n1, 0
			jg f1
			cmp n1, 0
			jle f5
			jmp whileloop


		f1:
			cmp n2, 0
			jg f2
			cmp n2, 0
			jle f3

		f2:
			mov eax, src1
			mov ebx, src2
			cmp eax, ebx
			jge f3
			cmp eax, ebx
			jl f4

		f3:
			mov ecx, dst
			mov ecx, [eax]
			inc dst
			inc src1
			dec n1
			inc i

		f4:
			mov ecx, dst
			mov ecx, [ebx]
			inc dst
			inc src2
			dec n2
			inc i

		f5:
			cmp n2, 0
			jg f4
			cmp n2, 0
			jle finish

		finish:
			xor eax, eax
	}
	return i;
}
int a(int *src1, int n1, int *src2, int n2, int *dst)
{
	bool done = false;
	while (!done)
	{
		if (n1 > 0 && n2 > 0)
		{
			if (*src1 < *src2)
			{
				*dst = *src1;
				dst++;
				src1++;
				n1--;
			}
			else
			{
				*dst = *src2;
				dst++;
				src2++;
				n2--;
			}
		}
		else if (n1 > 0)
		{
			*dst = *src1;
			dst++;
			src1++;
			n1--;
		}

		else if (n2 > 0)
		{
			*dst = *src2;
			dst++;
			src2++;
			n2--;
		}
		else
		{
			done = true;
		}
	}
	return 0;
}

int main2()
{
	int v1[] = { 2,4,7,10 };
	int v2[] = { 1,3,8,24 };
	int v3[20];
	ic(v1, 4, v2, 4, v3);
	for (int i = 0; i < sizeof(v3) / sizeof(int); i++)
	{
		cout << v3[i] << " ";
	}
	return 0;
}

int main()
{
	int *p, i,v[10],n;
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		cin >> v[j];
	}
	p = v;
	cin >> i;
	InmultireaUnuiVectorCuOConstanta(p, n, i);
    return 0;
}

