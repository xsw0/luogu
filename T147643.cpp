#include <iostream>

using namespace std;

int main()
{
    size_t T;
    cin >> T;
    for (size_t i = 0; i < T; ++i)
    {
        size_t n;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << (n / 2) * n - n + 1 << endl;
        }
        else
        {
            cout << (n / 2) * n << endl;
        }
    }
    return 0;
}
