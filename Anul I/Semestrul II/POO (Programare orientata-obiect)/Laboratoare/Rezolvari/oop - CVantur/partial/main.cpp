#include <iostream>
#include "ListaParagrafe.h"
#include "Procesator.h"
#include "ProcesatorNumaraCuvinte.h"
#include "ProcesatorNumaraPropozitii.h"
using namespace std;

int main()
{
	ListaParagrafe L;
	L.Add("Ce usor e Testul la C++!"); L.Add("Ce faci? Bine, tu Ce faci? Tot Bine.");
	Procesator *P = new ProcesatorNumaraCuvinte();
	Procesator *P2 = new ProcesatorNumaraPropozitii();
	for(auto paragraf : L) {
	P->Proceseaza(paragraf);
	P2->Proceseaza(paragraf);
	}
	P->Print(); // Afiseaza "Testul: 1, la: 1, C++: 1, e: 1, usor: 1,Ce: 3, Bine: 2, faci: 2, Tot: 1, tu: 1"
	P2->Print(); // Afiseaza "4 propozitii"
	delete P;
	delete P2;
	for(auto paragraf : L) {
	cout << paragraf << '\n';
	}
	// For-ul de mai sus va afisa paragrafele originale date prin metoda Add:
	// Ce usor e Testul la C++!
	// Ce faci? Bine, tu Ce faci? Tot Bine.
	return 0;
}
