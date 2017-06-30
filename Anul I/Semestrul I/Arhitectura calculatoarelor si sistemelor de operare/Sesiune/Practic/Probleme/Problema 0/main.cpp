#include <iostream>
#define MAX 100

using namespace std;

struct rect
{
    int x, y; // coordonatele coltului din stanga jos
    int width; // latime
    int height; // inaltime
};

int ic_C(int *src1, int n1, int *src2, int n2, int *dst);
int intersectie_C(rect *r1, rect *r2); // 2 - drpt r2 inclus in r1, 1 - drpt r1 inclus in r2, 0 - nici unu

int main()
{
    // PROBLEMA 1
    /*
    int src1[]={1,4,5,6,7,12}, src2[]={1,2,3,8};
    int dst[MAX], n1=6, n2=6;
    int dim = ic_C(src1, n1, src2, n2, dst);
    cout << "Vectorul interclasat este: " << endl;
    for(int i = 0; i < dim; ++i)
		cout << dst[i] << " ";
    cout << endl;
    */

    // PROBLEMA 2
    rect r1, r2;
    r1.x=0, r1.y=0, r1.height=2, r1.width=5;
    r2.x=0, r2.y=0, r2.height=5, r2.width=10;
    int rezultat = intersectie_C(&r1, &r2);
    cout << rezultat << endl;
    return 0;
}

int ic_C(int *src1, int n1, int *src2, int n2, int *dst)
{
    int i=0, j=0, k=0;
    while(i<n1 && j<n2)
        if(src1[i]<src2[j])
        {
            dst[k]=src1[i];
            k++;
            i++;
        }
        else
        {
            dst[k]=src2[j];
            k++;
            j++;
        }
    if(i<n1)
        for(int l=i; l<n1; l++)
        {
            dst[k]=src1[l];
            k++;
        }
    if(j<n2)
        for(int l=j; l<n2; l++)
        {
            dst[k]=src2[l];
            k++;
        }
    return n1+n2;
}

int intersectie_C(rect *r1, rect *r2)
{
    if(r2->x<r1->width && r2->y<r1->height && r2->x+r2->width<=r1->width && r2->y+r2->height<=r1->height)
        return 2;
    else if(r1->x<r2->width && r1->y<r2->height && r1->x+r1->width<=r2->width && r1->y+r1->height<=r2->height)
        return 1;
    else return 0;
}
