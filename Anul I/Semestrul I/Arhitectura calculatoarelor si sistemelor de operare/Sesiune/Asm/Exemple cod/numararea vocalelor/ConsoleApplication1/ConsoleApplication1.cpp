#include <iostream>
using namespace std;

int vocale(char a[])
{
_asm
{
	mov ebx,[ebp+8]
	mov ecx,0
start_while:
	mov al,[ebx]
	cmp al,0
	je sfarsit_while
	cmp al,'a'
	je incrementare_vocale
	cmp al,'e'
	je incrementare_vocale
	cmp al,'i'
	je incrementare_vocale
	cmp al,'o'
	je incrementare_vocale
	cmp al,'u'
	je incrementare_vocale
	cmp al,'A'
	je incrementare_vocale
	cmp al,'E'
	je incrementare_vocale
	cmp al,'I'
	je incrementare_vocale
	cmp al,'O'
	je incrementare_vocale
	cmp al,'U'
	je incrementare_vocale
	jmp incrementare
incrementare_vocale:
	inc ecx
incrementare:
	inc ebx
	jmp start_while
sfarsit_while:
	mov eax,ecx
}
}
int main()
{
	char a[]="AhohhuuhlklOhlkjikdfnvdalfneblfnUI";
	int d;
	_asm
	{
		lea ebx,a
		push ebx
		call vocale
		add esp,4
		mov d,eax
	}
	cout<<"Numarul vocalelor din sirul introdus este "<<d<<endl;
}