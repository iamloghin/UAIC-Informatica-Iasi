#include "t1.h"

/*
1.(0.4p)  Scrieți o funcție care verifică dacă un număr este palindrom. Un număr
este palindrom dacă citit de la dreapta la stanga este egal cu numărul citit de
la stânga la dreapta.
     Ex: 13231 este palindrom dar 12331 nu este palindrom
*/
bool isPalindrom(unsigned long long number)
{
    unsigned long long copie_number=number, new_number=0;

    if (number<=9) return true;

    while (number)
    {
        new_number=new_number*10 + number%10;
        number/=10;
    }

    if (new_number==copie_number)
        return true;

    return false;
}

/*
2.(0.4p) Scrieți o funcție care, pentru un număr natural, calculeză suma
cifrelor reprezentării lui binare.
     Ex: pentru number = 11 reprezentarea binară: 1011
        functia va returna 3 (numarul 3 nu caracterul '3')
*/
unsigned char sumBinaryFigure(unsigned long long number)
{
    unsigned char sum=0;

    while (number)
    {
        sum+=number%2;
        number/=2;
    }

    return (unsigned char) sum;
}

/*
3.(0.4p) Scrieti o funcție care calculează dacă un an este bisect.
*/
bool isLeapYear(unsigned short year)
{
    if (year%400==0 || (year%100!=0 && year%4==0) )
        return true;
    return false;
}

/*
4.(0.4p) Scrieți o funcție care pentru o zi (an luna zi) va returna numărul
zilei din săptamană.
     Ex: pentru year = 2016 month = 10 (Octombrie) day = 1
funcția va returna 6 (Sâmbătă) (numărul 6 nu caracterul '6')
    Hint: Congruența lui Zeller
*/
unsigned char dayOfTheWeek(unsigned short year, unsigned char month, unsigned char day)
{
    int h, q, m, k, j;

    if (month>12) return 0;
    if (day>31)   return 0;
    if (month==2 && day>29)   return 0;
    if (!isLeapYear(year) && month==2 && day==29) return 0;

    if (month==1) { month=13; year--; }
    if (month==2) { month=14; year--; }

    k=year%100;
    j=year/100;
    h=day + 13*(month+1)/5 + k + k/4 + j/4 + 5*j;
    h=h%7;

    int x=h+6;
    if (x<8) return x;

    return (unsigned char) x%7;
}

/*
5.(0.4p) Scrieti o funcție care pentru un număr X returnează al X-lea număr din
șirul lui Fibonnaci.
    Șirul lui Fibonnaci:
        fib(0) = 0;
        fib(1) = 1;
        fib(x) = fib(x-1) + fib(x-2);
     Ex: fib(3) = fib(2) + fib(1) = fib(1) + fib(0) + 1 = 1 + 0 + 1 = 2
*/
unsigned int fibonnaci(int index)
{
    int f1=1, f2=1, f3;

    if (index <=0 ) return 0;
    if (index==1) return 1;
    if (index==2) return 1;

    index-=2;
    while (index)
    {
        f3=f1+f2;
        f1=f2; f2=f3;
        index--;
    }
    return f3;
}

/*
6.(0.4p) Spunem că un număr natural este perfect dacă este egal cu suma
divizorilor săi strict mai mici decât el. Scrieți o funcție care returnează suma
celor mai mari două numere perfecte mai mici decat un număr (number >= 30) dat.
     Ex: 6 = 1 + 2 + 3 este numar perfect
        pentru number = 30 numerele perfecte sunt 6 si 28
*/
unsigned long perfectNumbers(unsigned int number)
{
    unsigned long d, perfect1=6, perfect2=28, i=30, sum;

    while (i<number)
    {
        d=2; sum=1;
        while (d*d<i)
        {
            if (i%d==0)
                sum=sum+d+i/d;
            d++;
        }
        if (d*d==i) sum+=d;
        if (sum==i)
        {
            perfect1=perfect2;
            perfect2=i;
        }
        i++;
    }
    return perfect1+perfect2;
}

