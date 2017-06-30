
#include <iostream>
#include <cstring>
#include <cmath>
#include "t2.h"

using namespace std;

long long decodificareADN(char sirADN[MAX_ADN])
{

}

void switch_to(char sirADN[MAX_ADN], int lungime)
{
    for(int i=0;i<=lungime;i++)
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
                sirADN[i]='-1';
                break;
            case 'A':
                sirADN[i]='0';
                break;
            case 'C':
                sirADN[i]='1';
                break;
            case 'G':
                sirADN[i]='2';
                break;
        }
}

void codificareADN(long long nrIntreg, char sirADN[MAX_ADN])
{
    int lungime=0;
    bool este_pozitiv=true;

    if(nrIntreg>0)
        while(nrIntreg>pow(4,lungime)*2.5) // calculam dimensiunea in sir a numarului pozitiv
        {
            sirADN[lungime]=0;
            lungime++;
        }
    else
    {
        nrIntreg=-nrIntreg; // il transformam in numar natural (ne va ajuta la transformarea binara)
        while(nrIntreg>=pow(4,lungime)*1.5) // calculam dimensiunea in sir a numarului negativ
        {
            este_pozitiv=false;
            sirADN[lungime]=0;
            lungime++;
        }
    }

    sirADN[lungime]=0;

    for(int i=lungime; i>=0; i--)
    {
        int rest = nrIntreg%4;
        switch(rest)
        {
            case 0:
                break;
            case 1:
                if(este_pozitiv)
                    sirADN[i]+=rest;
                else
                    sirADN[i]+=-1;
                break;
            case 2:
                if(este_pozitiv)
                    sirADN[i]+=rest;
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

    //switch_to(sirADN,lungime);


    // pentru mine, verificare rezultat
    for(int i=0;i<=lungime;i++)
        cout<< (int) sirADN[i];
    cout<<endl;
}

int main()
{
        int i=-50, j=-50;
        char c[MAX_ADN];
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        /*cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;
        cout << i++ << ". ";codificareADN(j,c);j++;*/
}
