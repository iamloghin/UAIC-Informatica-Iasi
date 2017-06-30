#include "t2.h"

//int lengthCod=4;
int cod[5] = {-1, 0, 1, 2}; //T A C G
long long pow4[MAX_ADN] = { 1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216, 67108864, 268435456, 1073741824, 4294967296, 17179869184, 68719476736, 274877906944, 1099511627776, 4398046511104, 17592186044416, 70368744177664, 281474976710656, 1125899906842624, 4503599627370496, 18014398509481984, 72057594037927936, 288230376151711744, 1152921504606846976, 4611686018427387904 };

int solution[MAX_ADN], sum;

void write(int k, char sirADN[MAX_ADN])
{
	int i;
	for (i=0; i<k; i++)
	{
		if (solution[i] == -1) sirADN[k-1-i]='T';
		if (solution[i] == 0)  sirADN[k-1-i]='A';
		if (solution[i] == 1)  sirADN[k-1-i]='C';
		if (solution[i] == 2)  sirADN[k-1-i]='G';
	}
	sirADN[k]='\0';
}

/*void bkt(int k, long long nrIntreg, char sirADN[MAX_ADN])
{
	int i;

	if (k == 15) return;
	if (nrIntreg<0)
		if (sum<nrIntreg) return;
		else
			if (sum>nrIntreg) return;
	if (sum == nrIntreg)
	{
		write(k, sirADN);
		return;
	}

	for (i = 0; i<lengthCod; i++)
	{
		solution[k] = cod[i];
		sum += cod[i] * pow4[k];
		bkt(k + 1, nrIntreg, sirADN);
		sum -= cod[i] * pow4[k];
	}
}*/

void codificareADN(long long nrIntreg, char sirADN[MAX_ADN])
{
	//bkt(0, nrIntreg, sirADN);

	long long k=0, rest, cat, ok;

	if (nrIntreg == 0)
        solution[k++]=0;

	if (nrIntreg>0)
    {
        while (nrIntreg)
        {
            ok=0;
            rest=nrIntreg%4;
            if (rest%4==0)
                solution[k++]=rest;
            else
                if (rest%4==1)
                    solution[k++]=rest;
                else
                    if (rest%4==2)
                        solution[k++]=rest;
                    else
                    {
                        cat=nrIntreg/4;
                        cat+=1;
                        solution[k++]=nrIntreg-cat*4;
                        ok=1;
                    }

            if (!ok)
                nrIntreg=nrIntreg/4;
            else
                nrIntreg=cat;
        }
    }
    else
    {
        while (nrIntreg!=0)
        {
            ok=0;
            rest=nrIntreg%4;
            if (rest%4==0)
                solution[k++]=rest;
            else
                if (rest%4==1)
                    solution[k++]=rest;
                else
                    if (rest%4==2)
                        solution[k++]=rest;
                    else
                        if (rest%4==-1)
                            solution[k++]=rest;
                        else
                        {
                            cat=nrIntreg/4;
                            cat-=1;
                            solution[k++]=nrIntreg-cat*4;
                            ok=1;
                        }
            if (!ok)
                nrIntreg=nrIntreg/4;
            else
                nrIntreg=cat;
        }
    }

    write(k, sirADN);
}

long long decodificareADN(char sirADN[MAX_ADN])
{
 	long long lg, k=0, number=0;

	for (lg=strlen(sirADN)-1; lg>=0; lg--)
	{

		if (sirADN[lg] == 'T') number += pow4[k++] * (-1);
		if (sirADN[lg] == 'A') number += pow4[k++] * 0;
		if (sirADN[lg] == 'C') number += pow4[k++] * 1;
		if (sirADN[lg] == 'G') number += pow4[k++] * 2;
	}
	return number;
}

void adunareADN(char primulSir[MAX_ADN], char alDoileaSir[MAX_ADN], char suma[MAX_ADN])
{
    long long first=decodificareADN(primulSir), second=decodificareADN(alDoileaSir);
    long long sum=first+second;
    codificareADN(sum, suma);
}

void scadereADN(char primulSir[MAX_ADN], char alDoileaSir[MAX_ADN], char diferenta[MAX_ADN])
{
    long long first=decodificareADN(primulSir), second=decodificareADN(alDoileaSir);
    long long dif=first-second;
    codificareADN(dif, diferenta);
}

rezultat mutariJoc(cartonas vecCartonase[MAX_CARTONASE], unsigned int nCartonase, char literaStart, char sirFinal[MAX_SIR])
{
    rezultat X;
    X.sePoate=true;
    X.nrMutari=0;
    return X;
}
