#include <string>
#include "contact.h"
using namespace std;

class Prieten : public Contact
{
private:
	string birth_date, phone, address;

public:
	string getName();
};