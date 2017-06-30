#include <string>
using namespace std;

class Contact
{
protected:
	string name;

public:
	virtual string getName() = 0;
};