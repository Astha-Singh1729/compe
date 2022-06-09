#include <bits/stdc++.h>
using namespace std;
#define int long long
void hocusPocus()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> check(n);

    const auto ans = [&](int u) -> pair<int, int>
    {
        int one = -1;
        int mx = -1;
        int two = -1;
        const auto dfs = [&](auto &self, int u, int p, int &node, int d) -> void
        {
            check[u] = true;

            if (d > mx)
                mx = d, node = u;
            for (int v : adj[u])
                if (v != p)
                    self(self, v, u, node, d + 1);
        };
        dfs(dfs, u, -1, one, 0);
        mx = -1;
        dfs(dfs, one, -1, two, 0);
        return {one + 1, two + 1};
    };
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
        if (!check[i])
            vp.push_back(ans(i));

    cout << vp.size() - 1 << endl;
    for (int i = 0; i < vp.size() - 1; i++)
        cout << vp[i].second << " " << vp[i + 1].first << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    hocusPocus();
}