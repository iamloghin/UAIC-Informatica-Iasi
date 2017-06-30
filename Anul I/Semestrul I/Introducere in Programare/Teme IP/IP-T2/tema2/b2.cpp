
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
    int lungime=-1;
    bool este_pozitiv=true;
    for(int i=0; i<=35; i++)
        sirADN[i]=0;
    if(nrIntreg<0)
    {
        este_pozitiv=false;
        nrIntreg=-nrIntreg;
    }
    while(nrIntreg!=0)
    {
        lungime++;
        switch(nrIntreg%4)
        {
            case 0:
                break;
            case 1:
                if(este_pozitiv)
                    sirADN[lungime]+=1;
                else
                    sirADN[lungime]+=-1;
                break;
            case 2:
                if(este_pozitiv)
                    sirADN[lungime]+=2;
                else
                {
                    sirADN[lungime]+=2;
                    sirADN[lungime+1]-=1;
                }
                break;
            case 3:
                if(este_pozitiv)
                {
                    sirADN[lungime]+=-1;
                    sirADN[lungime+1]+=1;
                }
                else
                {
                    sirADN[lungime]+=1;
                    sirADN[lungime+1]-=1;
                }
                break;
        }
        if(sirADN[lungime]==3)
        {
            sirADN[lungime]=-1;
            sirADN[lungime+1]+=1;
        }
        else if(sirADN[lungime]==-2)
        {
            sirADN[lungime]=2;
            sirADN[lungime+1]-=1;
        }
        else if(sirADN[lungime]==-3)
        {
            sirADN[lungime]=1;
            sirADN[lungime+1]-=1;
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
        codificareADN(-23,c);j++;
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
        cout << i++ << ". ";codificareADN(j,c);j++;*/
}
