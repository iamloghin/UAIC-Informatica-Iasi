#include "t2.h"

long long power(long long numar,long long putere)
{
    long long aux=4;
    if(putere==0)
        return 1;
    if(putere==1)
        return 4;
    for(int i=2; i<=putere; i++)
        aux=aux*4;
    return aux;
}

void switch_to(char sirADN[MAX_ADN], int lungime)
{
    for(int i=0; i<=lungime; i++)
        switch(sirADN[i])
        {
            case -1:
                sirADN[i]='T';
                break;
            case 0:
                sirADN[i]='A';
                break;
            case 1:
                sirADN[i]='C';
                break;
            case 2:
                sirADN[i]='G';
                break;
            case 'T':
                sirADN[i]=-1;
                break;
            case 'A':
                sirADN[i]=0;
                break;
            case 'C':
                sirADN[i]=1;
                break;
            case 'G':
                sirADN[i]=2;
                break;
        }
}

void codificareADN(long long nrIntreg, char sirADN[MAX_ADN])
{
    unsigned int lungime=0;
    bool este_pozitiv=true;

    if(nrIntreg>=0)
    {
        while(nrIntreg>power(4,lungime)*2.5)
        {
            sirADN[lungime]=0;
            lungime++;
        }
        sirADN[lungime]=0;
    }
    else if(nrIntreg<0)
    {
        int sum=2;
        este_pozitiv=false;
        nrIntreg=-nrIntreg;
        while(nrIntreg>=sum)
        {
            sirADN[lungime]=0;
            lungime++;
            sum=sum+power(4,lungime);
        }
        sirADN[lungime]=0;
    }

    for(int i=lungime; i>=0; i--)
    {
        int rest = nrIntreg%4;
        switch(rest)
        {
            case 0:
                break;
            case 1:
                if(este_pozitiv)
                    sirADN[i]+=1;
                else
                    sirADN[i]+=-1;
                break;
            case 2:
                if(este_pozitiv)
                    sirADN[i]+=2;
                else
                {
                    sirADN[i]+=2;
                    sirADN[i-1]-=1;
                }
                break;
            case 3:
                if(este_pozitiv)
                {
                    sirADN[i]+=-1;
                    sirADN[i-1]+=1;
                }
                else
                {
                    sirADN[i]+=1;
                    sirADN[i-1]-=1;
                }
                break;
        }
        if(sirADN[i]==3)
        {
            sirADN[i]=-1;
            sirADN[i-1]+=1;
        }
        else if(sirADN[i]==-2)
        {
            sirADN[i]=2;
            sirADN[i-1]-=1;
        }
        else if(sirADN[i]==-3)
        {
            sirADN[i]=1;
            sirADN[i-1]-=1;
        }
        nrIntreg/=4;
    }
    switch_to(sirADN,lungime);
}

long long decodificareADN(char sirADN[MAX_ADN])
{
    long long result = 0;
    long long lungime = strlen(sirADN)-1;
    switch_to(sirADN, lungime);
    for(long long i=lungime; i>=0; i--)
        result = result + sirADN[i]*power(4,lungime-i);
   return result;
}

void adunareADN(char primulSir[MAX_ADN], char alDoileaSir[MAX_ADN], char suma[MAX_ADN])
{
    long long result = decodificareADN(primulSir)+decodificareADN(alDoileaSir);
    codificareADN(result,suma);
}

void scadereADN(char primulSir[MAX_ADN], char alDoileaSir[MAX_ADN], char diferenta[MAX_ADN])
{
    long long result= decodificareADN(primulSir)-decodificareADN(alDoileaSir);
    codificareADN(result,diferenta);
}

rezultat mutariJoc(cartonas vecCartonase[MAX_CARTONASE], unsigned int nCartonase, char literaStart, char sirFinal[MAX_SIR])
{
    rezultat x;
    return x;
}
