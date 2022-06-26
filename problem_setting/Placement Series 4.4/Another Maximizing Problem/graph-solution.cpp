#include <bits/stdc++.h>
using namespace std;
#define int long long
void hocusPocus()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector adj(n, vector<int>(0));
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        --u, --v;
        adj[u].push_back(v);
    }
    if (n == 1)
    {
        cout << max(0LL, v[0]) << endl;
        return;
    }
    struct data
    {
        int a;
        int b;
    };
    int res = LLONG_MIN;
    const auto ans = [&](auto &self, int u) -> data
    {
        if (adj[u].size() == 0)
            return {v[u], 0};

        if (adj[u].size() == 1)
        {
            auto [a, b] = self(self, adj[u][0]);
            int nhp = max(v[u], a + v[u]);
            int nhp2 = max({b + v[u], 0LL, a});
            res = max({res, nhp, nhp2});
            return {nhp, nhp2};
        }

        if (adj[u].size() == 2)
        {
            auto [p, q] = self(self, adj[u][0]);
            auto [r, s] = self(self, adj[u][1]);
            int a = max(v[u], v[u] + p);
            a = max(a, v[u] + r);
            int b = max(a, v[u] + p + r);
            // for used
            int x = max({v[u] + q, 0LL, p});
            int y = max({v[u] + s, 0LL, r});
            // 100, 010, 001
            int z = max({q + v[u], q + v[u] + r});
            z = max({0LL, p, r, p + r, z});
            z = max({s + v[u], s + v[u] + p, z});
            res = max({res, b, z});
            return {a, max(x, y)};
        }

        return {-1, -1};
    };
    ans(ans, 0);
    cout << res << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    hocusPocus();
}