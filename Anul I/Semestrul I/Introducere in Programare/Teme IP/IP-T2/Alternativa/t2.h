#include <string.h>
#include <string>

#define MAX_ADN 35
#define MAX_CARTONASE 100
#define MAX_SIR 15

using namespace std;

typedef struct
{
    char sus;
    char jos[3];
} cartonas;

struct mutare
{
    cartonas nod;
    struct mutare *urmator;
};

typedef mutare* lista;

struct rezultat
{
	bool sePoate;
	int nrMutari;
	lista mutari;
};

void codificareADN(long long nrIntreg, char sirADN[MAX_ADN]);
long long decodificareADN(char sirADN[MAX_ADN]);
void adunareADN(char primulSir[MAX_ADN], char alDoileaSir[MAX_ADN], char suma[MAX_ADN]);
void scadereADN(char primulSir[MAX_ADN], char alDoileaSir[MAX_ADN], char diferenta[MAX_ADN]);

rezultat mutariJoc(cartonas vecCartonase[MAX_CARTONASE], unsigned int nCartonase, char literaStart, char sirFinal[MAX_SIR]);