/*
7.(0.4p) Scrieți o funcție care pentru un interval închis dat [left, right]
returnează numărul de numere ce au număr maxim de divizori primi.
     Ex: Pentru  [30, 45] numerele cu număr maxim de divizori primi = 30,42
     (au cate 3 divizori primi, nici un alt număr din interval nu are mai mulți
      divizori primi) iar functia va returna 2.
*/
bool isPrime(unsigned int number)
{
    int d=2;
    while (d*d<=number)
    {
        if (number%d==0)
            return false;
        d++;
    }
    return true;
}
unsigned short primeDivisors(unsigned int left, unsigned int right)
{
    int d, nrdiv, k=0, maxn=0, nrmax=0, i, j;
    int v[1001];

    int lgv=right-left+1;
    for (i=left; i<=right; i++)
    {
        d=2; nrdiv=0;
        while(d<=i/2)
        {
            if (isPrime(d) && i%d==0)
                nrdiv++;
            d++;
        }
        v[k++]=nrdiv;
        if (nrdiv>maxn)
            maxn=nrdiv;
    }

    for (i=0; i<lgv; i++)
        if (v[i]==maxn)
            nrmax++;
    return nrmax;
}

/*
8.(0.4p) Două numere naturale impare consecutive și prime se numesc numere prime
gemene.Scrieți o funcție care determină primele x perechi de numere prime gemene
mai mari decât un y dat.
Ex: Pentru count = 1 și lowerBound = 2 funcția va returna o matrice cu un rând
(un rezultat) și 2 coloane (pereche de numere – două numere) 3 5
*/
matrix primeTwins(unsigned int count, unsigned int lowerBound)
{
    int i, j;

    matrix M;

    i=lowerBound;
    if (lowerBound%2==0)
    {
        i+=1;
        j=i+2;
    }
    else
    {
        i=i+2;
        j=i+2;
    }

    M.lines=0; M.columns=2;
    while (count)
    {
        if (isPrime(i) && isPrime(j))
        {
            M.values[M.lines][0]=i;
            M.values[M.lines][1]=j;
            M.lines++;
            count--;
        }
        i+=2; j+=2;
    }

    return M;
}

/*
9.(0.4p) Scrieți o funcție care pentru un vector de lungime x verifică dacă
elementele din vector sunt primele x numere din șirul lui Fibonnaci în ordinea
apariției lor in șir.
     Ex: Pentru [0,1,1,2,3,5] funcția va returna true;
         Pentru [0,1,1,3,2,4] si [0,1,1,2,4] funcția va returna false.
*/
bool areOrderedFibonnaci(vector vec)
{
    int i;

    if (vec.values[0]!=0) return false;
    if (vec.values[1]!=1) return false;

    for (i=2; i<vec.length; i++)
    {
        if (vec.values[i]!=(vec.values[i-1]+vec.values[i-2]))
            return false;
    }
    return true;
}

void SelectSort(vector &vec)
{
    int i, j, mini, pmin;

    //Select Sort
    for (i=0; i<vec.length-1; i++)
    {//determinam min de la 1 la i
        mini=vec.values[i]; pmin=i;
        for (j=i+1; j<vec.length; j++)
            if (vec.values[j]<mini)
            {
                mini=vec.values[j];
                pmin=j;
            }
         //interschimbam min cu elementul de pe pozitia i
         vec.values[pmin]=vec.values[i];
         vec.values[i]=mini;
    }
}

/*
10.(0.4p) Scrieți o funcție care primește doi vectori ca parametru și returnează
 0 dacă sunt egali, 1 daca primul este inclus în al doilea, 2 dacă al doilea
 este inclus în primul și 3 altfel.
     Ex: Pentru [1,2,3] si [3,1,2] funcția returnează 0;
        Pentru [1,2,3] si [3,2] funcția returnează 2;
        Pentru [1,2,3] si [3,2,4] funcția returnează 3.
*/
unsigned char checkVectorInclude(vector vecOne, vector vecTwo)
{
     int i, j, minval=-1000000, countOne=0, ok;


     if (vecOne.length==0 || vecTwo.length==0)
     {
         if (vecOne.length==0 && vecTwo.length)
            return (unsigned char)1;
         if (vecOne.length==0 && vecTwo.length==0)
            return(unsigned char) 0;
         return(unsigned char) 2;
     }
     SelectSort(vecOne);
     SelectSort(vecTwo);

     if (vecOne.length==vecTwo.length)
     {
         for (i=0; i<vecOne.length; i++)
            if (vecOne.values[i]!=vecTwo.values[i])
               return (unsigned char) 3;
            return (unsigned char) 0;
     }

     if (vecOne.length>vecTwo.length)
     {
         for (i=0; i<vecTwo.length; i++)
         {
            ok=0;
            for (j=0; j<vecOne.length && !ok; j++)
                if (vecTwo.values[i]==vecOne.values[j])
                {
                    vecOne.values[j]=minval;
                    countOne++;
                    ok=1;
                }
         }
            if (countOne==vecTwo.length)
                 return (unsigned char) 2;
             return (unsigned char) 3;
     }
     else
     {
          for (i=0; i<vecOne.length; i++)
         {
            ok=0;
            for (j=0; j<vecTwo.length && !ok; j++)
                if (vecOne.values[i]==vecTwo.values[j])
                {
                    vecTwo.values[j]=minval;
                    countOne++;
                    ok=1;
                }
         }
            if (countOne==vecOne.length)
                 return (unsigned char) 1;
             return (unsigned char) 3;
     }
}

