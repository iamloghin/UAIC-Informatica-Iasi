// ACSO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define MAX 100

int ic(int *src1, int n1, int *src2, int n2, int *dst);
int ic_C(int *src1, int n1, int *src2, int n2, int *dst);

int main()
{
	int src1[] = { 1,4,5,6,7,12 }, src2[] = { 1,2,3,8 }, dst[MAX];
	int n1 = 6, n2 = 4;
	int dimensiune = ic(src1, n1, src2, n2, dst);
	//int dimensiune = ic_C(src1, n1, src2, n2, dst);
	for (int i = 0; i < dimensiune; i++)
		cout << dst[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}

int ic(int *src1, int n1, int *src2, int n2, int *dst)
{
	_asm
	{
		xor ecx, ecx; // i=0;
		xor edx, edx; // j=0;
		xor edi, edi; // k=0;
					  // mov esi, src1; // src1 [EBP + 8]
					  // mov edx, src2; // src2 [EBP + 16]
					  // mov ebx, dst; // dst [EBP + 24]
	_while:
		cmp ecx, n1; // [EBP + 12]
		jge _nextif;
		cmp edx, n2; // [EBP + 20]
		jge _nextif;

		mov esi, src1; // *src1
		lea eax, [esi + ecx * 4]; // [src1+i*4]
		mov eax, [eax]; // src1[i]

		mov esi, src2; // *src2
		lea ebx, [esi + edx * 4]; // [src2+i*4]
		mov ebx, [ebx]; // src2[j]

		cmp eax, ebx; // cmp src1[i] & src2[j]
		mov esi, dst; // *dst
		jle _firstif; // if(src[i1] <= src[i2])

		mov[esi + edi * 4], ebx; // dst[k] = src2[j]

		inc edx; // j++
		inc edi; // k++
		jmp _while;

	_firstif: //if (src[i1] <= src[i2])
		mov[esi + edi * 4], eax; // dst[k] = src1[i]

		inc ecx; // i++
		inc edi; // k++
		jmp _while;

	_nextif: // out of while
		cmp ecx, n1; // if(i<n1)
		jge _nextif2; // daca conditia nu e indeplinita
		mov esi, dst; // *dst
		mov ebx, ecx; // j = i

	_fornextif: // for(int l = j; l<n2; l++)
		cmp ebx, n1; // l < n1
		jge _nextif2; // daca conditia nu e indeplinita
		
		mov esi, src1; // *src1
		
		push edx;
		lea edx, [esi + ebx * 4]; //src1[j]
		mov eax, [edx]; // eax = src1[j]
		
		mov esi, dst; // *dst
		mov [esi + edi * 4], eax; //dst[k] = src1[j]
		pop edx;

		inc ebx; // j++
		inc edi; // k++
		jmp _fornextif;

	_nextif2:
		cmp edx, n2; // if(j<n2)
		jge _end; // daca conditia nu e indeplinita
		mov esi, dst; // *dst
		mov ebx, edx; // j = i

	_fornextif2:
		cmp ebx, n2; // l < n2
		jge _end; // daca conditia nu e indeplinita
		
		mov esi, src2; // *src2

		push edx;
		lea edx, [esi + ebx * 4]; // src2[j]
		mov eax, [edx]; // eax = src1[j]

		mov esi, dst; // *dst
		mov [esi + edi * 4], eax; // dst[k]=src2[j]
		pop edx;

		inc ebx; // j++
		inc edi; // k++
		jmp _fornextif2;

	_end:
		mov eax, n1; // n1
		add eax, n2; // n1 + n2
	}
}

int ic_C(int *src1, int n1, int *src2, int n2, int *dst)
{
	int i = 0, j = 0, k = 0;
	while (i<n1 && j<n2)
		if (src1[i]<src2[j])
		{
			dst[k] = src1[i];
			k++;
			i++;
		}
		else
		{
			dst[k] = src2[j];
			k++;
			j++;
		}
	if (i<n1)
		for (int l = i; l<n1; l++)
		{
			dst[k] = src1[l];
			k++;
		}
	if (j<n2)
		for (int l = j; l<n2; l++)
		{
			dst[k] = src2[l];
			k++;
		}
	return n1 + n2;
}