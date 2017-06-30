#include <cmath>
#include "form.h"
#define M_PI 3.141592653589

Dreptunghi::Dreptunghi(int lungime,int latime)
{
	Lungime = lungime;
	Latime = latime;
}

double Dreptunghi::ComputeArea()
{
	return 1.0 * Lungime * Latime;
}

const char * Dreptunghi::GetName()
{
	return "Dreptunghi";
}

Cerc::Cerc(int raza)
{
	Raza = raza;
}

double Cerc::ComputeArea()
{
	return 1.0 * M_PI * Raza * Raza;
}

const char * Cerc::GetName()
{
	return "Cerc";
}

Triunghi::Triunghi(int x1,int y1,int x2,int y2,int x3,int y3)
{
	X1 = x1;
	Y1 = y1;
	X2 = x2;
	Y2 = y2;
	X3 = x3;
	Y3 = y3;
}

double Triunghi::ComputeArea()
{
	return fabs(0.5 * (X2 - X1) * (Y3 - Y1) - 0.5 * (X3 - X1) * (Y2 - Y1));
}

const char * Triunghi::GetName()
{
	return "Triunghi";
}