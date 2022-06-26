#include <bits/stdc++.h>
using namespace std;
#define int long long
void hocusPocus()
{
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    const auto check = [&](int ans)
    {
        int sum = 0;
        for (auto i : v)
        {
            sum += (ans / i);
            if (sum >= t)
                break;
        }
        return sum >= t;
    };
    int l = -1, h = 1e18 + 2;
    while (h - l > 1)
    {
        int mid = (l + h) / 2;

        if (check(mid))
            h = mid;
        else
            l = mid;
    }
    cout << h << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    hocusPocus();
}