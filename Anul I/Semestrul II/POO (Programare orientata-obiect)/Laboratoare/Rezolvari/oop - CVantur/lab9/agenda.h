#include <vector>
#include "contact.h"
using namespace std;

class Agenda
{
private:
	vector<Contact*> contacts;

public:
	void deleteContact(const string &name);
	bool findContact(const string &name);
	void addContact(const string &name);
	vector<Contact*> getFriends();
};