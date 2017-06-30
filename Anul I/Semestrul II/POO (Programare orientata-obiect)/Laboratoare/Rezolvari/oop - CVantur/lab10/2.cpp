#include "2.h"
#include <iostream>
using namespace std;

Semafor::Semafor()
{
	cout << "Creating semafor\n";
}

Semafor::~Semafor()
{
	cout << "Destroying semafor\n";
}

Semafor* Semafor::create()
{
	if(nrInstante == NMAX)
	{
		cout << "Error\n";
		return nullptr;
	}

	++nrInstante;
	return new Semafor;
}

void Semafor::destroy(Semafor *s)
{
	if(s)
	{
		--nrInstante;
		delete s;
	}
}

int Semafor::nrInstante = 0;