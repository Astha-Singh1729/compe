#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin >> n;
    struct data
    {
        int a;
        int b;
        int reward;
    };
    vector<data> v;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    sort(v.begin(), v.end(), [](const auto &x, const auto &y)
         { return x.b < y.b; });

    const auto check = [&](int i, int ind)
    {
        return v[i].b < v[ind].a;
    };

    const auto gib_index = [&](int ind)
    {
        int l = -1, h = ind;
        while (h - l > 1)
        {
            int mid = (l + h) / 2;
            if (check(mid, ind))
                l = mid;
            else
                h = mid;
        }
        return l;
    };
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        int ind = gib_index(i);
        dp[i] = v[i].reward + (ind == -1 ? 0 : dp[ind]);
        if (i)
            dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[n - 1] << endl;
}