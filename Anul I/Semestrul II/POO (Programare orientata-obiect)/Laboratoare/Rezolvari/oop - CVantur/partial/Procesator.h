#include <string>
using namespace std;

#ifndef PROCESATOR_H
#define PROCESATOR_H

class Procesator
{
protected:
	//vector<string> v;

public:
	virtual void Proceseaza(const string &p) = 0;
	virtual void Print() = 0;
};

#endif