#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    size_t n, m;
    cin >> n >> m;
    vector<bool> flower;
    flower.reserve(n);
    size_t tot = 0;
    for (size_t i = 0; i < n; ++i)
    {
        size_t v;
        cin >> v;
        if (v == 1)
        {
            flower.emplace_back(false);
        }
        else
        {
            ++tot;
            flower.emplace_back(true);
        }
    }

    for (size_t i = 0; i < m; ++i)
    {
        char c;
        cin >> c;
        switch (c)
        {
        case 'A':
        {
            size_t s;
            cin >> s;
            if (s > tot + n || s == 0)
            {
                cout << "none" << endl;
            }
            else
            {
                size_t start = 0, last = (s + 1) / 2;
                size_t sss = std::accumulate(flower.cbegin(),
                                             flower.cbegin() + last,
                                             last);
                while (start != last && sss != s)
                {
                    if (sss < s)
                    {
                        if (flower[last])
                        {
                            sss += 2;
                        }
                        else
                        {
                            ++sss;
                        }
                        ++last;
                    }
                    else
                    {
                        if (flower[start])
                        {
                            sss -= 2;
                        }
                        else
                        {
                            --sss;
                        }
                        ++start;
                    }
                }
                if (sss == s)
                {
                    cout << start + 1 << ' ' << last << endl;
                }
                else
                {
                    cout << "none" << endl;
                }
            }
        }
        break;
        case 'C':
        {
            size_t index, val;
            cin >> index >> val;
            --index;
            bool b = val != 1;
            if (b != flower[index])
            {
                if (b)
                {
                    ++tot;
                }
                else
                {
                    --tot;
                }
                flower[index] = b;
            }
        }
        break;
        default:
            break;
        }
    }

    return 0;
}
