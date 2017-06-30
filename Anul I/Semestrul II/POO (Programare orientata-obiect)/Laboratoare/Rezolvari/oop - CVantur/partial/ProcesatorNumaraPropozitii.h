#include "Procesator.h"
using namespace std;

class ProcesatorNumaraPropozitii : public Procesator
{
private:
	int cnt;

public:
	void Proceseaza(const string &p);
	void Print();
	~ProcesatorNumaraPropozitii();
};