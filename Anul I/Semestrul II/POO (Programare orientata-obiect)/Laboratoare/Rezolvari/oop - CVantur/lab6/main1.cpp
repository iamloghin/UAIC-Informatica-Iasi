#include <bits/stdc++.h>
using namespace std;

/*struct caseInsensitive : public char_traits<char>
{
	static bool eq(char c1, char c2)
	{
		return toupper(c1) == toupper(c2);
	}

	static bool lt(char c1, char c2)
	{
		return toupper(c1) < toupper(c2);
	}

	static int compare(const char *s1, const char *s2, size_t n)
	{
		while(n > 0)
		{
			char c1 = toupper(*s1); ++s1;
			char c2 = toupper(*s2); ++s2;
			if(c1 < c2) return -1;
			if(c1 > c2) return 1;
			--n;
		}
		return 0;
	}
};*/

struct caseInsensitive
{
	bool operator()(const string &s1, const string &s2) const
	{
		string a1 = s1;
		transform(a1.begin(), a1.end(), a1.begin(), ::toupper);

		string a2 = s2;
		transform(a2.begin(), a2.end(), a2.begin(), ::toupper);

		return a1 < a2;
	}
};

bool isLetter(char c)
{
	if('a' <= c && c <= 'z') return true;
	if('A' <= c && c <= 'Z') return true;
	return false;
}

bool partOfWord(const string &s, int i)
{
	if(isLetter(s[i])) return true;
	if(s[i] != '-') return false;

	if(i == 0 || !isLetter(s[i - 1])) return false;
	if(i + 1 == s.length() || !isLetter(s[i + 1])) return false;
	return true;
}

bool isValid(const string &s)
{
	int i;
	bool propEnd = true, lastWasWord = false;

	for(i = 0; i < s.length(); )
	{
		if(isLetter(s[i]))
		{
			while(i < s.length() && partOfWord(s, i)) ++i;
			lastWasWord = true;
			propEnd = false;
			continue;
		}

		if(s[i] == ' ') { ++i; continue; }

		if(!lastWasWord) return false;
		lastWasWord = false;

		if(s[i] == '.' || s[i] == '!' || s[i] == '?')
		{
			++i;
			propEnd = true;
			continue;
		}

		if(s[i] == ',') { ++i; continue; }
		return false;
	}

	return propEnd;
}

string getProp(const string &s, int &i)
{
	string ret;
	while(true)
	{
		if(s[i] == '.' || s[i] == '!' || s[i] == '?')
		{
			ret.push_back(s[i]);
			++i;
			return ret;
		}
		else
			ret.push_back(s[i++]);
	}
}

string getWord(const string &s, int &i)
{
	string ret;

	while(partOfWord(s, i))
		ret.push_back(s[i++]);

	return ret;
}

int main()
{
	ifstream cin("data.in");
	ofstream cout("data.out");

	string line, word;
	vector<string> props;
	map<string, int> cnt;
	set<string, caseInsensitive> words;

	getline(cin, line);

	if(!isValid(line))
	{
		cout << "Text not valid\n";
		return 0;
	}

	for(int i = 0; i < line.length(); )
	{
		props.push_back(getProp(line, i));
	}

	cout << "Props:\n";
	for(auto p : props) cout << p << '\n';
	cout << '\n';

	for(int i = 0; i < line.length(); )
	{
		if(isLetter(line[i]))
		{
			word = getWord(line, i);
			cnt[word]++;
			words.insert(word);
		}
		else ++i;
	}

	cout << "Words:\n";
	for(auto w : cnt) cout << w.first << ' ' << w.second << '\n';
	cout << '\n';

	cout << "Sorted words:\n";
	for(auto w : words) cout << w << '\n';
	cout << '\n';

	return 0;
}