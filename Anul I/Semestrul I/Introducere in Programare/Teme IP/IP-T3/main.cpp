#include <iostream>
#include <fstream>
#include "t3.h"

ArbBin* inserare_nod(ArbBin* rad, int value)
{
    if (rad)
    {
        if (value < rad->val)
            rad->st=inserare_nod(rad->st, value);
        if (value > rad->val)
            rad->dr=inserare_nod(rad->dr, value);
        return rad;
    }
    else
    {
        ArbBin *p=new ArbBin;
        p->st=NULL;
        p->dr=NULL;
        p->val=value;
        return p;
    }
}


void parcurgere(ArbBin* rad, int &x)
{
    if (rad)
    {
        if (rad->st && rad->dr)///daca exista
        {
            if (rad->st->val!=0 && rad->dr->val!=0)///si sunt nenulu
                if(rad->st->val%2==0 && rad->dr->val%2==0)//si sunt pari
                    x++;
        }
        parcurgere(rad->st, x);
        parcurgere(rad->dr, x);
    }
}

void PreOrdine(ArbBin* rad)
{
    if (rad)
    {
        cout<<rad->val<<" ";
        PreOrdine(rad->st);
        PreOrdine(rad->dr);
    }
}

int nrNoduriSpeciale(int vectorNoduri[MAX_NODURI], int nrNoduri)
{
    ArbBin *rad;
    rad=new ArbBin;
    rad->st=NULL; rad->dr=NULL;
    rad->val=vectorNoduri[0];

    for (int i=1; i<nrNoduri; i++)
    {
        rad=inserare_nod(rad, vectorNoduri[i]);
    }

    PreOrdine(rad);
    int nrNspeciale=0;
    parcurgere(rad, nrNspeciale);
    return nrNspeciale;
}

int main()
{
    ifstream fin("txt.in");
    int n, a[MAX_NODURI];
    fin>>n;
    for (int i=0; i<n; i++)
        fin>>a[i];

    cout<<nrNoduriSpeciale(a, n);
    return 0;
}

