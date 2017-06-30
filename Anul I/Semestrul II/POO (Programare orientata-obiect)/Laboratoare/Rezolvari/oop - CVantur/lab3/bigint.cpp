#include "bigint.h"
#include <algorithm>
using namespace std;

BigNumber::BigNumber()
{
    CharactersCount = 1;
    memset(Number, 0, sizeof Number);
}

BigNumber::BigNumber(int value)
{
    memset(Number, 0, sizeof Number);

    int i = 0;

    do
    {
        Number[i++] = value % 10;
        value /= 10;
    } while (value);

    CharactersCount = i;
}

BigNumber::BigNumber(const char * number)
{
    memset(Number, 0, sizeof Number);

    CharactersCount = strlen(number);

    for (int i = 0; i < CharactersCount; ++i)
        Number[i] = number[CharactersCount - 1 - i] - '0';
}

BigNumber::BigNumber(const BigNumber & number)
{
    memset(Number, 0, sizeof Number);

    CharactersCount = number.CharactersCount;
    for (int i = 0; i < number.CharactersCount; ++i)
        Number[i] = number.Number[i];
}

bool BigNumber::Set(int value)
{
    if (value < 0) return false;

    *this = BigNumber(value);
    return true;
}

bool BigNumber::Set(const char * number)
{
    int i;
    for (i = 0; i < 256 && number[i]; ++i)
        if (number[i] < '0' || number[i] > '9')
            return false;

    if (i >= 256) return false;

    *this = BigNumber(number);
    return true;
}

BigNumber BigNumber::operator+(const BigNumber & number)
{
    int i, t;
    BigNumber sum;

    sum.CharactersCount = max(CharactersCount, number.CharactersCount);

    for (t = 0, i = 0; i < sum.CharactersCount; ++i)
    {
        sum.Number[i] = Number[i] + number.Number[i] + t;
        t = sum.Number[i] / 10;
        sum.Number[i] %= 10;
    }

    if (t)
    {
        ++sum.CharactersCount;
        sum.Number[sum.CharactersCount - 1] = t;
    }
    
    return sum;
}

BigNumber BigNumber::operator* (const BigNumber & number)
{
    BigNumber prod(0);

    if ((*this) == BigNumber(0) || number == 0) return 0;

    prod.CharactersCount = number.CharactersCount + CharactersCount - 1;
    if (prod.CharactersCount > 256) return 0;

    for (int i = 0; i < 256; ++i) prod.Number[i] = 0;
    for (int i = 0; i < CharactersCount; ++i)
    {
        for (int j = 0; j < number.CharactersCount; ++j)
        {
            prod.Number[i + j] += Number[i] * number.Number[j];
            prod.Number[i + j + 1] += prod.Number[i + j] / 10;
            prod.Number[i + j] %= 10;
        }
    }

    int i, t;
    for (t = 0, i = 0; i < prod.CharactersCount; ++i)
    {
        prod.Number[i] += t;
        t = prod.Number[i] / 10;
        prod.Number[i] %= 10;
    }

    if (t)
    {
        prod.Number[prod.CharactersCount] += t;
    }

    if (prod.Number[prod.CharactersCount])
        ++prod.CharactersCount;

    return prod;
}

BigNumber BigNumber::operator- (const BigNumber & number)
{
    int i, t;
    BigNumber diff;

    diff.CharactersCount = max(CharactersCount, number.CharactersCount);

    for (t = 0, i = 0; i < diff.CharactersCount; ++i)
    {
        diff.Number[i] = Number[i] - number.Number[i] + t;
        if (diff.Number[i] < 0) diff.Number[i] += 10, t = -1;
        else t = 0;
    }

    while (diff.CharactersCount > 1 && diff.Number[diff.CharactersCount - 1] == 0) --diff.CharactersCount;

    return diff;
}

BigNumber BigNumber::operator/ (const BigNumber & number)
{
    int i;
    BigNumber q, r;

    q.CharactersCount = CharactersCount;
    for (r = 0, i = CharactersCount - 1; i >= 0; --i)
    {
        r = r * BigNumber(10);
        r.Number[0] = Number[i];

        while (r >= number)
        {
            ++q.Number[i];
            r = r - number;
        }
    }

    while (q.CharactersCount >= 1 && q.Number[q.CharactersCount - 1] == 0) --q.CharactersCount;

    return q;
}

bool operator == (const BigNumber & n1, const BigNumber & n2)
{
    if (n1.CharactersCount != n2.CharactersCount)
        return false;

    for (int i = n1.CharactersCount; i >= 0; --i)
        if (n1.Number[i] != n2.Number[i])
            return false;

    return true;
}

bool operator != (const BigNumber & n1, const BigNumber & n2)
{
    return !(n1 == n2);
}

bool operator <  (const BigNumber & n1, const BigNumber & n2)
{
    if (n1.CharactersCount != n2.CharactersCount)
        return n1.CharactersCount < n2.CharactersCount;

    for (int i = n1.CharactersCount; i >= 0; --i)
        if (n1.Number[i] != n2.Number[i])
            return n1.Number[i] < n2.Number[i];

    return false;
}

bool operator >  (const BigNumber & n1, const BigNumber & n2)
{
    if (n1.CharactersCount != n2.CharactersCount)
        return n1.CharactersCount > n2.CharactersCount;

    for (int i = n1.CharactersCount; i >= 0; --i)
        if (n1.Number[i] != n2.Number[i])
            return n1.Number[i] > n2.Number[i];

    return false;
}

bool operator >= (const BigNumber & n1, const BigNumber & n2)
{
    return !(n1 < n2);
}

bool operator <= (const BigNumber & n1, const BigNumber & n2)
{
    return !(n1 > n2);
}

BigNumber::operator int()
{
    int i, x;

    for (x = 0, i = CharactersCount - 1; i >= 0; --i)
        x = x * 10 + Number[i];

    return x;
}

char BigNumber::operator[] (int index)
{
    if (index < 0 || index >= CharactersCount)
        return 0;

    return Number[index] + '0';
}

BigNumber BigNumber::operator() (int start, int end)
{
    if (start > end) return BigNumber(0);
    if (start < 0 || end >= CharactersCount) return BigNumber(0);

    int i, x;

    for (x = 0, i = end; i >= start; --i)
        x = x * 10 + Number[i];

    return x;
}