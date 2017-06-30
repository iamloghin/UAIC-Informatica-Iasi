#include "ProcesatorNumaraPropozitii.h"
#include <iostream>
#include <cstring>
using namespace std;

void ProcesatorNumaraPropozitii::Proceseaza(const string &p)
{
	for(int i = 0; i < p.size(); ++i)
	{
		if(strchr(".?!", p[i])) ++cnt;
	}
}

void ProcesatorNumaraPropozitii::Print()
{
	cout << cnt << " propozitii\n";
}

ProcesatorNumaraPropozitii::~ProcesatorNumaraPropozitii()
{
	cnt = 0;
}