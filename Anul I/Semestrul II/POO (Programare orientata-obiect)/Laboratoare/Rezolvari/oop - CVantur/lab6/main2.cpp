#include <bits/stdc++.h>
using namespace std;

int getVal(char c)
{
	switch(c)
	{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
	}

	return 0;
}

int value(const string &s)
{
	int i, x, val;

	for(x = 0, i = 0; i < s.length(); ++i)
	{
		val = getVal(s[i]);

		if(i + 1 < s.length() && getVal(s[i + 1]) > val)
			x -= val;
		else
			x += val;
	}

	return x;
}

int main()
{
	ifstream cin("data.in");
	ofstream cout("data.out");

	string s;
	vector<pair<int, string>> v;

	while(cin >> s)
	{
		v.emplace_back(value(s), s);
		//cout << s << " = " << value(s) << '\n';
	}

	sort(v.begin(), v.end());

	for(auto num : v)
		cout << num.second << '\n';

	return 0;
}