#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using pii = pair<int, int>;
#define dbg(x) cerr<<#x": "<<(x)<<'\n'
#define dbg_v(x, n) cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<'\n'
#define all(v) v.begin(), v.end()
#define LMAX 20

class strIterator
{
public:
	char **it;

	strIterator operator ++()
	{
		it++;
		return *this;
	}

	strIterator operator ++(int a)
	{
		strIterator tmp = *this;
		++it;
		return tmp;
	}

	friend bool operator !=(const strIterator &it1, const strIterator &it2)
	{
		return it1.it != it2.it;
	}

	char* operator *() const
	{
		return *it;
	}
};

class StrVector
{
private:
	char* v[LMAX];
	int size;

public:
	StrVector(const initializer_list<const char*> &l)
	{
		int i = 0;
		for(auto it : l)
			v[i] = new char[strlen(it)],
			strcpy(v[i++], it);

		size = i;
	}

	int GetCount() { return size; }
	strIterator begin() { strIterator tmp; tmp.it = &v[0]; return tmp; }
	strIterator end() { strIterator tmp; tmp.it = &v[size]; return tmp; }
	strIterator GetIterator() { strIterator tmp; tmp.it = &v[0]; return tmp; }
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	StrVector v  {"Test" , "for" , "C++"};
    auto it = v.GetIterator();
    auto count = v.GetCount();

    for (auto index=0;index<count;index++,it++)
        printf("%s\n",*it); // va afisa cele 3 texte
    for (auto element: v)
        printf("%s\n",element); // va afisa deasemenea cele 3 texte

	return 0;
}