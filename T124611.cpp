#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t n;
    cin >> n;
    vector<int> v{1};
    v.reserve(n + 1);
    size_t count = 1;
    for (size_t i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
            v.push_back(2);
            count += 2;
            break;
        case 2:
            v.push_back(1);
            count += 1;
            break;
        default:
        {
            size_t index;
            cin >> index;
            v.push_back(-v[index]);
            count -= v[index];
        }
        break;
        }
        cout << count << endl;
    }

    return 0;
}