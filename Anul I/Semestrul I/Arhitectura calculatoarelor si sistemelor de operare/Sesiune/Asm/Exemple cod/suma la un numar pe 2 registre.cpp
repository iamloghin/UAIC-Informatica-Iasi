#include <stdio.h>
#define LEAST_SEMNIF 3147093704
#define SEMNIF 1

//Sa se scrie codul in limbaj de asamblare care calculeaza suma: 1+2+3+...+n, unde n = 55607 
//Atentie, aceasta suma nu se poate reprezenta folosind doar 32 de biti.

void main(){
	int n;
	n = 122000;
	int least_semnif,semnif;
	_asm{
		mov eax, n
		mov ebx,eax
		inc eax
		mul ebx
		shr eax,1
		mov ebx,edx
		and ebx,1
		mov cl,31
		shl ebx,cl
		or eax,ebx
		shr edx,1
		mov least_semnif, eax
		mov semnif, edx
	}
	if( least_semnif == LEAST_SEMNIF && semnif == 1){
		printf("Ok!\n");
	}else{
		printf("Failed! Your result is: %d*pow(2,32)+%d\n",semnif, least_semnif);
	}	
}