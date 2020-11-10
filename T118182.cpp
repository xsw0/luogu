#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main()
{
    size_t n, m;
    cin >> n >> m;
    vector<size_t> a, b;
    a.reserve(n);
    b.reserve(n - 1);
    for (size_t i = 0; i < n; ++i)
    {
        size_t t;
        cin >> t;
        a.emplace_back(t);
    }
    for (size_t i = 0; i < n - 1; ++i)
    {
        size_t t;
        cin >> t;
        b.emplace_back(t);
    }

    return 0;
}