/*
11.(0.4p) Scrieți o funcție care pentru un vector și o matrice primite ca
parametri verifică dacă vectorul se regasește ca linie și/sau coloană în matrice.
    Ex: Pentru [1,3,6] și
[1,2,3]
[3,4,5]
[6,7,8]
funcția returnează true;
        Pentru [1,2] și
[2,1]
[3,4] funcția returnează false.
*/
bool checkIsIn(vector vec, matrix mat)
{
    unsigned long int i, j, ok;

    if (vec.length>mat.lines || vec.length>mat.columns) return false;
    if (mat.lines==0 || mat.columns==0) return true;
    for (i=0; i<mat.lines; i++) //cautam pe linii
    {
        ok=1;
        for (j=0; j<mat.columns && ok; j++)
            if (mat.values[i][j]!=vec.values[j])
                ok=0;
        if (ok) return true;
    }

    for (j=0; j<mat.columns; j++) //cautam pe coloane
    {
        ok=1;
        for (i=0; i<mat.lines && ok; i++)
            if (mat.values[i][j]!=vec.values[i])
                ok=0;
        if (ok) return true;
    }
    return false;
}

/*
12.(0.4p) Scrieți o funcție care primește ca parametri o matrice patratică nxn,
un număr de rotații stânga și un număr de rotații dreapta și returnează matricea
cu rotații stânga, respectiv dreapta în funcție de numerele primite ca parametri.
     Ex: Pentru
[1,2]
[3,4],
     rotLeft = 1, rotRight = 0 funcția returnează
[2,4]
[1,3].
        Pentru [1,2][3,4], rotLeft = 0, rotRight = 1 funcția returnează
[3,1]
[4,2]
*/
matrix rotate(matrix mat, unsigned int rotLeft, unsigned int rotRight)
{
    int i, j;
    matrix matAux;
    matAux.lines=mat.lines;
    matAux.columns=mat.lines;

    if (rotLeft==rotRight) return mat;
    if (rotLeft>rotRight)
    {
        rotLeft-=rotRight;
        rotLeft%=4;
        rotRight=0;
    }
    else
    {
        rotRight-=rotLeft;
        rotRight%=4;
        rotLeft=0;
    }

    if (rotLeft==0)
    {
        while (rotRight)
        {
            for (j=0; j<mat.columns; j++)
                for (i=mat.lines-1; i>=0; i--)
                    matAux.values[j][mat.lines-1-i]=mat.values[i][j];

            for (i=0; i<mat.lines; i++)
                for (j=0; j<mat.columns; j++)
                    mat.values[i][j]=matAux.values[i][j];
            rotRight--;
        }
    }
    else //rotRight=0;
    {
        while (rotLeft)
        {
            for (i=0; i<mat.lines; i++)
                for (j=0; j<mat.columns; j++)
                    matAux.values[i][j]=mat.values[j][i];

            for (j=0; j<mat.columns; j++)
                for (i=0; i<mat.lines; i++)
                    mat.values[mat.lines-1-i][j]=matAux.values[i][j];
            rotLeft--;
        }
    }
    return mat;
}

