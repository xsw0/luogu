#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;
    size_t i = 0;
    while (n)
    {
        n /= 2;
        ++i;
    }
    cout << (INT64_MAX >> (63 - i)) * 2 << endl;
    return 0;
}
