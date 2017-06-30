#include <string>
#include "contact.h"
using namespace std;

class Cunoscut : public Contact
{
private:
	string phone;

public:
	string getName() { return name; }
};