/*
13.(0.6p)  Scrieți o funcție care pentru un vector de  lungime x și un număr y
verifică dacă elementele din vector sunt primele x numere din sirul lui Fibonnaci
începând cu numărul y (>=2).
     Ex: Pentru [3,5,2] și 2 functia va returna true;
        Pentru [3,4,2] si 2 functia va returna false.
*/
bool isPartOfFibonnaci(vector vec, unsigned int startingNumber)
{
    long long int i, j, mini, pmin;

    SelectSort(vec);

    if (vec.values[0]!=startingNumber) return false;

    long long int a=0, b=1, c;

    while(c!=startingNumber)
    {
        c=a+b;
        a=b;
        b=c;
    }

    if (vec.length==1) return true;
    if (a+startingNumber != vec.values[1])
        return false;

    bool ok=true;
    for (i=0; i<vec.length-2 && ok; i++)
    {
        if (vec.values[i]+vec.values[i+1]!=vec.values[i+2])
            ok=false;
    }
    return ok;
}

/*14.(0.6p) Scrieți o funcție care primește
 - un vector de x numere a căror reprezentare binară reprezintă mulțimi de
 numere din intervalul [0,63]
 - un vector de x-1 caractere, fiecare caracter reprezentând o operatie între
 mulțimi: ’U’ = reuniune, ’A’ = intersecție, ’\’ = A – B, ’/’ = B – A
și returnează numărul obținut prin aplicarea operațiilor pe numerele primite ca
parametru astfel:
Prima operație se aplică pe primele două numere
A doua operație se aplică pe rezultatul operației anterioare și al treilea numar
A treia operație se aplică pe rezultatul operației anteriore și al patrulea număr
ș.a.md.
Ex: Pentru sets=[1,2,3] și operations=[’U’,’\’] funcția va calcula 001(1) reunit
cu 010(2) și va avea rezultatul 011 iar 011 minus 011(3) va avea rezultatul 000(0)
si funcția va returna 0.
*/
unsigned long setOperations(long sets[], char operations[], unsigned int x)
{
    unsigned long result, i;

    result=sets[0];
    for (i=1; i<x; i++)
    {
        if (operations[i-1]=='U')//A | B
            result=result | sets[i];

        if (operations[i-1]=='A')//A & B
            result=result & sets[i];

        if (operations[i-1]=='\\')//A-B
            result=result ^ (result & sets[i]);

        if (operations[i-1]=='/')//B-A
            result=sets[i] ^ (sets[i] & result);

    }
    return result;
}


/*
15.(0.6p) Scrieți o funcție care primește ca parametri un vector de x numere  și
un vector de x-1 caractere reprezentând operații pe biți () și returnează
rezultatul aplicării operațiilor pe numere. Operațiile sunt aplicate astfel:
prima operație se aplică pe primele două numere, a doua operație se aplică pe
rezultatul primei operații și al treilea număr, a treia operație pe rezultatul
operației a doua și al patrulea număr ș.a.m.d.
	Operații: < (<<), > (>>), ^, |, &
	Ex: Pentru numbers=[1,2,3] și operations=[>,&] funcția va returna (1>>2)&3 = 0
*/

unsigned long bitOperations(long numbers[], char operations[], unsigned int x)
{
    unsigned long result, i;

    result=numbers[0];
    for (i=1; i<x; i++)
    {   if (operations[i-1] == '<')
            result=result << numbers[i];

        if (operations[i-1] == '>')
            result=result >> numbers[i];

        if (operations[i-1]=='^')
            result=result ^ numbers[i];

        if (operations[i-1]=='&')
            result=result & numbers[i];

        if (operations[i-1]=='|')
            result= result | numbers[i];
    }
    return result;
}

/*
16.(0.85p) Scrieți o funcție care verifică dacă reprezentarea binară a unui
număr dat ca parametru este palindrom.
*/
bool palindrom(long number)
{
    int i=0, b[MAX_ARRAY_LENGTH], negativ=0;

    if (number<0)
    {
        number*=-1;
        negativ=1;
    }

    for (i=0; i<32 || number; i++)
    {
        b[i]=number%2;
        number/=2;
    }

    int length=i;
    if (negativ)
    {
        for (i=0; i<32; i++)
            b[i]=1-b[i];
        i=0;
        //adun 1 la number
        if (b[i]==0)
            b[i++]=1;
        else
        {
            while (b[i]) b[i++]=0;
            b[i]=1;
        }
    }

    for (i=0; i<length/2; i++)
        if (b[i]!=b[length-1-i])
            return false;

    return true;
}

