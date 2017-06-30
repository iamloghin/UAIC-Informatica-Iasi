#include <vector>
#include <string>
//#include "MyIterator.h"
using namespace std;

class ListaParagrafe
{
private:
	vector<string> v;

public:
	void Add(const string &s);
	vector<string>::iterator begin();
	vector<string>::iterator end();
};