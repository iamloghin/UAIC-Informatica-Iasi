#include "Procesator.h"
#include <map>
using namespace std;

class ProcesatorNumaraCuvinte : public Procesator
{
private:
	map<string, int> cnt;

	bool isLetter(char c);

public:
	void Proceseaza(const string &p);
	void Print();
	~ProcesatorNumaraCuvinte();
};