/*
17.(0.85p) Scrieți o funcție care primește ca parametru o matrice cu x rânduri
și y coloane și verifică daca matricea conține primele (x*y) elemente din sirul
lui fibonnaci in spirală pornind din colțul stânga sus.
    Ex: Pentru
[0,1]
[2,1]
și
[0, 1, 1]
[13,21,2]
[8, 5, 3]
returnează true;
        Pentru
[0,1]
[1,2]
returnează false.
*/
bool fibonnaciSpirale(matrix mat)
{
    int k, i, j, l=0, nr=0;
    int v[100001];

    for (k=0; k<(mat.lines+1)/2 && nr<=mat.lines*mat.columns; k++)
    {
        for (j=k; j<=mat.columns-k-1; j++)
        {   v[l++]=mat.values[k][j]; nr++;}

        for (i=k+1; i<=mat.lines-k-1; i++)
        {   v[l++]=mat.values[i][mat.columns-k-1]; nr++;}

        if (nr>=mat.columns*mat.lines) break;
        for (j=mat.columns-k-2; j>=k; j--)
        {   v[l++]=mat.values[mat.lines-k-1][j]; nr++;}

        for (i=mat.lines-k-2; i>k; i--)
        {   v[l++]=mat.values[i][k]; nr++;}
    }

    int f1=0, f2=1;
    if (v[0]==0 && v[1]==1)
    {
        for (i=2; i<l; i++)
            if (v[i]!=(v[i-1]+v[i-2]))
                return false;
    }
    return true;
}

/*
18.(0.85p) Scrieți o funcție care primește un labirint sub forma unei matrici,
poziția celulei de plecare și poziția celulei de iesire și returnează lungimea
drumului minim de la plecare la ieșire. Fiecare celulă din matrice va avea va
avea valoare 1 (perete) sau 0 (drum).
*/
bool verificareMatrix (unsigned int linM, int colM, int lin, int col)
{
    if (lin<0 || lin>=linM)
        return false;
    if (col<0 || col>=colM)
        return false;
    return true;
}

unsigned int minRouteLength(smaze maze)
{

    char dl[]={-1, 0, 1, 0};
    char dc[]={0, 1, 0, -1};

    int prim, ultim, k;

    struct poz
    {
        int lin;
        int col;
    }C[MAX_ARRAY_LENGTH_LONG*MAX_ARRAY_LENGTH_LONG], poz, vecin;

    prim=0; ultim=0;
    C[0].lin=maze.rowOfDeparture;
    C[0].col=maze.columnOfDeparture;
    maze.maze[maze.rowOfDeparture][maze.columnOfDeparture]='1';

    while (prim<=ultim && maze.maze[maze.rowOfExit][maze.columnOfExit]=='0')
    {
        poz.lin=C[prim].lin;
        poz.col=C[prim].col;
        prim++;

        for (k=0; k<4; k++)
        {
            vecin.lin=poz.lin+dl[k];
            vecin.col=poz.col+dc[k];
            if (maze.maze[vecin.lin][vecin.col]=='0'
                && verificareMatrix(maze.noOfRows, maze.noOfColumns, vecin.lin, vecin.col))
            {
                maze.maze[vecin.lin][vecin.col]=maze.maze[poz.lin][poz.col]+1;
                ultim++; C[ultim]=vecin;
            }
        }
    }

    return (unsigned int) maze.maze[maze.rowOfExit][maze.columnOfExit]-'1';
}

/*
19.(0.85p) Scrieți o funcție care primește o matrice de 1 și 0, și returnează
matricea modificată astfel: dacă într-o celulă se găsește 0, toată linia și
coloana respectivă vor fi umplute cu 0.
Ex: Pentru matricea
[1, 0, 1]
[1, 1, 1]
[1, 1, 1]
funcția va returna
[0, 0, 0]
[1, 0, 1]
[1, 0, 1]
*/
void transformMatrix(char mat[MAX_ARRAY_LENGTH_LONG][MAX_ARRAY_LENGTH_LONG], unsigned int rows, unsigned int columns)
{
    unsigned int i, j, k;


    for (i=0; i<rows; i++)
        for (j=0; j<columns; j++)
        {
            if (mat[i][j]==0)
            {
                mat[i][j]=7;
                for (k=0; k<columns; k++)
                    if (mat[i][k]==1)
                        mat[i][k]=7;

                for (k=0; k<rows; k++)
                    if (mat[k][j]==1)
                        mat[k][j]=7;
            }
        }

    for (i=0; i<rows; i++)
        for (j=0; j<columns; j++)
        {
            if (mat[i][j]==7)
                mat[i][j]=0;
        }
}
