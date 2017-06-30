#include "ListaParagrafe.h"
using namespace std;

void ListaParagrafe::Add(const string &s)
{
	v.push_back(s);
}

vector<string>::iterator ListaParagrafe::begin()
{
	return v.begin();
}

vector<string>::iterator ListaParagrafe::end()
{
	return v.end();
}