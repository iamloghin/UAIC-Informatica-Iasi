#include <iostream>
using namespace std;

char GetMaxConsecutiveChar(char *s)
{
	_asm
	{
		mov ebx,[ebp+8]
		mov cl,0
		mov dl,0
		mov dh,0
		mov al,0
start_for:
		mov al,byte ptr[ebx]
		cmp al,0
		je end_for
		cmp al,[ebx+1]
		jne comparare_incrementare
		inc cl
comparare_incrementare:
		cmp cl,dl
		jb mai_jos
		mov dl,cl
mai_jos:
		cmp al,[ebx+1]
		je mai_departe
		mov cl,0
mai_departe:
		cmp cl,dl
		jb incrementare
		mov dh,[ebx]
incrementare:
		inc ebx
		jmp start_for
end_for:
		mov al,dh
	}
}

int main()
{
	char s[]="aaiugufiufaaahhhh[p[p[lpppppaaaa",a;
	_asm
	{
		lea ebx,s
		push ebx
		call GetMaxConsecutiveChar
		add esp,4
		mov a,al
	}
	cout<<"Elementul care formeaza cea mai lunga secventa de elemente consecutive identice este : "<<a<<endl;

}