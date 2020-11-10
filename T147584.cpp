#include <iostream>
#include <unordered_map>
#include <cstdint>

using namespace std;

struct Rational
{
    uint64_t numerator;
    uint64_t denominator;
    Rational(uint64_t numerator = 0, uint64_t denominator = 1)
        : numerator(numerator), denominator(denominator){};
    Rational(const Rational &numerator,
             const Rational &denominator = 1)
        : numerator(numerator.numerator * denominator.denominator),
          denominator(numerator.denominator * denominator.numerator){};
    Rational operator*(const Rational &other)
    {
        return Rational(numerator * other.numerator,
                        denominator * other.denominator);
    }
    Rational operator+(const Rational &other)
    {
        return Rational(numerator * other.denominator +
                            denominator * other.numerator,
                        denominator * other.denominator);
    }
};

struct Hasher
{
    size_t operator()(const pair<size_t, size_t> &p) const
    {
        return std::hash<size_t>()(p.first) ^ std::hash<size_t>()(p.second);
    }
};

unordered_map<pair<size_t, size_t>, Rational, Hasher> um{{{0, 1}, {1, 1}}};

Rational count(size_t n, size_t m)
{
    if (um.find({n, m}) == um.end())
    {
        if (m == 0)
        {
            um[{n, m}] = count(n - 1, 1) + 1;
        }
        else if (m == 1)
        {
            um[{n, m}] = count(n, 0) + n + 1;
        }
        else
        {
            um[{n, m}] = Rational(count(n + m - 1, 1) * n + count(n, m - 1) * m + m + n, n + m);
        }
    }
    return um[{n, m}];
}

int main()
{
    size_t n, m;
    while (cin >> n >> m)
    {
        auto r = count(n, m);
        cout << r.numerator / r.denominator << endl;
    }
    return 0;
}
