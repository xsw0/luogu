#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
    size_t first = -1;
    size_t count = 0;
    size_t current = 0;
    string match;
    cin >> match;
    string word;
    while (cin >> word)
    {
        auto isEq = [&] {
            if (match.size() != word.size())
            {
                return false;
            }
            for (size_t i = 0; i < match.size(); ++i)
            {
                if (std::toupper(word[i], std::locale()) != std::toupper(match[i], std::locale()))
                {
                    return false;
                }
            }
            return true;
        };
        if (isEq())
        {
            if (count == 0)
            {
                first = current;
            }
            ++count;
        }
        current += word.size();
        current++;
    }
    if (count)
    {
        cout << count << ' ' << first;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}