#include "ProcesatorNumaraCuvinte.h"
#include <iostream>
#include <cstring>
using namespace std;

bool ProcesatorNumaraCuvinte::isLetter(char c)
{
	return !strchr(".?! ,",c);
}

void ProcesatorNumaraCuvinte::Proceseaza(const string &p)
{
	string word;

	for(int i = 0; i < p.size(); ++i)
	{
		if(isLetter(p[i]))
			word.push_back(p[i]);

		if(i + 1 == p.size() || strchr(".?! ,", p[i + 1]))
		{
			//cerr << "new word " << word << "tt" << '\n';
			if(!word.empty()) cnt[word]++;
			word.clear();
		}
	}
}

void ProcesatorNumaraCuvinte::Print()
{
	if(cnt.empty()) return;

	cout << (cnt.begin()->first) << ": " << (cnt.begin()->second);

	auto it = cnt.begin();
	for(++it; it != cnt.end(); ++it)
		cout << ", " << (it->first) << ": " << (it->second);
	cout << '\n';
}

ProcesatorNumaraCuvinte::~ProcesatorNumaraCuvinte()
{
	cnt.clear();
}