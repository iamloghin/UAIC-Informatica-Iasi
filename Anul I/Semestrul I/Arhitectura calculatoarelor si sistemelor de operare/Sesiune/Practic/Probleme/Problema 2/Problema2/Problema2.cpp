// Problema2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct rect
{
	int x, y; // coordonatele coltului din stanga jos
	int width; // latime
	int height; // inaltime
};

int intersectie(rect *r1, rect *r2); // 2 - drpt r2 inclus in r1, 1 - drpt r1 inclus in r2, 0 - nici unu
int intersectie_C(rect *r1, rect *r2);

int main()
{
	rect r1, r2;
	r1.x = 0, r1.y = 0, r1.width = 10, r1.height = 5;
	r2.x = 0, r2.y = 0, r2.width = 5, r2.height = 2;
	int rezultat = intersectie(&r1, &r2);
	//int rezultat = intersectie_C(&r1, &r2);
	cout << rezultat << endl;
	system("pause");
    return 0;
}

int intersectie(rect *r1, rect *r2)
{
	_asm
	{
	_if1:
		mov esi, r2; // *r2
		mov eax, [esi]; // r2.x
		mov esi, r1; // r1
		mov ebx, [esi + 8]; // r1.width

		cmp eax, ebx;
		jge _if2; // r2.x >= r1.width

		mov esi, r2; // *r2
		mov eax, [esi + 4]; // r2.y
		mov esi, r1; // *r1
		mov ebx, [esi + 12]; // r1.height

		cmp eax, ebx;
		jge _if2; // r2.y >= r1.height

		mov esi, r2; // *r2
		mov eax, [esi]; // r2.x
		mov esi, r2; // *r2
		mov ebx, [esi + 8]; // r2.width

		add eax, ebx; // r2.x+r2.width

		mov esi, r1; // *r1
		mov ecx, [esi + 8]; // r1.width

		cmp eax, ecx;
		jg _if2; // r2.x+r2.width > r1.width

		mov esi, r2; // *r2
		mov eax, [esi + 4]; // r2.y

		mov esi, r2; // *r2
		mov ebx, [esi + 12]; // r2.height

		add eax, ebx; // r2.y+r2.height

		mov esi, r1; // *r1
		mov ecx, [esi + 12]; // r1.height

		cmp eax, ecx;
		jg _if2; // r2.y+r2.height > r1.height

		mov ebx, 2; // return 2
		jmp _end;

	_if2:
		mov esi, r1; // *r1
		mov eax, [esi]; // r1.x
		mov esi, r2; // r2
		mov ebx, [esi + 8]; // r2.width

		cmp eax, ebx;
		jge _else; // r1.x >= r2.width

		mov esi, r1; // *r1
		mov eax, [esi + 4]; // r1.y
		mov esi, r2; // *r2
		mov ebx, [esi + 12]; // r2.height

		cmp eax, ebx;
		jge _else; // r1.y >= r2.height

		mov esi, r1; // *r1
		mov eax, [esi]; // r1.x
		mov esi, r1; // *r1
		mov ebx, [esi + 8]; // r1.width

		add eax, ebx; // r1.x+r1.width

		mov esi, r2; // *r2
		mov ecx, [esi + 8]; // r2.width

		cmp eax, ecx;
		jg _else; // r1.x+r1.width > r2.width

		mov esi, r1; // *r1
		mov eax, [esi + 4]; // r1.y

		mov esi, r1; // *r1
		mov ebx, [esi + 12]; // r1.height

		add eax, ebx; // r1.y+r1.height

		mov esi, r2; // *r2
		mov ecx, [esi + 12]; // r2.height

		cmp eax, ecx;
		jg _else; // r1.y+r1.height > r2.height

		mov ebx, 1; // return 1
		jmp _end;

	_else:
		mov ebx, 0; // return 0

	_end:
		mov eax, ebx;
	}
}

int intersectie_C(rect *r1, rect *r2)
{
	if (r2->x<r1->width && r2->y<r1->height && r2->x + r2->width <= r1->width && r2->y + r2->height <= r1->height)
		return 2;
	else if (r1->x<r2->width && r1->y<r2->height && r1->x + r1->width <= r2->width && r1->y + r1->height <= r2->height)
		return 1;
	else return 0;
}