#include "agenda.h"

void Agenda::deleteContact(const string &name)
{
	for(auto it = contacts.begin(); it != contacts.end(); ++it)
		if((*it)->getName() == name)
		{
			delete (*it);
			contacts.erase(it);
			return;
		}
}

bool Agenda::findContact(const string &name)
{
	for(auto c : contacts)
		if(c->getName() == name)
			return true;

	return false;
}
/*
void Agenda::addContact(const string &name);
vector<Contact*> Agenda::getFriends();*/