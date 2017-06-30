#include<iostream>
#include<string>
using namespace std;

#define MAX 100
#define for(i,a,b) for(int i=a; i<b; i++)

string vecCartonase[MAX][MAX];  //to store entered vecCartonasemar
string dpr[MAX];
int p,nCartonase;       //nCartonase-> number of productions

inline string concat( string a, string b)   //concatenates unique non-terminals
{
    int i;
    string r=a;
    for(i,0,b.length())
        if(r.find(b[i]) > r.length())
            r+=b[i];
    return (r);
}

inline void break_vecCartonase(string Cartonas)    //seperates right hand side of entered vecCartonasemar
{
    int i;
    p=0;
    while(Cartonas.length())
    {
        i=Cartonas.find("|");
        if(i>Cartonas.length())
        {
            dpr[p++] = Cartonas;
            Cartonas="";
        }
        else
        {
            dpr[p++] = Cartonas.substr(0,i);
            Cartonas=Cartonas.substr(i+1,Cartonas.length());
        }
    }
}

inline int stangaCYK(string Cartonas)   //checks if LHS of entered vecCartonasemar is in CNF
{
    if(Cartonas.length()==1 && Cartonas[0]>='A' && Cartonas[0]<='Z')
        return 1;
    return 0;
}

inline int dreaptaCYK(string Cartonas)   //checks if RHS of vecCartonasemar is in CNF
{
    if (Cartonas.length() == 1 && Cartonas[0]>='0' && Cartonas[0] <='9')
        return 1;
    if(Cartonas.length()==1 && Cartonas[0]>='A' && Cartonas[0]<='Z')
        return 1;
    if (Cartonas.length()==2 && Cartonas[0]>='A' && Cartonas[0]<='Z' && Cartonas[1]>='A' && Cartonas[1]<='Z' )
        return 1;
    return 0;
}

inline string search_prod(string p) //returns a concatenated string of variables which can produce string p
{
    int j,k;
    string r="";
    for(j,0,nCartonase)
    {
        k=1;
        while(vecCartonase[j][k] != "")
        {
            if(vecCartonase[j][k] == p)
            {
                r=concat(r,vecCartonase[j][0]);
            }
            k++;
        }
    }
    return r;
}

inline string gen_comb(string a, string b)  //creates every combination of variables from a and b . For eg: BA * AB = {BA, BB, AA, BB}
{
    int i,j;
    string pri=a,re="";
    for(i,0,a.length())
        for(j,0,b.length())
        {
            pri="";
            pri=pri+a[i]+b[j];
            re=re+search_prod(pri);     //searches if the generated productions can be created or not
        }
    return re;
}

int main()
{
    int pt,j,l,k;
    string Cartonas,sirFinal,r,pr,literaStart;
    cout<<"\nLitera start: ";
    cin >> literaStart;
    cout<<"\nNr. Cartonase ";
    cin >> nCartonase;
    for(i,0,nCartonase)
    {
        cin >> Cartonas;
        pt=Cartonas.find("->");
        vecCartonase[i][0] = Cartonas.substr(0,pt);
        if (stangaCYK(vecCartonase[i][0]) == 0)
        {
            cout<<"\nSus cartonasul trebuie sa contina doar o litera !\n";
            return 0;
        }
        Cartonas = Cartonas.substr(pt+2, Cartonas.length());
        break_vecCartonase(Cartonas);
        for(j,0,p)
        {
            vecCartonase[i][j+1]=dpr[j];
            if (dreaptaCYK(dpr[j]) == 0)
            {
                cout<<"\nJos cartonasul trebuie sa contina doar un numar sau doua litere!\n";
                return 0;
            }
        }
    }
    string matrix[MAX][MAX],st;
    cout<<"\nEnter string to be checked : ";
    cin >> sirFinal;
    for(i,0,sirFinal.length())       //Assigns values to principal diagonal of matrix
    {
        r="";
        st = "";
        st+=sirFinal[i];
        for(j,0,nCartonase)
        {
            k=1;
            while(vecCartonase[j][k] != "")
            {
                if(vecCartonase[j][k] == st)
                {
                    r=concat(r,vecCartonase[j][0]);
                }
                k++;
            }
        }
        matrix[i][i]=r;
    }
    int ii,kk;
    for(k,1,sirFinal.length())       //Assigns values to upper half of the matrix
    {
        for(j,k,sirFinal.length())
        {
            r="";
            for(l,j-k,j)
            {
                pr = gen_comb(matrix[j-k][l],matrix[l+1][j]);
                r = concat(r,pr);
            }
            matrix[j-k][j] = r;
        }
    }

    for(i,0,sirFinal.length())   //Prints the matrix
    {
        k=0;
        l=sirFinal.length()-i-1;
        for(j,l,sirFinal.length())
        {
            cout<<"\t"<<matrix[k++][j]<<" ";
        }
        cout<<endl;
    }

    int f=0;
    for(i,0,literaStart.length())
        if(matrix[0][sirFinal.length()-1].find(literaStart[i]) <= matrix[0][sirFinal.length()-1].length())   //Checks if last element of first row contains a literaStart variable
        {
            cout<<"String can be generated\n";
            return 0;
        }
    cout<<"String cannot be generated\n";
    return 0;
}
