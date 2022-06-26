#include <bits/stdc++.h>
using namespace std;
#define int long long
void hocusPocus()
{
    int n;
    cin >> n;
    struct data
    {
        int start;
        int reward;
    };
    struct hmm
    {
        int start;
        int end;
        int reward;
    };
    vector<hmm> nhp;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        b++;
        mp[a], mp[b];
        nhp.push_back({a, b, x});
    }
    int c = 0;
    for (auto &[a, b] : mp)
        b = c, ++c;
    vector<vector<data>> v(c);
    for (auto [a, b, x] : nhp)
        v[mp[b]].push_back({mp[a], x});

    vector<int> dp(c, 0);
    for (int i = 0; i < c; i++)
    {
        if (i > 0)
            dp[i] = dp[i - 1];
        for (auto [start, reward] : v[i])
            dp[i] = max(dp[i], dp[start] + reward);
    }
    cout << dp[c - 1] << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    hocusPocus();
}
/*
2 3
1 3

*/