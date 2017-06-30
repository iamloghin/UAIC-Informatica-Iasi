#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include "bigint.h"
#define LOCAL
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main()
{
    ifstream fin("data.in");
    ofstream fout("data.out");

    BigNumber a(90986209), b("909"), c;

    c = a / b;
    fout << (int)c << '\n';
    fout << a(2, 3) << '\n';

    c.Set("5628943");
    fout << (int)c << '\n';

    return 0;
}
