#include <bits/stdc++.h>
#include "lista.h"
using namespace std;
using uint = unsigned int;
using ll = long long;
using pii = pair<int, int>;
#define dbg(x) cerr<<#x": "<<(x)<<'\n'
#define dbg_v(x, n) cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<'\n'
#define all(v) v.begin(), v.end()
#define NMAX 

ListaDubluInlantuita<int> ints;
ListaDubluInlantuita<char*> chars;

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("data.in");
	ofstream cout("data.out");
#endif
	ios_base::sync_with_stdio(false);

	ints.push_back(2);
	ints.push_back(4);
	ints.push_front(5);

	ints.print(cout);

	ints.pop_back();
	ints.pop_front();

	ints.print(cout);

	chars.push_front("abc");

	chars.print(cout);

	return 0;
}