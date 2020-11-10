#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    size_t rows, cols;
    cin >> rows >> cols;
    list<int> sum(cols, 0);
    for (size_t i = 0; i < rows; ++i)
    {
        list<int> row;
        int n;
        cin >> n;
        row.emplace_back(n);
        auto maximum = row.begin();
        for (size_t j = 1; j < cols; ++j)
        {
            cin >> n;
            row.emplace_front(n);
            if (n > *maximum)
            {
                maximum = row.begin();
            }
        }
        sum.front() += *maximum;
        maximum = row.erase(maximum);
        for (auto it = next(sum.begin()); it != sum.end(); ++it)
        {
            if (maximum == row.begin())
            {
                *it += row.front();
                row.pop_front();
                maximum = row.begin();
            }
            else if (maximum == row.end())
            {
                *it += row.back();
                row.pop_back();
                maximum = row.end();
            }
            else if (*prev(maximum) > *maximum)
            {
                *it += *prev(maximum);
                row.erase(prev(maximum));
            }
            else if (*prev(maximum) < *maximum)
            {
                *it += *maximum;
                maximum = row.erase(maximum);
            }
            else
            {
            }
        }
    }

    list<int> dec = {0};

    for (auto n : sum)
    {
        {
            int carry = 0;
            for (auto it = dec.begin();
                 n || carry;
                 n /= 10, ++it)
            {
                if (it == dec.end())
                {
                    dec.emplace_back(0);
                    it = prev(dec.end());
                }
                int s = carry + *it + n % 10;
                carry = s / 10;
                *it = s % 10;
            }
        }
        {
            int carry = 0;
            for (auto &i : dec)
            {
                int s = carry + i * 2;
                carry = s / 10;
                i = s % 10;
            }
            if (carry)
            {
                dec.push_back(carry);
            }
        }
    }

    for (auto it = dec.crbegin(); it != dec.crend(); ++it)
    {
        cout << *it;
    }
    cout << endl;

    return 0;
}
